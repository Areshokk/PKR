#include <iostream>
#include <iomanip>

using namespace std;

typedef int Info;

struct Elem
{
    Elem* next,
        * prev;
    int info;
};

void enqueue(Elem*& first, Elem*& last, Info value)
{
    Elem* tmp = new Elem;
    tmp->info = value;
    tmp->next = NULL;
    if (last != NULL)
        last->next = tmp;
    tmp->prev = last;
    last = tmp;
    if (first == NULL)
        first = tmp;
}

Info dequeue(Elem*& first, Elem*& last)
{
    Elem* tmp = first->next;
    Info value = first->info;
    delete first;
    first = tmp;
    if (first == NULL)
        last = NULL;
    else
        first->prev = NULL;
    return value;
}

void Create(Elem*& first, Elem*& last, int i)
{
    if (i <= 10) {
        enqueue(first, last, i);
        Create(first, last, i + 1);
    }
}

void Delete(Elem*& first, Elem*& last)
{
    if (first != NULL) {
        dequeue(first, last);
        Delete(first, last);
    }
       
}

void Print(Elem*& first, Elem*& last, Elem* tmp)
{
    if (tmp != NULL) {
        cout << tmp->info << " ";
        return Print(first, last, tmp = tmp->next);
    }
    else
        cout << endl;
}

int count(Elem*& first, Elem*& last, Elem* tmp, int& result, int q)
{
    if (tmp != NULL)
    {
        if (tmp->info == q)
            result++;
        return count(first, last, tmp = tmp->next, result, q);
    }
}

int main()
{
    Elem* first = NULL,
        * last = NULL;

    Create(first, last, 0);
    Print(first, last, first);
    int q;
    cout << "Vvedit znach : ";
    cin >> q;
    int res = 0;
    count(first, last, first, res, q);
   
    cout << " Count : " << res << endl;

    Delete(first, last);

    return 0;
}
