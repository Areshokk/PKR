#include <iostream>
#include <fstream>
#include <iomanip>
#include <Windows.h>

using namespace std;

struct Zodiac {
	char fullName[64];
	char zod_sign[64];
	int birthDate[3];
};


void Create(const char* fName);
void Print(const char* fName);
void fWrite(fstream& f, const int i, Zodiac x);
Zodiac fRead(fstream& f, const int i);
void fChange(fstream& f, const int i, const int j);
void Sort(const char* fName);
int Search(const char* fName, char sign[]);



int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	char f[64];
	char g[6] = "g.dat";
	char prizv[64];

	int menuItem;
	do {
		cout << "Оберіть дію: " << endl;
		cout << "[1]  введення даних з клавіатури." << endl;
		cout << "[2]  вивід даних на екран." << endl;
		cout << "[3]  сортування." << endl;
		cout << "[4]  пошук за знаком зодіаку." << endl;
		cout << "[5]  ввести назву файла." << endl;
		cout << "[0]  вихід та завершення роботи програми" << endl << endl;
		cout << "Введіть значення: "; cin >> menuItem;
		switch (menuItem) {
		case 1:
			Create(f);
			break;
		case 2:
			Print(f);
			break;
		case 3:
			Sort(f);
			break;
		case 4:
			char sign[64];
			cout << "Ввведіть знак зодіаку, який бажаєте знайти: ";
			cin >> sign;
			Search(f, sign);
			break;
		case 5:
			cout << "Введіть назву файла: "; cin >> f;
			break;
		case 0:
			break;
		default:
			cout << "Ви ввели помилковезначення! Слід ввести число - номер вибраного пункту меню" << endl;
		}
	} while (menuItem != 0);



	system("pause");
	cin.get();
	return 0;
}

void Create(const char* fName)
{
	ofstream f(fName, ios::binary);
	Zodiac zod;
	char ch;
	int i = 1;
	do {
		cout << " №: " << i++ << ": " << endl;
		cin.ignore();
		cout << "Прізвище та ім'я: ";
		cin >> zod.fullName;
		cout << "Знак зодіаку: ";
		cin >> zod.zod_sign;
		cout << "День народження: "; cin >> zod.birthDate[0];
		cout << "Місця народження: "; cin >> zod.birthDate[1];
		cout << "Рік народження: "; cin >> zod.birthDate[2];
		cout << endl;

		cout << endl;
		if (!f.write((char*)&zod, sizeof(Zodiac))) {
			cerr << "Error writing file." << endl;
		}
		cout << "Continue?(Y/N)"; cin >> ch;
	} while (ch == 'y' || ch == 'Y');
}



void Print(const char* fName)
{
	cout << "======================================================================================" << endl;
	cout << "|  No  |    Прізвище та ім'я    |  Номер телефону  |      Повна дата народження      |" << endl;
	cout << "--------------------------------------------------------------------------------------" << endl;

	ifstream f(fName, ios::binary);
	Zodiac zod;
	int i = 1;
	while (f.read((char*)&zod, sizeof(Zodiac))) {
		cout << "| " << setw(3) << right << i++ << "  ";
		cout << "| " << setw(23) << left << zod.fullName
			<< "|  " << setw(16) << right << zod.zod_sign
			<< "|  " << setfill('0') << setw(2) << zod.birthDate[0] << "." << setfill('0') << setw(2) << zod.birthDate[1] << "." << zod.birthDate[2] << setfill(' ') << setw(22) << " |" << endl;

	}
	cout << "======================================================================================" << endl;
	cout << endl;
}



void fWrite(fstream& f, const int i, Zodiac x) {
	f.seekp(i * (long)sizeof(Zodiac));
	f.write((char*)&x, sizeof(Zodiac));
}

Zodiac fRead(fstream& f, const int i) {
	Zodiac x;
	f.seekg(i * (long)sizeof(Zodiac));
	f.read((char*)&x, sizeof(Zodiac));
	return x;
}

void fChange(fstream& f, const int i, const int j) {
	Zodiac x = fRead(f, i);
	Zodiac y = fRead(f, j);
	fWrite(f, i, y);
	fWrite(f, j, x);
}

void Sort(const char* fName) {
	fstream f(fName, ios::binary | ios::in | ios::out);

	f.seekg(0, ios::end);
	int size = f.tellg() / sizeof(Zodiac);
	f.seekg(0, ios::beg);

	for (int i0 = 1; i0 < size; i0++) {
		for (int i1 = 0; i1 < size - i0; i1++) {
			Zodiac a = fRead(f, i1);
			Zodiac b = fRead(f, i1 + 1);
			if (strcmp(a.fullName, b.fullName) == 1) {
				fChange(f, i1, i1 + 1);
			}
		}
	}


	f.seekp(0, ios::end);
}

int Search(const char* fName, char sign[]) {
	ifstream f(fName, ios::binary);
	Zodiac zod;
	int n = 1;

	cout << endl << "======================================================================================" << endl;
	cout << "|  No  |    Прізвище та ім'я    |  Знак зодіаку  |      Повна дата народження      |" << endl;
	cout << "--------------------------------------------------------------------------------------" << endl;

	while (f.read((char*)&zod, sizeof(Zodiac))) {
		if (strcmp(zod.zod_sign, sign) == 0) {
			cout << endl;
			cout << "| " << setw(3) << right << n++ << "  ";
			cout << "| " << setw(23) << left << zod.fullName
				<< "|  " << setw(16) << right << zod.zod_sign
				<< "|  " << setfill('0') << setw(2) << zod.birthDate[0] << "." << setfill('0') << setw(2) << zod.birthDate[1] << "." << zod.birthDate[2] << setfill(' ') << setw(22) << " |" << endl;

		}
	}

	cout << "======================================================================================" << endl;
	cout << endl;

	if (n == 1) {
		cout << endl;
		cout << "Cпівпадінь за введеними даними не знайдено." << endl << endl;
		return -1;
	}
	else {
		return 1;
	}
}