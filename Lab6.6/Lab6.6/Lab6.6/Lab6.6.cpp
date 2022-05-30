#define QMAX 100
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <Windows.h>

using namespace std;

typedef int Info;

struct queue {
	int qu[QMAX];
	int rear,
		frnt;
};

void init(struct queue* q) {
	q->frnt = 1;
	q->rear = 0;
	return;
}

void insert(struct queue* q, int x) {
	if (q->rear < QMAX - 1) {
		q->rear++;
		q->qu[q->rear] = x;
	}
	else
		printf("error\n");
	return;
}

int isempty(struct queue* q) {
	if (q->rear < q->frnt)    return 1;
	else  return 0;
}

void print(struct queue* q) {
	int h;
	if (isempty(q) == 1) {
		printf("Черга пуста введіть елементи\n");
		return;
	}
	for (h = q->frnt; h <= q->rear; h++)
		printf("%d ", q->qu[h]);
	return;
}

int remove(struct queue* q) {
	int x;
	if (isempty(q) == 1) {
		printf("Черга пуста\n");
		return(0);
	}
	x = q->qu[q->frnt];
	q->frnt++;
	return x;
}

int main()
{
	SetConsoleCP(1251);       
	SetConsoleOutputCP(1251);

	struct queue* q;
	int a;

	q = (queue*)malloc(sizeof(queue));

	init(q);
	print(q);

	for (int i = 0; i < 8; i++) {
		printf("Елемент: ");
		scanf("%d", &a);
		insert(q, a);
	}

	if (isempty(q))
		cout << "Черга порожня" << endl;
	else
		cout << "Черга НЕ порожня" << endl;

	printf("\n");
	print(q);
	while (q->frnt <= q->rear) {
		a = remove(q);
		printf("\nЕлемент вийшов з черги %d\n", a);
		print(q);
	}

	getchar();
	return 0;
}