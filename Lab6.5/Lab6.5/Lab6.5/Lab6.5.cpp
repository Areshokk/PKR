#include <iostream>
#include <stack>
#include <fstream>
#include <string>
using namespace std;

typedef int Info;
struct Elem
{
	Elem* link;
	Info info;
};


void push(Elem*& top, Info value)
{
	Elem* tmp = new Elem; // 1
	tmp->info = value; // 2
	tmp->link = top; // 3
	top = tmp; // 4
}

Info pop(Elem*& top)
{
	Elem* tmp = top->link; // 1
	Info value = top->info; // 2
	delete top; // 3
	top = tmp; // 4
	return value; // 5
}

void readTXT(Elem*& top)
{
	ifstream f("input.txt");
	int element;
	if (!f.eof()) {
		f >> element;
		push(top, element);
	}
	while (!f.eof()) {
		f >> element;
		push(top, element);
	}
}

void print(Elem* top)
{
	while (top != NULL)
	{
		cout << top->info << " ";
		top = top->link;
	}
	cout << endl;
}

int count(Elem* top)
{
	int value = 0;
	while (top != NULL)
	{
		value++;
		top = top->link;
	}
	return value;
}

void printprop(Elem* top, int x)
{
	while (top != NULL)
	{
		if(top->info % x != 0)
			cout << top->info << " ";
		top = top->link;
	}
	cout << endl;
}

int main()
{
	Elem* top = NULL;
		
	readTXT(top);
	print(top);
	int x;
	cout <<"Count : " << count(top) << endl;
	cout << " Vvedit chuslo : "; cin >> x;
	printprop(top, x);
	int value = count(top);

	return 0;
}