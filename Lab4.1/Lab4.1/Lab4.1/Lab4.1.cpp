#include <iostream>
#include <fstream>
#include <string>
using namespace std;
bool search()
{
	ifstream f("t.txt");
	string s;
	while (getline(f, s)) {
		for (int j = 1; s[j] != '\0'; j++)
				if (s[j - 1] == 'n' && s[j + 1] == 'o')
					return true;
	return false;
	}
		
}
int main()
{

	if (search())
	{
		cout << "Is there group of symbols where s i,j-1 = n and s i,j+1 = o " << endl;
		cout << "yes" << endl;
	}
	else
	{
		cout << "Is there group of symbols where s i,j-1 = n and s i,j+1 = o " << endl;
		cout << "no" << endl;
	}

	return 0;
}
