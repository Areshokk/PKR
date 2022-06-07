#include <iostream>

using namespace std;

typedef int Info;
struct Node
{
	Node* left,
		* right;
	Info info;
	char ch;
};

Node* CreateTree(int nodeCount);
void PrintTree(Node* root, int level);
Info PostfixOrder(Node* root, Info& max, char& ch);
int Count(Node* root);

int main()
{
	char ch;
	int N, max = INT_MIN;
	cout << "Enter nodes count: "; cin >> N;
	Node* root = CreateTree(N);
	cout << endl;
	PrintTree(root, 0);
	cout << "Postfix search: ";
	PostfixOrder(root, max, ch);
	cout << endl << max << ch << endl<< endl;
	cout << "Count - " << Count(root);
	return 0;
}

Node* CreateTree(int nodeCount)
{
	if (nodeCount == 0)
		return NULL;
	else
	{
		Node* newNode = new Node;

		cout << " Enter node value: ";
		cin >> newNode->info;
		cout << " Enter node symbol: ";
		cin >> newNode->ch;

		int leftCount = nodeCount / 2;
		int rightCount = nodeCount - leftCount - 1;
		newNode->left = CreateTree(leftCount);
		newNode->right = CreateTree(rightCount);
		return newNode;
	}
}

void PrintTree(Node* root, int level)
{
	if (root != NULL)
	{
		PrintTree(root->right, level + 1);
		for (int i = 1; i <= level; i++)
			cout << "   ";
		cout << root->info;
		cout << root->ch << endl;
		PrintTree(root->left, level + 1);
	}
}

Info PostfixOrder(Node* root, Info& max, char& ch)
{
	if (root != NULL)
	{
		PostfixOrder(root->left, max, ch);
		if (root->info >= max) {
			max = root->info;
			ch = root->ch;
		}
		PostfixOrder(root->right, max, ch);
		cout << root->info << "";
		cout << root->ch << "   ";
	}
	return ch;
}
int Count(Node* root)
{
	if (root == NULL)
		return 0;
	else
		return 1 + Count(root->left) + Count(root->right);
}















































//#include <iostream>
//#include <fstream>
//#include <windows.h>
//#include <conio.h>
//#include <string>
//
//using namespace std;
//
////typedef int Data;
////
////typedef struct tag_tree {
////
////	Data data;
////	
////	int k = 1;
////	struct tag_tree* left, * right;
////} TREE;
//
//
//typedef int Info;
//
//struct Node
//{
//	Node* left,
//		* right;
//	int k = 1;
//	Info info;
//	char ch;
//};
//
//
//
////void CreateTree(TREE*& root);
//void BalanceHeight(Node*& root);
//void InsertNode(Node* root);
////void Print_Tree(TREE* Tree);
//void DisplayTree(Node* root, int level);
//void DeleteNodeOfTree(Node* Tree);
//void DeleteBranchOfTree(Node*& Tree);
//void DestroyTree(Node* Root);
//int Height(Node* Root);
//int Leaves(Node* Root);
//void readFile(Node*& root);
//int Count(Node* root);
////void PrintTree(TREE* root, int level);
////TREE* FindMin(TREE* node);
////TREE* FindMax(TREE* node);
//
//
//Node* CreateTree(int nodeCount);
//void PrintTree(Node* root, int level);
//Info PostfixOrder(Node* root, Info& max);
//Node* FindMax(Node* root);
//
//int main(int argc, TCHAR* argv[])
//{
//	SetConsoleCP(1251);
//	SetConsoleOutputCP(1251);
//
//	Node* root = NULL;
//	readFile(root);
//	int N, min = -9999999999;
//	//cout << "Enter nodes count: "; cin >> N;
//	//root = CreateTree(N);
//	cout << endl;
//	int i = 0;
//	
//
//	while (true) {
//		cout << endl << endl;
//		cout << "0  - Створити дерево" << endl;
//		cout << "1  - Вивести дерево" << endl;
//		cout << "2  - Postfix Order" << endl;
//		cout << "3  - Збалансувати" << endl;
//		cout << "4  - Delete Node Of Tree" << endl;
//		cout << "5  - Delete Branch Of Tree" << endl;
//		cout << "6  - Display Tree" << endl;
//		cout << "7  - Insert Node" << endl;
//		cout << "8  - Кількість" << endl;
//		cout << "9  - Destroy Tree" << endl;
//		cout << "Виберіть значення - ";
//		cin >> i;
//		switch (i) {
//
//		case 0: 
//			cout << "Enter nodes count: "; cin >> N;
//			root = CreateTree(N); cout << endl; break;
//		case 1: PrintTree(root, 0); cout << endl; break;
//		case 2: cout << PostfixOrder(root, min); break;
//		case 3: BalanceHeight(root); break;
//		case 4: DeleteNodeOfTree(root); break;
//		case 5: DeleteBranchOfTree(root); break;
//		case 6: DisplayTree(root, 0); break;
//		case 7: InsertNode(root); break;
//		case 8: cout << "Кількість елементів:" << Count(root) << endl; break;
//		case 9: DestroyTree(root);
//			return 0;
//		}
//	}
//
//	return 0;
//
//
//
//	/*TREE* root = NULL;
//	int i = 0;
//	readFile(root);
//
//	while (true) {
//		cout  << endl << endl;
//		cout << "1  - Створити дерево" << endl;
//		cout << "2  - Вивести дерево" << endl;
//		cout << "3  - Збалансувати" << endl;
//		cout << "4  - Delete Node Of Tree" << endl;
//		cout << "5  - Delete Branch Of Tree" << endl;
//		cout << "6  - Display Tree" << endl;
//		cout << "7  - Insert Node" << endl;
//		cout << "8  - Кількість" << endl;
//		cout << "9  - Destroy Tree" << endl;
//		cout << "10  - FindMax" << endl;
//		cout << "Виберіть значення - ";
//		cin >> i;
//		switch (i) {
//		case 1: CreateTree(root); break;
//		case 2: PrintTree(root, 0); cout << endl; Print_Tree(root); break;
//		case 3: BalanceHeight(root); break;
//		case 4: DeleteNodeOfTree(root); break;
//		case 5: DeleteBranchOfTree(root); break;
//		case 6: DisplayTree(root, 0); break;
//		case 7: InsertNode(root); break;
//		case 8: cout << "Кількість елементів:" << Count(root) << endl; break;
//		case 9: DestroyTree(root);
//		case 10: cout << FindMax(root); break;
//			return 0;
//		}
//	}
//	*/
//	system("pause");
//	return 0;
//}
//
//Node* CreateTree(int nodeCount)
//{
//	if (nodeCount == 0)
//		return NULL;
//	else
//	{
//		Node* newNode = new Node;
//
//		cout << " Enter node value: ";
//		cin >> newNode->info;
//		cout << " Enter node symbol: ";
//		cin >> newNode->ch;
//
//		int leftCount = nodeCount / 2;
//		int rightCount = nodeCount - leftCount - 1;
//		newNode->left = CreateTree(leftCount);
//		newNode->right = CreateTree(rightCount);
//		return newNode;
//	}
//}
//
//void PrintTree(Node* root, int level)
//{
//	if (root != NULL)
//	{
//		PrintTree(root->right, level + 1);
//		for (int i = 1; i <= level; i++)
//			cout << "  ";
//		cout << root->info;
//		cout << root->ch << endl;
//		PrintTree(root->left, level + 1);
//	}
//}
//
//Node* FindMax(Node* root)
//{
//	if (root->right != NULL)
//		return FindMax(root->right);
//	else
//		return root;
//}
//
//Info PostfixOrder(Node* root, Info& max)
//{
//	if (root != NULL)
//	{
//		PostfixOrder(root->left, max);
//		PostfixOrder(root->right, max);
//		if (root->info > max)
//			max = root->info;
//	}
//	return max;
//}
//
//
//void Include(Node*& R, Info value) {
//	if (R == NULL) {
//		R = new Node;
//		R->info = value;
//		R->left = R->right = NULL;
//	}
//	else  if (value == R->info) R->k++; else {
//		if (value < R->info)  Include(R->left, value);
//		else if (value > R->info) Include(R->right, value);
//	}
//}
//
//void CreateTree(Node*& root) {
//	int n;
//	Info data;
//	DestroyTree(root);
//	root = NULL;
//	cout << "Введіть кількість елементів - ";
//	cin >> n;
//	if (n < 1) return;
//	for (int i = 1; i <= n; i++) {
//		cout << "Елемент -" << i << "  ";
//		cin >> data;
//		Include(root, data);
//	}
//}
//
//void InsertNode(Node* root) {
//	Info data;
//	cout << endl;
//	cout << "Введіть елемент ";
//	cin >> data;
//	Include(root, data);
//	cout << endl << endl;
//	cout << "Leaves: " << Leaves(root) << endl;
//	cout << "Height: " << Height(root) << endl << endl;
//}
//
//void Backpass(Node* T) {
//	if (T != NULL) {
//		Backpass(T->left);
//		cout << T->info << "   ";
//		Backpass(T->right);
//	}
//}
//
//void PrefixBackpass(Node* T) {
//	if (T != NULL) {
//		cout << T->info << "   ";
//		PrefixBackpass(T->left);
//		PrefixBackpass(T->right);
//	}
//}
//
//void  PostfixBackpass(Node* T) {
//	if (T != NULL) {
//		PostfixBackpass(T->left); PostfixBackpass(T->right);
//		cout << T->info << "   ";
//	}
//}
//
//void BackpassCount(Node* T, int& k) {
//	if (T != NULL) {
//		BackpassCount(T->left, k); k++;
//		BackpassCount(T->right, k);
//	}
//}
//
//
//void DestroyTree(Node* Root) {
//	Node* L, * R;
//	if (Root == NULL) return; L = Root->left;
//	R = Root->right;
//	delete Root; DestroyTree(L); DestroyTree(R);
//}
//
//int Leaves(Node* Root) {
//	if (Root == NULL) return 0;
//	else if ((Root->left == NULL) && (Root->right == NULL)) return 1;
//	else return(Leaves(Root->left) + Leaves(Root->right));
//}
//
//int Max(int x, int y) {
//	if (x > y) return x;
//	else return y;
//}
//
//int Height(Node* Root) {
//	int hL, hR;
//	if (Root == NULL) return 0;
//	hL = Height(Root->left);
//	hR = Height(Root->right); return (1 + Max(hL, hR));
//}
//
//void RightRotation(Node*& root) {
//	Node* tmp1 = root->left; Node* tmp2 = tmp1->right;
//	tmp1->right = root; root->left = tmp2; root = tmp1;
//}
//
//void LeftRotation(Node*& root) {
//	Node* tmp1 = root->right; Node* tmp2 = tmp1->left;
//	tmp1->left = root; root->right = tmp2; root = tmp1;
//}
//
//int Height_(Node* root) {
//	if (root == NULL) return 0;
//	int hL = Height_(root->left);
//	int hR = Height_(root->right);
//	if (hL > hR) return hL + 1;
//	else return hR + 1;
//}
//
//int BFactor(Node* root) {
//	return Height_(root->right) - Height_(root->left);
//}
//
//void BalanceHeight(Node*& root) {
//	if (root != NULL) {
//		BalanceHeight(root->left);
//		BalanceHeight(root->right);
//		if (BFactor(root) == 2) {
//			if (BFactor(root->right) < 0)
//				RightRotation(root->right);
//			LeftRotation(root);
//		}
//		if (BFactor(root) == -2) {
//			if (BFactor(root->left) > 0)
//				LeftRotation(root->left);
//			RightRotation(root);
//		}
//	}
//}
//
//int NodeCount(Node* T) {
//	int k = 0;
//	if (T != NULL) {
//		NodeCount(T->left);
//		if ((T->left != NULL) && (T->right != NULL)) k++;
//		NodeCount(T->right);
//	}
//	return k;
//}
//
//int rightmost(Node* root) {
//	while (root->right != NULL)
//		root = root->right;
//	return root->info;
//}
//
//Node* DeleteNode(Node* root, Info val)
//{
//	if (NULL == root) return NULL;
//	if (root->info == val) {
//		if (NULL == root->left && NULL == root->right) {
//			free(root); return NULL;
//		}
//		if (NULL == root->right && root->left != NULL) {
//			Node* temp = root->left; free(root); return temp;
//		}
//		if (NULL == root->left && root->right != NULL) {
//			Node* temp = root->right;
//			free(root);
//			return temp;
//		}
//		root->info = rightmost(root->left);
//		root->left = DeleteNode(root->left, root->info); return root;
//	}
//	if (val < root->info) {
//		root->left = DeleteNode(root->left, val); return root;
//	}
//	if (val > root->info) {
//		root->right = DeleteNode(root->right, val); return root;
//	}
//	return root;
//}
//
//void DeleteNodeOfTree(Node* Tree) {
//	Info data;
//	cout << endl << endl;
//	cout << "Введіть елемент який хочете видалити: ";
//	cin >> data;
//	Tree = DeleteNode(Tree, data);
//}
//
//void RemoveBranch(Node*& root, int X, Node* V, BOOL B) {
//	if (root != NULL)
//		if (X < root->info) {
//			V = root; B = true; RemoveBranch(root->left, X, V, B);
//		}
//		else if (X > root->info) {
//			V = root; B = false; RemoveBranch(root->right, X, V, B);
//		}
//		else {
//			DestroyTree(root);
//			if (B) V->left = NULL;
//			else V->right = NULL; return;
//		}
//	return;
//}
//
//void DeleteBranchOfTree(Node*& Tree) {
//	Info data;
//	cout << endl << endl;
//	cout << "Введіть яку гілку хочете видалити: ";
//	cin >> data;
//	if (data == Tree->info) {
//		DestroyTree(Tree); Tree = NULL; return;
//	}
//	else RemoveBranch(Tree, data, NULL, true);
//}
//
//void DisplayTree(Node* root, int level)
//{
//	if (root != NULL)
//	{
//		DisplayTree(root->right, level + 1);
//		for (int i = 1; i <= level; i++) cout << "  ";
//		cout << root->info << endl;
//		DisplayTree(root->left, level + 1);
//	}
//}
//
//void readFile(Node*& root) {
//	ifstream text_file("t.txt");
//	if (!text_file) {
//		cout << "Файл пустий"<<endl;
//		return;
//	}int M;
//	while (text_file >> M) {
//		Include(root, M);
//	}
//	text_file.close();
//}
//
//int Count(Node* root)
//{
//	if (root == NULL)
//		return 0;
//	else
//		return 1 + Count(root->left) + Count(root->right);
//}

//void PrintTree(Node* p, int level)
//{
//	if (p != NULL)
//	{
//		PrintTree(p->right, level + 1);
//		for (int i = 1; i <= level; i++)
//			cout << "   ";
//		cout << p->info << endl;
//		PrintTree(p->left, level + 1);
//	}
//}
