#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <string>
using namespace std;
struct elem
{
	string name;
	struct elem* next;
	struct elem* previous;
};
elem* head = NULL;
elem* last = NULL;
elem* current = NULL;
elem* temp = NULL;
elem* newList = NULL;

void add_name(string s)
{
	if (head != NULL)
	{
		newList = new elem;
		newList->name = s;
		newList->next = NULL;
		newList->previous = current;
		current->next = newList;
		last = newList;
		current = newList;
	}
	else
	{
		newList = new elem;
		newList->name = s;
		head = newList;
		newList->next = NULL;
		newList->previous = NULL;
		current = newList;
		last = head;
	}
}

void delete_unit(string name)
{
	newList = head;
	while (newList) {
		if (newList->name == name)
		{
			if (newList == head) {
				head = head->next;
				if (head)
					head->previous = NULL;
				else
					last = NULL;
				if (current == newList)
					current = head;
				delete newList;
				break;
			}
			if (newList == last) {
				last = last->previous;
				if (last)
					last->next = NULL;
				if (current == newList)
					current = last;
				delete newList;
				break;
			}
			newList->previous->next = newList->next;
			newList->next->previous = newList->previous;
			current = newList->previous;
			delete newList;
			break;
		}
		newList = newList->next;
	}
}

void show_list(void)
{
	struct elem* info;
	info = head;
	while (info)
	{
		cout << info->name << " ";
		info = info->next;
	}
	cout << "\n";
}

int main(void)
{
	string enter_name;
	int key = -1;
	while (key)
	{
		cout << "1. Enter element of list\n";
		cout << "2. Delete unit\n";
		cout << "3. Show list\n";
		cout << "0. Exit\n";
		cin >> key;
		switch (key)
		{
		case 1:
		{
			cout << "Enter element\n";
			cin >> enter_name;
			add_name(enter_name);
			break;
		}
		case 2:
		{
			cout << "Enter unit for deleting\n";
			cin >> enter_name;
			delete_unit(enter_name);
			_getch();
			break;
		}
		case 3:
		{
			cout << "List from left to right\n";
			show_list();
			break;
		}
		case 0:
		{
			cout << "Bye\n";
			_getch();
			break;
		}
		default:
		{
			cout << "Error\n";
			_getch();
			break;
		}
		if (key == 0) break;
		}
	}
	return 0;
}