// Iter
#include <iostream>
#include <Windows.h>

using namespace std;

typedef int Info;

struct Elem
{
	Elem* link;
	Info info;
};



void Process(Elem* L1, Elem* L2);
void Enqueue(Elem*& first, Elem*& last, Info value);
bool contains(Elem* L1, Elem* L2);

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int tmp = 0;

	Elem* L1 = NULL,
		* L2 = NULL;

	Info info, N, B;

	do
	{
		cout << "Введіть кількість елементів L1: "; cin >> N;
	} while (N < 0);

	for (int i = 0; i < N; i++)
	{
		cout << " L1: "; cin >> info;
		Enqueue(L1, L2, info);
	}
	do
	{
		cout << "Введіть кількість елементів L2: "; cin >> B;
	} while (B < 0);

	for (int i = 0; i < B; i++)
	{
		cout << "  L2: "; cin >> info;
		Enqueue(L1, L2, info);
	}



	if (contains(L1, L2) == true)
		cout << "всі елементи списку L1 входять у список L2";
	else
		cout << "всі елементи списку L1 НЕ входять у список L2";


	//Process(L1, L2);
	/*if (tmp == 1)
		cout << "всі елементи списку L1 входять у список L2";
	else
		cout << "всі елементи списку L1 НЕ входять у список L2";*/

	return 0;
}


void Enqueue(Elem*& first, Elem*& last, Info value)
{
	Elem* tmp = new Elem;
	tmp->info = value;
	tmp->link = NULL;
	if (last != NULL)
		last->link = tmp;
	last = tmp;
	if (first == NULL)
		first = tmp;
}

void Process(Elem* L1, Elem* L2)
{
	int tmp = 0;
	while (L1 != NULL)
	{
		if (L1->info == L2->info)
		{
			tmp = 1;
			L1 = L1->link;
		}
		L1 = L1->link;
	}
}

bool contains(Elem* L1, Elem* L2)
{
	
	if (L1 == NULL || L2 == NULL)
		return false;

	Elem* currentl = L1, * currentw = L2;


	while (currentw && currentl)
	{
		if (currentl->info != currentw->info)
			break;

		currentl = currentl->link;
		currentw = currentw->link;
	}

	return !L1 ? false : currentw ? contains(L1->link, L2) : true;
}