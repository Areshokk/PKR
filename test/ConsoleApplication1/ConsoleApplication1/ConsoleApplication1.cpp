
//#include <iostream>
//#include <iomanip>
//#include <fstream>
//#include <string>
//#include <Windows.h>               // забезпечення відображення кирилиці
//
//using namespace std;
//
//enum Specialty { KOMP_NAYK, INFORMATUKA, MATEM_EKONOM, FIZ_MATEM, TRUD_NAVCH };
//
//string specialtyStr[] = { "Комп'ютерні науки", "Інформатика", "Математика та економіка", "Фізика та інформатика", "Трудове навчання" };
//
//struct Student
//{
//	char surname[64];
//	unsigned course;
//	Specialty specialty;
//	double SERrate;
//	unsigned physics;
//	unsigned maths;
//	union
//	{
//		unsigned programming;
//		unsigned ch_methods;
//		unsigned pedagogy;
//	};
//};
//
//void CreateBIN(const char* filename);
//void PrintBIN(const char* filename);
//void fWrite(fstream& f, const int i, Student x);
//Student fRead(fstream& f, const int i);
//void fChange(fstream& f, const int i, const int j);
//void SortBIN(const char* filename);
//void IndexSortBIN(const char* filename, const char* newfile);
//void PrintIndexSortedBIN(const char* filename, const char* newfile);
//int BinSearch(const char* filename, const char* surname, const double avg, const int course);
//
//int main()
//{                             // забезпечення відображення кирилиці:
//	SetConsoleCP(1251);       // встановлення сторінки win-cp1251 в потік вводу
//	SetConsoleOutputCP(1251); // встановлення сторінки win-cp1251 в потік виводу
//
//	char filename[100] = "f.dat";
//	char newfile[15] = "g.dat";
//	char surname[64];
//	double avg;
//	int found, course;
//
//	int menuItem;
//	do {
//		cout << endl;
//		cout << " Виберіть дію: " << endl << endl;
//		cout << " [1] - введення даних з клавіатури " << endl;
//		cout << " [2] - вивід даних на екран " << endl;
//		cout << " [3] - фізичне впорядкування даних " << endl;
//		cout << " [4] - індексне впорядкування та вивід даних " << endl;
//		cout << " [5] - бінарний пошук " << endl;
//		cout << " [0] - вихід та завершення роботи програми " << endl << endl;
//		cout << " Введіть значення: ";
//		cin >> menuItem;
//		cout << endl;
//
//		switch (menuItem)
//		{
//		case 1:
//			if (strcmp(filename, "") == 0) {
//				cout << "Введіть ім'я файлу: ";
//				cin >> filename;
//			}
//			CreateBIN(filename);
//			break;
//		case 2:
//			if (strcmp(filename, "") == 0) {
//				cout << "Файл не існує, спочатку створіть файл." << endl;
//				break;
//			}
//			PrintBIN(filename);
//			break;
//		case 3:
//			if (strcmp(filename, "") == 0) {
//				cout << "Файл не існує, спочатку створіть файл." << endl;
//				break;
//			}
//			SortBIN(filename);
//			PrintBIN(filename);
//			break;
//		case 4:
//			if (strcmp(filename, "") == 0) {
//				cout << "Файл не існує, спочатку створіть файл." << endl;
//				break;
//			}
//			IndexSortBIN(filename, newfile);
//			PrintIndexSortedBIN(filename, newfile);
//			break;
//		case 5:
//			if (strcmp(filename, "") == 0) {
//				cout << "Файл не існує, спочатку створіть файл." << endl;
//				break;
//			}
//
//			cout << "Введіть ключі пошуку:" << endl;
//			cout << " Прізвище: ";
//			cin.get();
//			cin.sync();
//			cin >> surname;
//			cout << " Середній бал: ";
//			cin >> avg;
//			cout << " Курс ";
//			cin >> course;
//
//			found = BinSearch(filename, surname, avg, course);
//
//			//cout <<"bin " << found << endl;
//
//			if (found == -1) {
//				cout << " Шуканого студента не знайдено" << endl;
//			}
//			else {
//				ifstream fin(filename, ios::binary);
//				if (!fin) {
//					cout << "Main: Помилка відкриття файлу. " << filename << endl;
//					return -1;
//				}
//				cout << " Знайдено студента в позиції № " << found + 1 << endl;
//			}
//			break;
//		case 0:
//			break;
//		default:
//			cout << " Ви ввели помилкове значення! "
//				" Слід ввести число - номер вибраного пункту меню " << endl;
//		}
//	} while (menuItem != 0);
//
//	return 0;
//}
//
//void CreateBIN(const char* filename)
//{
//	ofstream f(filename, ios::binary); // відкрили файл для запису
//	char ch; // відповідь користувача – чи продовжувати введення
//	int n = 1;
//	int specialty;
//	Student student;
//
//	do {
//		cout << " Студент № " << n << ":" << endl;
//		cin.get(); // очищуємо буфер клавіатури – бо залишаються символи
//		cin.sync(); // "кінець рядка", які не дають ввести наступний літерний рядок
//		cout << " Прізвище: ";
//		cin >> student.surname;
//		cout << " Курс: ";
//		cin >> student.course;
//		cout << " Спеціальність (0 - Комп'ютерні науки, 1 - Інформатика, 2 - Математика та економіка, 3 - Фізика та інформатика, 4 - Трудове навчання): ";
//		cin >> specialty;
//		student.specialty = (Specialty)specialty;
//		cout << " Оцінка з фізики: ";
//		cin >> student.physics;
//		cout << " Оцінка з математики: ";
//		cin >> student.maths;
//
//		switch (student.specialty)
//		{
//		case KOMP_NAYK:
//
//			cout << " Оцінка з програмування: ";
//			cin >> student.programming;
//			student.SERrate = ((student.physics + student.maths + student.programming) / 3.0);
//			cout << " Середній бал = " << student.SERrate;
//			break;
//		case INFORMATUKA:
//			cout << " Оцінка з чисельних методів: ";
//			cin >> student.ch_methods;
//			student.SERrate = ((student.physics + student.maths + student.ch_methods) / 3.0);
//			cout << " Середній бал = " << student.SERrate;
//			break;
//		case MATEM_EKONOM:
//		case FIZ_MATEM:
//		case TRUD_NAVCH:
//			cout << " Оцінка з педагогіки: ";
//			cin >> student.pedagogy;
//			student.SERrate = ((student.physics + student.maths + student.pedagogy) / 3.0);
//			cout << " Середній бал = " << student.SERrate;
//			break;
//		}
//		cout << endl;
//		f.write((char*)&student, sizeof(Student)); // записали у файл
//		n++;
//		cout << "Додати ще? (y/n): ";
//		cin >> ch;
//		cout << endl;
//	}
//
//	while (ch == 'y' || ch == 'Y');
//	cout << endl;
//	f.close();
//
//}
//
//void PrintBIN(const char* filename)
//{
//	ifstream f(filename, ios::binary); // відкрили файл для зчитування
//	if (!f) {
//		cout << "PrintBIN: Помилка відкриття файлу." << endl;
//		return;
//	}
//
//	cout << "=================================================================================================================================" << endl;
//	cout << " |  №  |    Прізвище    | Курс |      Спеціальність      | Фізика | Математика | Програмування | Чисельні методи | Педагогіка |" << endl;
//	cout << "---------------------------------------------------------------------------------------------------------------------------------" << endl;
//
//	Student student;
//	int i = 1;
//
//	while (f.read((char*)&student, sizeof(Student))) {
//		cout << " | " << setw(2) << right << i << " ";
//		cout << " | " << setw(14) << left << student.surname;
//		cout << " |  " << setw(2) << right << student.course << " ";
//		cout << " | " << setw(23) << left << specialtyStr[student.specialty];
//		cout << " | " << setw(4) << right << student.physics << "  ";
//		cout << " | " << setw(6) << right << student.maths << "    ";
//
//		switch (student.specialty)
//		{
//		case KOMP_NAYK:
//			cout << " | " << setw(7) << right << student.programming << "     " << "  | " << setw(18) << right << " | " << setw(12) << right << "|" << endl;
//			break;
//		case INFORMATUKA:
//			cout << " | " << setw(16) << right << "| " << setw(8) << right << student.ch_methods << "      " << "  | " << setw(12) << right << "|" << endl;
//			break;
//		case MATEM_EKONOM:
//		case FIZ_MATEM:
//		case TRUD_NAVCH:
//			cout << " | " << setw(16) << right << "| " << setw(18) << right << "  | " << setw(6) << right << student.pedagogy << "     " << "|" << endl;
//			break;
//		}
//		i++;
//	}
//	cout << "=================================================================================================================================" << endl;
//	cout << endl;
//}
//
//void fWrite(fstream& f, const int i, Student x)
//{
//	f.seekp(i * (long)sizeof(Student));   // встановили вказівник
//	f.write((char*)&x, sizeof(Student));  // записали значення
//}
//
//Student fRead(fstream& f, const int i)
//{
//	Student x;
//	f.seekg(i * (long)sizeof(Student));   // встановили вказівник
//	f.read((char*)&x, sizeof(Student));   // прочитали значення
//	return x;
//}
//
//void fChange(fstream& f, const int i, const int j)
//{
//	Student x = fRead(f, i);
//	Student y = fRead(f, j);
//	fWrite(f, i, y);
//	fWrite(f, j, x);
//}
//
//void SortBIN(const char* filename)
//{
//	fstream f(filename, ios::binary | ios::in | ios::out);
//
//	f.seekg(0, ios::end);
//	int size = f.tellg() / sizeof(Student);
//	f.seekg(0, ios::beg);
//
//	for (int i0 = 1; i0 < size; i0++) {
//		for (int i1 = 0; i1 < size - i0; i1++)
//		{
//			Student a = fRead(f, i1);
//			Student b = fRead(f, i1 + 1);
//
//			if ((a.SERrate > b.SERrate)
//				||
//				(a.SERrate == b.SERrate &&
//					strcmp(a.surname, b.surname) == -1)
//				||
//				(a.SERrate == b.SERrate &&
//					strcmp(a.surname, b.surname) == 0) &&
//						a.course > b.course)			{
//				fChange(f, i1, i1 + 1);
//			}
//		}
//	}
//
//	f.seekp(0, ios::end);
//}
//
//void IndexSortBIN(const char* filename, const char* newfile)
//{	// сортування файлу – за допомогою послідовного доступу: зчитуємо з одного файлу і записуємо в інший
//	fstream g(newfile, ios::binary | ios::in | ios::out | ios::trunc);
//	fstream f(filename, ios::binary | ios::in | ios::out);
//
//	f.seekg(0, ios::end);
//	int size = f.tellg() / sizeof(Student);
//	f.seekg(0, ios::beg);
//
//	for (int i = 0; i < size; i++)
//		g.write((char*)&i, sizeof(int));
//	g.seekg(0, ios::beg);
//
//	int x, y;
//
//	for (int i0 = 1; i0 < size; i0++) {
//		for (int i1 = 0; i1 < size - i0; i1++) {
//			;
//			g.seekg(i1 * (long)sizeof(int));
//			g.read((char*)&x, sizeof(int));
//			g.read((char*)&y, sizeof(int));
//			Student a = fRead(f, x);
//			Student b = fRead(f, y);
//			if ((a.SERrate > b.SERrate)
//				||
//				(a.SERrate == b.SERrate &&
//					strcmp(a.surname, b.surname) == -1)
//				||
//				(a.SERrate == b.SERrate &&
//					strcmp(a.surname, b.surname) == 0 &&
//						a.course > b.course))
//			{
//				int  i2;
//				g.seekg(i1 * (long)sizeof(int));
//				g.read((char*)&i1, sizeof(int));
//				g.seekg((i1 + 1) * (long)sizeof(int));
//				g.read((char*)&i2, sizeof(int));
//				g.seekg(i1 * (long)sizeof(int));
//				g.write((char*)&i2, sizeof(int));
//				g.seekg((i1 + 1) * (long)sizeof(int));
//				g.write((char*)&i1, sizeof(int));
//			}
//		}
//	}
//
//	g.seekg(0, ios::beg);
//	f.seekp(0, ios::end);
//	f.close();
//	g.close();
//}
//
//void PrintIndexSortedBIN(const char* filename, const char* newfile)
//{
//	cout << "=================================================================================================================================" << endl;
//	cout << " |  №  |    Прізвище    | Курс |      Спеціальність      | Фізика | Математика | Програмування | Чисельні методи | Педагогіка |" << endl;
//	cout << "---------------------------------------------------------------------------------------------------------------------------------" << endl;
//
//	ifstream g(newfile, ios::binary);		// відкрили файл для запису
//	if (!g) {
//		cout << "PrintIndexSorted: Помилка відкриття файлу. " << newfile << endl;
//		return;
//	}
//	fstream f(filename, ios::binary | ios::in | ios::out);	// відкрили файл для зчитування
//	if (!f) {
//		cout << "PrintIndexSorted: Помилка відкриття файлу. " << filename << endl;
//		return;
//	}
//
//	Student student;
//	f.seekg(0, ios::end);
//	int size = f.tellg() / sizeof(Student);
//	f.seekg(0, ios::beg);
//
//	int i = 1;
//	int idx;
//
//	while (g.read((char*)&idx, sizeof(int))) {
//		f.seekg(idx * (long)sizeof(Student));
//		f.read((char*)&student, sizeof(Student));
//		cout << " | " << setw(2) << right << i++ << " ";
//		cout << " | " << setw(14) << left << student.surname;
//		cout << " |  " << setw(2) << right << student.course << " ";
//		cout << " | " << setw(23) << left << specialtyStr[student.specialty];
//		cout << " | " << setw(4) << right << student.physics << "  ";
//		cout << " | " << setw(6) << right << student.maths << "    ";
//
//		switch (student.specialty)
//		{
//		case KOMP_NAYK:
//			cout << " | " << setw(7) << right << student.programming << "     " << "  | " << setw(18) << right << " | " << setw(12) << right << "|" << endl;
//			break;
//		case INFORMATUKA:
//			cout << " | " << setw(16) << right << "| " << setw(8) << right << student.ch_methods << "      " << "  | " << setw(12) << right << "|" << endl;
//			break;
//		case MATEM_EKONOM:
//		case FIZ_MATEM:
//		case TRUD_NAVCH:
//			cout << " | " << setw(16) << right << "| " << setw(18) << right << "  | " << setw(6) << right << student.pedagogy << "     " << "|" << endl;
//			break;
//		}
//	}
//	cout << "=================================================================================================================================" << endl;
//	cout << endl;
//}
//
//int BinSearch(const char* filename, const char* surname, const double avg, const int course)
//{   // повертає індекс знайденого елемента або -1, якщо шуканий елемент відсутній
//	fstream f(filename, ios::binary | ios::in | ios::out);
//	if (!f) {
//		cout << "Print_I: Помилка відкриття файлу. " << filename << endl;
//		return -1;
//	}
//	int L = 0, m;
//	f.seekg(0, ios::end);
//	int R = f.tellg() / sizeof(Student);
//	f.seekg(0, ios::beg);
//
//	do {
//		m = (L + R) / 2;
//		Student a = fRead(f, m);
//
//		if (a.SERrate == avg && strcmp(a.surname, surname) == 0 && a.course == course) {
//			return m;
//		}
//		else if ((a.SERrate > avg) ||
//			(a.SERrate == avg && strcmp(a.surname, surname) == -1) ||
//			(a.SERrate == avg && strcmp(a.surname, surname) == 0 && a.course > course))
//		{
//			R = m - 1;
//		}
//		else {
//			L = m + 1;
//		}
//	} while (L <= R);
//
//	return -1;
//}



//#include <iostream>
//#include <iomanip>
//#include <fstream>
//#include <windows.h>
//#include <string>
//#include <algorithm>
//using namespace std;
//
//// Console 
//
//namespace cons {
//
//	COORD GetBufferSize() {
//		static HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
//		CONSOLE_SCREEN_BUFFER_INFO csbInfo;
//		GetConsoleScreenBufferInfo(handle, &csbInfo);
//		return { csbInfo.srWindow.Right - csbInfo.srWindow.Left ,
//				csbInfo.srWindow.Bottom - csbInfo.srWindow.Top };
//	}
//
//	const COORD size = GetBufferSize();
//
//	void clear() {
//		system("cls");
//	}
//
//	void gotoxy(const COORD pos) {
//		static HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
//		SetConsoleCursorPosition(handle, pos);
//	}
//
//	COORD getxy() {
//		static HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
//		CONSOLE_SCREEN_BUFFER_INFO csbi;
//		if (!GetConsoleScreenBufferInfo(handle, &csbi))
//			return { -1, -1 };
//		return csbi.dwCursorPosition;
//	}
//
//	void clearto(const COORD pos) {
//		COORD current_pos = getxy();
//		while (current_pos.Y >= pos.Y)
//		{
//			if (current_pos.Y > pos.Y) {
//				gotoxy({ 0, current_pos.Y });
//				for (int i = 0; i < size.X; i++)
//					cout << ' ';
//			}
//			else if (current_pos.Y == pos.Y) {
//				gotoxy({ pos.X, current_pos.Y });
//				for (int i = 0; i <= size.X - pos.X; i++)
//					cout << ' ';
//			}
//
//			current_pos.Y--;
//		}
//		gotoxy(pos);
//	}
//
//	void change_cusor_visibility(const bool& rst) {
//		static HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
//		CONSOLE_CURSOR_INFO structCursorInfo;
//		GetConsoleCursorInfo(handle, &structCursorInfo);
//		structCursorInfo.bVisible = rst;
//		SetConsoleCursorInfo(handle, &structCursorInfo);
//	}
//
//	template <typename T>
//	T input(bool (*check)(T& temp, char* err), const bool& rom, const char* text, ...) {
//		COORD start[2] = { getxy() };
//		char out[256] = { 0 }, err[256] = { 0 };
//		T temp;
//
//		va_list  args;
//		va_start(args, text);
//		vsprintf_s(out, 255, text, args);
//		va_end(args);
//		cout << out;
//		start[1] = getxy();
//		if (check == nullptr)
//			check = [](T& temp, char* err) -> bool { return !cin.fail(); };
//		do {
//			cin.clear();
//			cin.ignore();
//			if (err[0] != '\0') {
//				change_cusor_visibility(false);
//				clearto(start[0]);
//				cout << err << endl;
//				err[0] = '\0';
//				cout << out;
//				start[1] = getxy();
//				change_cusor_visibility(true);
//			}
//			else clearto(start[1]);
//			cin >> temp;
//		} while (!check(temp, err));
//		if (rom)
//			clearto(start[0]);
//		return temp;
//	}
//}
//
//struct Bill {
//	string r_r_payer;
//	string r_r_recipient;
//	float sum;
//};
//
//Bill* InitBill() {
//	cout << "Adding new bill: " << endl;
//	Bill* bill = new Bill();
//	bill->r_r_payer = cons::input<string>(nullptr, false, "Input payer IBAN: ");
//	bill->r_r_recipient = cons::input<string>(nullptr, false, "Input recipient IBAN: ");
//	bill->sum = cons::input<float>([](float& temp, char* err)-> bool {
//		if (cin.fail() ||
//			temp <= 0)
//		{
//			sprintf_s(err, 255, "Incorrect money (money > 0) (%f)", temp);
//			return false;
//		}
//		return true;
//		}, false, "Input transfered money: ");
//	return bill;
//}
//
//void sort_bill(Bill** bills, const unsigned int& size) {
//	sort(bills, bills + size, [](Bill* a1, Bill* a2) -> bool {
//		return a1->r_r_payer < a2->r_r_payer;
//		});
//}
//
//int get_bill_by_payer(Bill** bills, const unsigned int& size, const string& payer) {
//	for (int i = 0; i < size; i++)
//		if (bills[i]->r_r_payer == payer)
//			return i;
//	return -1;
//}
//
//void draw_bills(Bill** bills, const unsigned int& size) {
//	cout << "============================================================================================" << endl;
//	cout << "| Id | Payer IBAN                         | Recipient IBAN                     | Sum       |" << endl;
//	cout << "--------------------------------------------------------------------------------------------" << endl;
//	for (int i = 0; i < size; i++) {
//		cout << "| " << setw(3) << i + 1
//			<< "| " << setw(35) << bills[i]->r_r_payer
//			<< "| " << setw(35) << bills[i]->r_r_recipient
//			<< "| " << setw(10) << fixed << setprecision(2) << bills[i]->sum
//			<< "|" << endl;
//	}
//	cout << "============================================================================================" << endl;
//}
//
//void AddBill(Bill**& bills, int& count, Bill* new_bill) {
//	Bill** n_bills = new Bill * [++count];
//	memcpy(n_bills, bills, (count - 1) * sizeof(Bill*));
//	delete[] bills;
//	bills = n_bills;
//	bills[count - 1] = new_bill;
//}
//
//void save_string_to_file(ofstream& file, const string& str) {
//	const int size = str.size();
//	file.write(reinterpret_cast<const char*>(&size), sizeof(int));
//	file.write(str.c_str(), size);
//}
//
//void save_bill_to_file(ofstream& file, Bill* bill) {
//	save_string_to_file(file, bill->r_r_payer);
//	save_string_to_file(file, bill->r_r_recipient);
//	file.write(reinterpret_cast<const char*>(&bill->sum), sizeof(float));
//}
//
//void save_bills_to_file(ofstream& file, Bill** bills, const int& size) {
//	file.write(reinterpret_cast<const char*>(&size), sizeof(int));
//	for (int i = 0; i < size; i++)
//		save_bill_to_file(file, bills[i]);
//}
//
//string read_string_from_file(ifstream& file) {
//	int size = 0;
//	file.read(reinterpret_cast<char*>(&size), sizeof(int));
//	char* temp = new char[size + 1];
//	file.read(reinterpret_cast<char*>(temp), size);
//	temp[size] = '\0';
//	string str(temp);
//	delete[] temp;
//	return str;
//}
//
//Bill* read_bill_from_file(ifstream& file) {
//	Bill* bill = new Bill();
//	bill->r_r_payer = read_string_from_file(file);
//	bill->r_r_recipient = read_string_from_file(file);
//	file.read(reinterpret_cast<char*>(&bill->sum), sizeof(float));
//	return bill;
//}
//
//Bill** read_bills_from_file(ifstream& file, int& size) {
//	file.read(reinterpret_cast<char*>(&size), sizeof(int));
//	Bill** bills = new Bill * [size];
//	for (int i = 0; i < size; i++)
//		bills[i] = read_bill_from_file(file);
//	return bills;
//}
//
//void main() {
//	SetConsoleCP(1251); // âñòàíîâëåííÿ ñòîð³íêè win-cp1251 â ïîò³ê ââîäó
//	SetConsoleOutputCP(1251); // âñòàíîâëåííÿ ñòîð³íêè win-cp1251 â ïîò³ê âèâîäó
//	cout.setf(ios_base::left);
//
//	Bill** bills = nullptr;
//	int count = 0, state = 1;
//	char message[256] = { 0 };
//	do {
//		cons::clear();
//		//cout << bin_search_student(st, count, "abcd max", 2, 3) << endl;
//		draw_bills(bills, count);
//		if (message[0] != '\0') {
//			cout << message << endl;
//			message[0] = '\0';
//		}
//		cout << "[1] Add bill" << endl
//			<< "[2] Sort bill by sender IBAN" << endl
//			<< "[3] Search bill by payer" << endl
//			<< "[4] Save bills to file" << endl
//			<< "[5] Load bills from file" << endl
//			<< "[0] Exit" << endl;
//		state = cons::input<unsigned int>(nullptr, false, "Select action: ");
//		switch (state)
//		{
//		case 1:
//			AddBill(bills, count, InitBill());
//			sprintf_s(message, 255, "Succesful add bill!");
//			break;
//		case 2:
//			sort_bill(bills, count);
//			sprintf_s(message, 255, "Succesful sort bills!");
//			break;
//		case 3: {
//			int id;
//			string payer = cons::input<string>(nullptr, false, "Input payer IBAN: ");
//			if (id = get_bill_by_payer(bills, count, payer), id != -1)
//				sprintf_s(message, 255, "Succesful search bill - %s with sum %f!", bills[id]->r_r_payer.c_str(), bills[id]->sum);
//			else sprintf_s(message, 255, "Incorrect bill payer - %s!", payer.c_str());
//		}
//			  break;
//		case 4: {
//			string file_name = cons::input<string>([](string& temp, char* err) -> bool {
//				if (cin.fail() ||
//					temp.size() < 1) {
//					strcpy_s(err, 255, "Incorrect file name!");
//					return false;
//				}
//				return true;
//				}, false, "Input filename: ");
//			ofstream file = ofstream(file_name, std::ios_base::binary);
//			if (file.is_open()) {
//				save_bills_to_file(file, bills, count);
//				file.close();
//				sprintf_s(message, 255, "Succesful save bills to file %s", file_name.c_str());
//			}
//			else sprintf_s(message, 255, "Can't open file %s!", file_name.c_str());
//		}
//			  break;
//		case 5: {
//			string file_name = cons::input<string>([](string& temp, char* err) -> bool {
//				if (cin.fail() ||
//					temp.size() < 1) {
//					strcpy_s(err, 255, "Incorrect file name!");
//					return false;
//				}
//				return true;
//				}, false, "Input filename: ");
//			ifstream file = ifstream(file_name, std::ios_base::binary);
//			if (file.is_open()) {
//				if (bills != nullptr) {
//					for (int i = 0; i < count; i++)
//						delete bills[i];
//					delete[] bills;
//					count = 0;
//				}
//				bills = read_bills_from_file(file, count);
//				file.close();
//				sprintf_s(message, 255, "Succesful load bills from file %s", file_name.c_str());
//			}
//			else sprintf_s(message, 255, "Can't open file %s!", file_name.c_str());
//		}
//			  break;
//		default:
//			sprintf_s(message, 255, "Incorrect action!");
//		}
//	} while (state > 0);
//
//	if (bills != nullptr) {
//		for (int i = 0; i < count; i++)
//			delete bills[i];
//		delete[] bills;
//		count = 0;
//	}
//}



#include <iostream>
#include <string>
#include <fstream>
using namespace std;

void formt(string& str) {
	size_t pos_space = str.find(' '),
		start = 0, end = 0, tos;
	string m;
	while (start = str.find_first_of("0123456789", start), start < pos_space&& start != -1) {
		end = str.find_first_not_of("0123456789.,", start + 1);
		m = str.substr(start, end - start);
		if (tos = m.find_first_of(".,"), tos != -1 && tos + 3 < m.length()) {
			m = to_string(stof(m));
			tos = m.find_first_of(".,");
			m = m.substr(0, tos + 3);
			str.replace(start, end - start, m);
			pos_space -= end - start - m.length();
			start += m.length() + 1;
		}
		else start = end;
	}
}

void formt_file(ifstream& in, ofstream& out) {
	string tmp;
	while (!in.eof()) {
		getline(in, tmp);
		formt(tmp);
		out << tmp << endl;
	}
}

void main() {
	string t = "r.txt", t2 = "m.txt";

	cout << "Input input  filename: "; cin >> t;
	cout << "Input output filename: "; cin >> t2;

	ifstream in_file(t);
	ofstream out_file(t2);
	if (in_file.is_open()) {
		if (out_file.is_open())
		{
			formt_file(in_file, out_file);
			cout << "File successfully formatted!";
			out_file.close();
		}
		else cout << "Can't open output file!";
		in_file.close();
	}
	else cout << "Can't open input file!";
	cout << endl;
}