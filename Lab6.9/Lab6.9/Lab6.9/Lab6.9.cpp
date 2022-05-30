#include<iostream>
#include<stdlib.h>
#include<conio.h>
#include <Windows.h> 
using namespace std;
struct treeNode
{
	int data;
	treeNode* left;
	treeNode* right;
};
treeNode* FindMin(treeNode* node)
{
	if (node == NULL)
	{
		// íåò ýëåìåíòà â äåðåâå
		return NULL;
	}
	if (node->left) /* Go to the left sub tree to find the min element */
		return FindMin(node->left);
	else
		return node;
}
treeNode* FindMax(treeNode* node)
{
	if (node == NULL)
	{
		/* There is no element in the tree */
		return NULL;
	}
	if (node->right) /* Go to the left sub tree to find the min element */
		return(FindMax(node->right));
	else
		return node;
}
treeNode* Insert(treeNode* node, int data)
{
	if (node == NULL)
	{
		treeNode* temp;
		temp = new treeNode;
		temp = (treeNode*)malloc(sizeof(treeNode));
		temp->data = data;
		temp->left = temp->right = NULL;
		return temp;
	}
	if (data >= (node->data))
	{
		node->right = Insert(node->right, data);
	}
	else if (data <= (node->data))
	{
		node->left = Insert(node->left, data);
	}
	/* Else there is nothing to do as the data is already in the tree. */
	return node;
}

void PrintTree(treeNode* root, int level)
{
	if (root != NULL)
	{
		PrintTree(root->right, level + 1);
		for (int i = 1; i <= level; i++)
			cout << " ";
		cout << root->data << endl;
		PrintTree(root->left, level + 1);
	}
}

treeNode* Delet(treeNode* node, int data)
{
	treeNode* temp;
	if (node == NULL)
	{
		cout << "Element Not Found";
	}
	else if (data < node->data)
	{
		node->left = Delet(node->left, data);
	}
	else if (data > node->data)
	{
		node->right = Delet(node->right, data);
	}
	else
	{
		/* Now We can delete this node and replace with either minimum element
		in the right sub tree or maximum element in the left subtree */
		if (node->right && node->left)
		{
			/* Here we will replace with minimum element in the right sub tree */
			temp = FindMin(node->right);
			node->data = temp->data;
			/* As we replaced it with some other node, we have to delete that node */
			node->right = Delet(node->right, temp->data);
		}
		else
		{
			/* If there is only one or zero children then we can directly
			remove it from the tree and connect its parent to its child */
			temp = node;
			if (node->left == NULL)
				node = node->right;
			else if (node->right == NULL)
				node = node->left;
			free(temp); /* temp is longer required */
		}
	}
	return node;
}
treeNode* Find(treeNode* node, int data)
{
	if (node == NULL)
	{
		/* Element is not found */
		return NULL;
	}
	if (data > node->data)
	{
		/* Search in the right sub tree. */
		return Find(node->right, data);
	}
	else if (data < node->data)
	{
		/* Search in the left sub tree. */
		return Find(node->left, data);
	}
	else
	{
		/* Element Found */
		return node;
	}
}
void Inorder(treeNode* node)
{
	if (node == NULL)
	{
		return;
	}
	Inorder(node->left);
	cout << node->data << " ";
	Inorder(node->right);
}
void Preorder(treeNode* node)
{
	if (node == NULL)
	{
		return;
	}
	cout << node->data << " ";
	Preorder(node->left);
	Preorder(node->right);
}
void Postorder(treeNode* node)
{
	if (node == NULL)
	{
		return;
	}
	Postorder(node->left);
	Postorder(node->right);
	cout << node->data << " ";
}
void Sum(treeNode* node, int& sum)
{
	if (node != NULL)
	{
		sum += node->data;
		Sum(node->left, sum);
		Sum(node->right, sum);
	}
}
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int sum = 0;
	setlocale(LC_ALL, "russian");
	treeNode* root = NULL, * temp;
	int ch;
	//clrscr();
	while (1)
	{
		cout << "\n1.Добавити елемент\n2.Видалити елемент\n3.Ñèìåòðè÷íèé îáõ³ä\n4.Îáõ³ä â øèðèíó\n5.Îáõ³ä â ãëèáèíó\n6.FindMin\n7.FindMax\n8.Знайти елемент\n9.Сума всіх елементів\n10.Вихід\n";
		cout << "Введіть значення:";
		cin >> ch;
		switch (ch)
		{
		case 1:
			cout << "\nÂâåä³òü åëëåìåíò äëÿ âñòàâêè:";
			cin >> ch;
			root = Insert(root, ch);
			cout << "\nÅëëåìåíòè â BST:";
			Inorder(root);
			break;
		case 2:
			cout << "\nÂâåä³òò åëëåìåíò äëÿ âèäàëåííÿ:";
			cin >> ch;
			root = Delet(root, ch);
			cout << "\nÏ³ñëÿ âèäàëåííÿ , åëëåìåíò³â â BST :";
			Inorder(root);
			break;
		case 3:
			cout << "\nInorder Travesals is:";
			Inorder(root);
			break;
		case 4:
			cout << "\nPreorder Traversals is:";
			Preorder(root);
			break;
		case 5:
			cout << "\nPostorder Traversals is:";
			Postorder(root);
			break;
		case 6:
			temp = FindMin(root);
			cout << "\nÌ³í³ìàëüíèé åëëåìåíò :" << temp->data;
			break;
		case 7:
			temp = FindMax(root);
			cout << "\nÌàêñèìàëüíèé åëëåìåíò :" << temp->data;
			break;
		case 8:
			cout << "\nÂâåä³òü åëëåìåíò äëÿ ïîøóêó:";
			cin >> ch;
			temp = Find(root, ch);
			if (temp == NULL)
			{
				cout << "Åëëåìåíò íå çíàéäåíî ";
			}
			else
			{
				cout << "Åëëåìåíò " << temp->data << " Çíàéäåíî\n";
			}
			break;
		case 9:
			Sum(root, sum);
			cout << "\nСума всіх елементів :" << sum;
			break;
		case 10:
			exit(0);
			break;
		case 11:
			PrintTree(root, 1);
		default:
			cout << "\nÍå ïðàâèëüíèé ïóíêò ìåíþ , ñïðîáóéòå ââåñòè éîãî ùå ðàç :";
			break;
		}
		//Sum(root, sum);
		//system("pause");
	}
	return 0;
}
/*

#include <iostream>
#include <fstream>
#include <windows.h>
#include <conio.h>
#include <string>

using namespace std;

typedef int Data;

typedef struct tag_tree {
	Data data;
	int k = 1;
	struct tag_tree* left, * right;
} TREE;

void CreateTree(TREE*& root);
void BalanceHeight(TREE*& root);
void InsertNode(TREE* root);
void Print_Tree(TREE* Tree);
void DisplayTree(TREE* root, int level);
void DeleteNodeOfTree(TREE* Tree);
void DeleteBranchOfTree(TREE*& Tree);
void DestroyTree(TREE* Root);
int Height(TREE* Root);
int Leaves(TREE* Root);
void readFile(TREE*& root);
int Count(TREE* root);
void PrintTree(TREE* root, int level);

int main(int argc, TCHAR* argv[])
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	TREE* root = NULL;
	int i = 0;
	readFile(root);

	while (true) {
		cout << "Âèáåðiòü çíà÷åííÿ:" << endl << endl;
		cout << "1  - Ñòâîðåííÿ äåðåâà" << endl;
		cout << "2  - Âèâ³ä äåðåâà" << endl;
		cout << "3  - Ïîáóäîâà çáàëàíñîâàíîãî äåðåâà" << endl;
		cout << "4  - Âèëó÷åííÿ âóçëà äåðåâà" << endl;
		cout << "5  - Âèëó÷åííÿ ã³ëêè äåðåâà" << endl;
		cout << "6  - Âèâåäåííÿ ò³ëüêè ñòðóêòóðà äåðåâà" << endl;
		cout << "7  - Âñòàâêà âóçëà" << endl;
		cout << "8  - Ê³ëüê³ñòü åëåìåíò³â" << endl;
		cout << "0  - Çàâåðøèòè ðîáîòó" << endl;
		cout << "Ââåä³òü çíà÷åííÿ - ";
		cin >> i;
		switch (i) {
		case 1: CreateTree(root); break;
		case 2: PrintTree(root, 0); cout << endl; Print_Tree(root); break;
		case 3: BalanceHeight(root); break;
		case 4: DeleteNodeOfTree(root); break;
		case 5: DeleteBranchOfTree(root); break;
		case 6: DisplayTree(root, 0); break;
		case 7: InsertNode(root); break;
		case 8: cout << "Çíàéäåíî åëåìåíò³â:" << Count(root) << endl; break;
		case 0: DestroyTree(root);
			return 0;
		}
	}
	system("pause");
	return 0;
}

void Include(TREE*& R, Data value) {
	if (R == NULL) {
		R = new TREE;
		R->data = value;
		R->left = R->right = NULL;
	}
	else  if (value == R->data) R->k++; else {
		if (value < R->data)  Include(R->left, value);
		else if (value > R->data) Include(R->right, value);
	}
}

void CreateTree(TREE*& root) {
	int n;
	Data data;
	DestroyTree(root);
	root = NULL;
	cout << "Âêàæ³òü ê³ëüê³ñòü åëåìåíò³â - ";
	cin >> n;
	if (n < 1) return;
	for (int i = 1; i <= n; i++) {
		cout << "Ââåä³òü åëåìåíò -" << i << "  ";
		cin >> data;
		Include(root, data);
	}
}

void InsertNode(TREE* root) {
	Data data;
	cout << endl;
	cout << "Ââåä³òü åëåìåíò ";
	cin >> data;
	Include(root, data);
	cout << endl << endl;
	cout << "Ê³ëüê³ñòü ëèñòê³â â äåðåâ³: " << Leaves(root) << endl;
	cout << "Âèñîòà äåðåâà: " << Height(root) << endl << endl;
}

void Backpass(TREE* T) {
	if (T != NULL) {
		Backpass(T->left);
		cout << T->data << "   ";
		Backpass(T->right);
	}
}

void PrefixBackpass(TREE* T) {
	if (T != NULL) {
		cout << T->data << "   ";
		PrefixBackpass(T->left);
		PrefixBackpass(T->right);
	}
}

void  PostfixBackpass(TREE* T) {
	if (T != NULL) {
		PostfixBackpass(T->left); PostfixBackpass(T->right);
		cout << T->data << "   ";
	}
}

void BackpassCount(TREE* T, int& k) {
	if (T != NULL) {
		BackpassCount(T->left, k); k++;
		BackpassCount(T->right, k);
	}
}

void Print_Tree(TREE* Tree) {
	if (Tree == NULL) { cout << "Äåðåâà íå ³ñíóº!!!"; return; }
	cout << "²íô³êñíèé îáõ³ä  : ";
	Backpass(Tree);
	cout << endl;
	cout << "Ïðåô³êñíèé îáõ³ä : ";
	PrefixBackpass(Tree);
	cout << endl;
	cout << "Ïîñòô³êñíèé îáõ³ä: ";
	PostfixBackpass(Tree);
	cout << endl;
	cout << "Ê³ëüê³ñòü ëèñòê³â: " << Leaves(Tree) << endl;
	cout << "Âèñîòà äåðåâà    : " << Height(Tree) << endl << endl;
}

void DestroyTree(TREE* Root) {
	TREE* L, * R;
	if (Root == NULL) return; L = Root->left;
	R = Root->right;
	delete Root; DestroyTree(L); DestroyTree(R);
}

int Leaves(TREE* Root) {
	if (Root == NULL) return 0;
	else if ((Root->left == NULL) && (Root->right == NULL)) return 1;
	else return(Leaves(Root->left) + Leaves(Root->right));
}

int Max(int x, int y) {
	if (x > y) return x;
	else return y;
}

int Height(TREE* Root) {
	int hL, hR;
	if (Root == NULL) return 0;
	hL = Height(Root->left);
	hR = Height(Root->right); return (1 + Max(hL, hR));
}

void RightRotation(TREE*& root) {
	TREE* tmp1 = root->left; TREE* tmp2 = tmp1->right;
	tmp1->right = root; root->left = tmp2; root = tmp1;
}

void LeftRotation(TREE*& root) {
	TREE* tmp1 = root->right; TREE* tmp2 = tmp1->left;
	tmp1->left = root; root->right = tmp2; root = tmp1;
}

int Height_(TREE* root) {
	if (root == NULL) return 0;
	int hL = Height_(root->left);
	int hR = Height_(root->right);
	if (hL > hR) return hL + 1;
	else return hR + 1;
}

int BFactor(TREE* root) {
	return Height_(root->right) - Height_(root->left);
}

void BalanceHeight(TREE*& root) {
	if (root != NULL) {
		BalanceHeight(root->left);
		BalanceHeight(root->right);
		if (BFactor(root) == 2) {
			if (BFactor(root->right) < 0)
				RightRotation(root->right);
			LeftRotation(root);
		}
		if (BFactor(root) == -2) {
			if (BFactor(root->left) > 0)
				LeftRotation(root->left);
			RightRotation(root);
		}
	}
}

int NodeCount(TREE* T) {
	int k = 0;
	if (T != NULL) {
		NodeCount(T->left);
		if ((T->left != NULL) && (T->right != NULL)) k++;
		NodeCount(T->right);
	}
	return k;
}

int rightmost(TREE* root) {
	while (root->right != NULL)
		root = root->right;
	return root->data;
}

TREE* DeleteNode(TREE* root, Data val)
{
	if (NULL == root) return NULL;
	if (root->data == val) {
		if (NULL == root->left && NULL == root->right) {
			free(root); return NULL;
		}
		if (NULL == root->right && root->left != NULL) {
			TREE* temp = root->left; free(root); return temp;
		}
		if (NULL == root->left && root->right != NULL) {
			TREE* temp = root->right;
			free(root);
			return temp;
		}
		root->data = rightmost(root->left);
		root->left = DeleteNode(root->left, root->data); return root;
	}
	if (val < root->data) {
		root->left = DeleteNode(root->left, val); return root;
	}
	if (val > root->data) {
		root->right = DeleteNode(root->right, val); return root;
	}
	return root;
}

void DeleteNodeOfTree(TREE* Tree) {
	Data data;
	cout << endl << endl;
	cout << "Çàäàéòå ÷èñëî, âóçîë ç ÿêèì áóäåòå âèëó÷àòè: ";
	cin >> data;
	Tree = DeleteNode(Tree, data);
}

void RemoveBranch(TREE*& root, int X, TREE* V, BOOL B) {
	if (root != NULL)
		if (X < root->data) {
			V = root; B = true; RemoveBranch(root->left, X, V, B);
		}
		else if (X > root->data) {
			V = root; B = false; RemoveBranch(root->right, X, V, B);
		}
		else {
			DestroyTree(root);
			if (B) V->left = NULL;
			else V->right = NULL; return;
		}
	return;
}

void DeleteBranchOfTree(TREE*& Tree) {
	Data data;
	cout << endl << endl;
	cout << "Çàäàéòå ÷èñëî, ã³ëêó ç ÿêèì áóäåòå âèëó÷àòè: ";
	cin >> data;
	if (data == Tree->data) {
		DestroyTree(Tree); Tree = NULL; return;
	}
	else RemoveBranch(Tree, data, NULL, true);
}

void DisplayTree(TREE* root, int level)
{
	if (root != NULL)
	{
		DisplayTree(root->right, level + 1);
		for (int i = 1; i <= level; i++) cout << "  ";
		cout << root->data << endl;
		DisplayTree(root->left, level + 1);
	}
}

void readFile(TREE*& root) {
	ifstream text_file("test.txt");
	if (!text_file) {
		cout << "Ïîìèëêà ñòâîðåííÿ ôàéëó";
		return;
	}int M;
	while (text_file >> M) {
		Include(root, M);
	}
	text_file.close();
}

int Count(TREE* root)
{
	if (root == NULL)
		return 0;
	else
		return 1 + Count(root->left) + Count(root->right);
}

void PrintTree(TREE* p, int level)
{
	if (p != NULL)
	{
		PrintTree(p->right, level + 1);
		for (int i = 1; i <= level; i++)
			cout << "   ";
		cout << p->data << endl;
		PrintTree(p->left, level + 1);
	}
}*/