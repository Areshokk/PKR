#include <iostream>

using namespace std;

struct Elem
{
	Elem* link1,
		* link2;
	int info;
};
int main()
{
	Elem* p;
	p = new Elem; // 1
	p->info = 1; // 2
	p->link2 = new Elem; // 3
	p->link2->info = 2; // 4
	p->link2->link2 = NULL; // 5
	p->link2->link1 = new Elem; // 6
	p->link2->link1->info = 3; // 7
	p->link2->link1->link2 = NULL; // 8
	p->link2->link1->link1 = p->link2;; // 9
	p->link1 = new Elem; // 3
	p->link1->info = 4; // 11
	p->link1->link1 = p->link2; // 12
	p->link1->link2 = p->link2->link1; // 13

	delete p->link1; // 14
	delete p->link2->link1; // 15
	delete p->link2; // 16
	delete p; // 17
	return 0;
}