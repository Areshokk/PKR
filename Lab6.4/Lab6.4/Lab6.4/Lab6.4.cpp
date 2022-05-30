#include <iostream>
#include <iomanip>

using namespace std;

typedef int Info;
struct Elem
{
	Elem* link;
	Info info;
};

void Insert(Elem*& L, Info value)
{
	Elem* tmp = new Elem;
	tmp->info = value;
	if (L != NULL)
	{
		Elem* T = L;
		while (T->link != L)
			T = T->link;
		T->link = tmp;
	}
	else
	{
		L = tmp;
	}
	tmp->link = L;
}

Info Remove(Elem*& L)
{
	Elem* T = L;
	while (T->link != L) T = T->link;

	Info value = L->info;
	if (T != L)
	{
		Elem* tmp = L->link;
		delete L;
		L = tmp;
		T->link = L;
	}
	else
	{
		delete L;
		L = NULL;
	}
	return value;
}

int Count(Elem* L) {
	if (L == NULL) return 0;
	Elem* first = L;
	int k = 1;
	while (L->link != first)
	{
		k++;
		L = L->link;
	}
	return k;
}

void Print(Elem* L) {
	if (L == NULL) return;
	Elem* first = L;
	cout << setw(4) << L->info;
	while (L->link != first)
	{
		L = L->link;
		cout << setw(4) << L->info;
	}
	cout << endl;
}

void del( Elem* L, Info x)
{
	if (L == NULL)
		return;
	Elem* first = L;
	
	while (L->link != first)
	{
		if (L->info == x)
			Remove(L);
		L = L->link;
	}

}

int main()
{
	Elem* L = NULL;
	for (int i = 0; i < 15; i++)
		Insert(L, i);
	cout << Count(L) << endl;
	Print(L);

	int N;
	cout << "Vvedit number: "; cin >> N;
	del(L, N);
	Print(L);
	return 0;
}