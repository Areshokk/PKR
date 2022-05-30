//R
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

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);


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
		cout << " L2: "; cin >> info;
		Enqueue(L1, L2, info);
	}
	int tmp{ 1 };

	Process(L1, L2);

	if (tmp == 1)
		cout << "всі елементи списку L1 входять у список L2";
	else
		cout << "всі елементи списку L1 НЕ входять у список L2";

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
	if (L1 != NULL)
	{
		if (L1->info == L2->info)
		{
			tmp = 1;
			L1 = L1->link;
		}
		return Process(L1->link, L2);
	}
}