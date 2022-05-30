#include <iostream>
#include <iomanip>
#include <windows.h>
#include <time.h>

using namespace std;

typedef int Info;
struct Elem
{
	Elem* link;
	Info info;
};

void Create(Elem*& first, int N, int Low, int High, int k);
void Insert(Elem*& L, Info value);
void Remove(Elem*& L);
void del(Elem* L, Elem* first, int x);
void Print(Elem* L, Elem* first);

void Create(Elem*& first, int N, int Low, int High, int k)
{
	if (k < N)
	{
		int value = Low + rand() % (High - Low + 1);
		Insert(first, value);
		Create(first, N, Low, High, k + 1);
	}
}

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

void Remove(Elem*& L)
{
	Elem* T = L->link;
	while (T->link != L->link)
		T = T->link;

	Info value = L->info;

	if (T != L->link)
	{
		Elem* tmp = L->link->link;
		delete L->link;
		L->link = tmp;
		T->link = L->link;
	}
	else
	{
		delete L->link;
		L->link = NULL;
	}
}

void Print(Elem* L, Elem* first)
{
	if (L == NULL)
		return;
	else
	{
		if (L->link != first)
		{
			cout << setw(4) << L->link->info;
			Print(L->link, first);
		}
	}
}

void del(Elem* L, Elem* first, int x)
{
	if (L == NULL)
		return;
	else
	{
		if (L->link != first)
		{
			if (L->info == x)
			{
				Remove(L);
				
			}
				L->link, first, x;
		}
	}
}

int main()
{
	Elem* L = NULL;
	for (int i = 0; i < 15; i++)
		Insert(L, i);
	Elem* first = L;	
	Print(L,first);

	int N;
	cout << "Vvedit number: "; cin >> N;
	del(L,first, N);
	Print(L,first);
	return 0;
}