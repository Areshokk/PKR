#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <conio.h>
#include <Windows.h> 

#define MAX_LEN 1000

typedef struct link
{
	struct link* next;
	double value;
} link_t;

// ñòâîðåííÿ ïóñòîãî ºëåìåíòà ñïèñêà
static link_t* create_link()
{
	link_t* l = (link_t*)malloc(sizeof(link_t));
	l->next = NULL;
	l->value = 0;

	return l;
}

// âèäàëåííÿ ñïèñêà
static void delete_list(link_t** l)
{
	if (l && *l)
	{
		delete_list(&((*l)->next));
		free(*l);
		*l = NULL;
	}
}

// ñòâîðåííÿ ñïèñêà ç ôàéëà
static void create_list_from_file(link_t** l, FILE* file)
{
	double c;
	fscanf(file, "%lf", &c);

	if (!feof(file))
	{
		(*l) = create_link();
		(*l)->value = c;

		create_list_from_file(&((*l)->next), file);
	}
}

// ïå÷àòü ñïèñêà
static void print_list(link_t* l)
{
	link_t* current = l;

	while (current)
	{
		printf("%lf ", current->value);
		current = current->next;
	}

	printf("\n");
}

// ïðîâ³ðêà íà âì³ñò
static bool contains(link_t* l, link_t* w)
{
	// ïóñò³ ñïèñêè
	if (l == NULL || w == NULL)
		return false;

	link_t* currentl = l, * currentw = w;

	// çð³âíþºìî 2 ñëîâà
	while (currentw && currentl)
	{
		if (currentl->value != currentw->value)
			break;

		currentl = currentl->next;
		currentw = currentw->next;
	}

	return !l ? false : currentw ? contains(l->next, w) : true;
}

static bool readList(link_t** l)
{
	char fileName[255];


	printf("Ââåäèòå èìÿ ôàéëà: \n");
	scanf("%s", fileName);

	FILE* file = fopen(fileName, "r");
	if (!file)
	{
		printf("Íå óäàëîñü îòêðûòü ôàéë %s\n", fileName);
		return false;
	}

	// ñòâîðþºìî ñïèñîê ç ôàéëó
	create_list_from_file(l, file);
	fclose(file);

	return true;
}

int main()
{
	SetConsoleCP(1251); // âñòàíîâëåííÿ ñòîð³íêè win-cp1251 â ïîò³ê ââîäó
	SetConsoleOutputCP(1251); // âñòàíîâëåííÿ ñòîð³íêè win-cp1251 â ïîò³ê âèâîäó
	// ïóñò³ ñïèñêè l1, l2
	link_t* l1 = NULL, * l2 = NULL;

	if (!readList(&l1))
		return EXIT_FAILURE;
	if (!readList(&l2))
		return EXIT_FAILURE;


	printf("L1: \n");
	print_list(l1);

	printf("L2: \n");
	print_list(l2);

	if (contains(l1, l2))
		printf("Ïåðâûé ñïèñîê ñîäåðæèò âòîðîé\n");
	else if (contains(l2, l1))
		printf("Âòîðîé ñïèñîê ñîäåðæèò ïåðâûé\n");
	else
		printf("Íè îäèí èç ñïèñêîâ íå ñîäåðèò äðóã äðóãà\n");

	delete_list(&l1);
	delete_list(&l2);

	_getch();
	return EXIT_SUCCESS;

}