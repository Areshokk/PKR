#include <iostream>
#include <fstream>
#include <time.h>
#include <Windows.h>

using namespace std;

void Create(const char* fName)
{
	srand((unsigned)time(NULL));
	ofstream f(fName, ios::binary);
	int x;
	for (int i = 0; i < 10; i++)
	{
		x = -10 + rand() % 21;
		f.write((char*)&x, sizeof(x));
	}
}

void Print(const char* fName)
{
	ifstream f(fName, ios::binary);
	int x;
	while (f.read((char*)&x, sizeof(x)))
		cout << x << " ";
	cout << endl;
}

void ProcessBin(const char* fname, const char* gname) {
	
	ifstream f(fname, ios::binary);
	ofstream g(gname, ios::binary);
	int l;
	int a = 0, b = 0, j = 0, h = 0;

	while (f.read((char*)&l, sizeof(l))) {
		if (l % 2 == 0) {
			a += l;
			h++;
		}
		if (l % 2 != 0) {
			b += l;
			j++;
		}
	}
	double par = (double)a / h;
	double npar = 1.0 * b / j;
	
	cout << "Середне арифметичне парних: " << par << endl;
	cout << "Середне арифметичне не парних: " << npar << endl;

	g.write((char*)&par, sizeof(par));
	g.write((char*)&npar, sizeof(npar));
	f.close();
	g.close();
}


int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	char f[6] = "f.dat";
	char g[6] = "g.dat";
	Create(f);
	Print(f);
	cout << endl;
	ProcessBin(f, g);
	
	cin.get();
	return 0;
}