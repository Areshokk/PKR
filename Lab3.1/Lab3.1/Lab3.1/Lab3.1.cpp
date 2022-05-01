#include <iostream>
#include <iomanip>
#include <string>
#include <Windows.h> 

using namespace std;

enum Specilnist { KN, INF, MathEcon, PhysInf, WORK };

string predmetStr[] = { " Комп. науки  ", " Інформатика  ", "Мат. та економ", " Фіз. та інф. ", " Труд. навч.  " };


struct Student
{
	string prizvandname;
	unsigned kurs;
	Specilnist spec;
	int Physical;
	int Math;
	int Informatik;
};



void Create(Student* s, const int N);
void Print(Student* s, const int N);
int Percent(Student* s, const int N);
double Highest(Student* s, const int N);

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int N;
	cout << "Введіть кількість студентів: "; cin >> N;

	Student* s = new Student[N];

	string prizvandname;
	unsigned kurs;
	Specilnist spec;
	int Physical;
	int Math;
	int Informatik;

	Create(s, N);
	Print(s, N);
	cout <<"Найбільший середній бал - " << Highest(s, N) <<endl;
	cout <<"Процент студентів з оцінками 4 або 5 - " << Percent(s, N);
	
	return 0;
}


void Create(Student* s, const int N)
{
	int spec;
	for (int i = 0; i < N; i++)
	{
		cout << "Студент № " << i + 1 << ":" << endl;
		cin.get(); // очищуємо буфер клавіатури – бо залишаються символи
		cin.sync(); // "кінець рядка", які не дають ввести наступний літерний рядок
		cout << " прізвище: "; getline(cin, s[i].prizvandname);
		cout << " курс: "; cin >> s[i].kurs;
		cout << "  Виберіть спеціальність (0 - Комп. науки , 1 - Інформатика , 2 - Мат. та економ , 3 - Фіз. та інф. , 4 - Труд. навч. ): "; cin >> spec;
		s[i].spec = (Specilnist)spec;
		cout << " Оцінка з Фізики: "; cin >> s[i].Physical;
		cout << " Оцінка з Математики: "; cin >> s[i].Math;
		cout << " Оцінка з Інфортматики: "; cin >> s[i].Informatik;


		cout << endl;
	}
}
void Print(Student* s, const int N)
{
	cout << "======================================================================================="
		<< endl;
	cout << "| № |      Прізвище       | Курс | Спеціальність | Фізика | Математика | Інфортматика | "
		<< endl;
	cout << "---------------------------------------------------------------------------------------"
		<< endl;
	for (int i = 0; i < N; i++) {
		cout << "| " << setw(1) << right << i + 1 << " ";
		cout << "| " << setw(20) << left << s[i].prizvandname << "| " << setw(4) << right << s[i].kurs << " ";
		cout << "| " << setw(8) << right << predmetStr[s[i].spec] << " |";
		cout << "| " << setw(6) << setprecision(2) << fixed << right << s[i].Physical << right << " |";
		cout << " " << setw(10) << right << s[i].Math << " |";
		cout << " " << setw(12) << right << s[i].Informatik << " |" << endl;
		
	}
	cout << "=======================================================================================" << endl;
	cout << endl;
}

double Highest(Student* s, const int N)
{
	double stud = 0, max = 0;
	int index = 0;
	for (int i = 0; i < N; i++) {
		stud = s[i].Physical + s[i].Math + s[i].Informatik;
		if (stud > max) {
			max = stud;
			index = i;
		}
		stud = 0;
	};
	max = max / 3;

	return max;

}

int Percent(Student* s, int N)
{
	int number = 0;
	double stud = 0;
	for (int i = 0; i < N; i++) {
		stud = s[i].Physical;
		if (stud == 5 || stud == 4) {
			number++;
		}
		stud = 0;
	};
	return (number * 100.0) / N;
}




