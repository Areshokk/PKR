#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <Windows.h>
#include <math.h>

using namespace std;

void Create(const char* fName);
void Print(const char* fName);
int LineSearch(char* fname);
double LineSearch2(char* fname);

enum Specialty { KN, INF, ME, PI, TD };

string specialtyStr[] = { "Комп. науки", "Інфо.", "Мат. та ек.", " Фіз. та інф.", "Труд. навч." };

struct Student {
	char prizv[64];
	unsigned kurs;
	Specialty specialty;
	unsigned gradePhys;
	unsigned gradeMath;
	union {
		unsigned gradeProg;
		unsigned gradeMetod;
		unsigned gradePed;
	};
};


int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	char f[6] = "f.dat";

	int menuItem;

	do
	{
		cout << endl << endl;
		cout << "Виберіть дію:" << endl << endl;
		cout << " [1] - ввести дані у файл" << endl;
		cout << " [2] - вивести дані на екран" << endl;
		cout << " [3] - середній бал 4.5 більше" << endl;
		cout << " [4] - середній бал предмету " << endl;
		cout << " [0] - вихід та завершення роботи програми" << endl << endl;
		cout << "Введіть значення: "; cin >> menuItem;
		cout << endl << endl << endl;
		switch (menuItem)
		{
		case 1:
			cin.get(); // очищуємо буфер клавіатури – щоб не було символу
			cin.sync(); // "кінець рядка", який залишився після вводу числа
			Create(f);
			break;
		case 2:

			Print(f);
			break;
		case 3:
			cout << "середній бал 4.5 більше: " << LineSearch(f) << endl;
			
			break;
		case 4:
			cout << LineSearch2(f) << endl;
			break;
		case 0:
			break;
		default:
			cout << "Ви ввели помилкове значення! "
				"Слід ввести число  - номер вибраного пункту меню" << endl;
		}
	} while (menuItem != 0);

	system("pause");
	cin.get();
	return 0;
}



void Create(const char* fName)
{
	ofstream f(fName, ios::binary);
	Student student;
	char ch;
	int specialty;
	do {

		cout << "Прізвище: ";
		cin >> student.prizv;
		cout << "Курс: "; cin >> student.kurs;
		cout << "Спеціальність (0 - Комп'ютерні науки, 1 - Інформатика, 2 - Математика та екноміка, 3 - Фізика та інформатика, 4 - Трудове навчання): ";
		cin >> specialty;
		student.specialty = (Specialty)specialty;
		cout << "Оцінка з фізики: "; cin >> student.gradePhys;
		cout << "Оцінка з математики: "; cin >> student.gradeMath;
		switch (student.specialty) {
		case KN:
			cout << "Оцінка з програмування: "; cin >> student.gradeProg;
			break;
		case INF:
			cout << "Оцінка з чисельних методоів: "; cin >> student.gradeMetod;
			break;
		default:
			cout << "Оцінка педагогіки: "; cin >> student.gradePed;
			break;
		}

		cout << endl;
		if (!f.write((char*)&student, sizeof(Student))) {
			cerr << "Error writing file." << endl;
		}
		cout << "Continue?(Y/N)"; cin >> ch;
	} while (ch == 'y' || ch == 'Y');
}


void Print(const char* fName)
{
	cout << endl << "\nfile \"" << fName << "\":\n";
	cout << "==================================================================================================="
		<< endl;
	cout << "| № |  Прізвище  | Курс |   Спеціальність   | Фізика | Матем. | Програм. | Чис. мет. | Педагогіка |"
		<< endl;
	cout << "==================================================================================================="
		<< endl;

	ifstream f(fName, ios::binary);
	Student student;
	int i = 1;
	while (f.read((char*)&student, sizeof(Student))) {
		cout << "| " << right << i++ << " ";
		cout << "| " << setw(11) << left << student.prizv
			<< "|" << setw(4) << right << student.kurs << "  "
			<< "| " << setw(18) << left << specialtyStr[student.specialty]
			<< "| " << setw(6) << right << student.gradePhys << " "
			<< "| " << setw(6) << right << student.gradeMath << " ";
		switch (student.specialty) {
		case KN:
			cout << "| " << setw(8) << fixed << right << student.gradeProg
				<< " |" << setw(12) << "|" << setw(12) << "|" << endl;
			break;
		case INF:
			cout << "|" << setw(11)
				<< "| " << right << fixed << setw(9) << student.gradeMetod << " |" << setw(12) << "|" << endl;
			break;
		default:
			cout << "|" << setw(11)
				<< "|" << setw(12) << "| " << setw(10) << student.gradePed << " |" << endl;
			break;
		}

	}
	cout << "===================================================================================================" << endl;
	cout << endl;
}


int LineSearch(char* fname)
{
	ifstream f(fname, ios::binary);
	if (f.fail())
	{
		cout << "Error" << fname << "!" << endl;
		return 0;
	}
	Student student;

	int k = 0, n = 0;
	while (f.read((char*)&student, sizeof(Student)))
	{
		if (student.specialty == KN)
		{
			n++;
			if ((student.gradePhys + student.gradeMath + student.gradeProg) / 3.0 > 4.5)
				k++;
		}
		if (student.specialty == INF)
		{
			n++;
			if ((student.gradePhys + student.gradeMath + student.gradeMetod) / 3.0 > 4.5)
				k++;

		}
		if (student.specialty == ME || student.specialty == PI || student.specialty == TD)
		{
			n++;
			if ((student.gradePhys + student.gradeMath + student.gradePed) / 3.0 > 4.5)
				k++;
		}

	}
	return k;
}
double LineSearch2(char* fname)
{
	ifstream f(fname, ios::binary);
	if (f.fail())
	{
		cout << "Error" << fname << "!" << endl;
		return 0;
	}
	Student student;

	double N = sizeof(Student), r = 0, q = 0, t = 0, a = 0, b = 0, c = 0, d = 0, j = 0;
	while (f.read((char*)&student, sizeof(Student)))
	{
		if (student.specialty == KN)
		{
			r++;
			a += student.gradePhys;
			b += student.gradeMath;
			c += student.gradeProg;

		}
		if (student.specialty == INF)
		{
			q++;
			a += student.gradePhys;
			b += student.gradeMath;
			d += student.gradeMetod;

		}
		if (student.specialty == ME || student.specialty == PI || student.specialty == TD)
		{
			t++;
			a += student.gradePhys;
			b += student.gradeMath;
			j += student.gradePed;
		}
	}
	double aq = a / N;
	double bq = b / N;
	double cq = c / r;
	double dq = d / q;
	double jq = j / t;



	double maximum = max(aq, max(bq, max(cq, dq)));
	maximum = max(maximum, jq);

	if (maximum == aq)
	{
		cout << " Фізика" << endl;
	}
	else if (maximum == bq)
	{
		cout << " Матем" << endl;
	}
	else if (maximum == cq)
	{
		cout << "Програм." << endl;
	}
	else if (maximum == dq)
	{
		cout << "Чис. мет." << endl;
	}
	else
	{
		cout << "Педагогіка" << endl;
	}
	return maximum;

}