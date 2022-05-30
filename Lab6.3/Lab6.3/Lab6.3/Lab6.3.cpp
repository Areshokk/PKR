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

void Create(Elem*& first, Elem*& last)
{
    for (int i = 0; i <= 10; i++)
    {
        enqueue(first, last, i);
    }
}

void Delete(Elem*& first, Elem*& last)
{
    while (first != NULL)
        dequeue(first, last);
}

void Print(Elem*& first, Elem*& last)
{
    Elem* tmp = first;
    while (tmp != NULL)
    {
        cout << tmp->info << " ";
        tmp = tmp->next;
    }
    cout << endl;
}

int Count(Elem*& first, int q)
{
    Elem* tmp = first;
    int result = 0;
    while (tmp != NULL)
    {
        if (tmp->info == q)
            result++;
        tmp = tmp->next;
    }
    return result;
}

int main()
{
    Elem* first = NULL,
        * last = NULL;

    Create(first, last);
    Print(first, last);

    int q;
    cout << "Vvedit znach : ";
    cin >> q;
    cout << " Count : " << Count(first, q) << endl;

    Delete(first, last);

    //cout << " Count after del = " << Count(first, q) << endl;
    return 0;
}