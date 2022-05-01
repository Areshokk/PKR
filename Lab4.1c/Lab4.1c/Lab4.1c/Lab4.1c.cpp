#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable : 4996)

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <iostream>

#define N 512   /* max length */
 
bool analize_str (char *, size_t);
bool find ();
 
using namespace std;

int main()
{
    printf("'n' and 'o' %s\n", find() ? "found" : "not found");

    return 0;
}

bool analize_str (char *str, size_t size) {

    for (size_t i = 0, k = 2; k < size; i++, k++)
        if (str[i] == 'n' && str[k] == 'o')
            return true;

    return false;
}

bool find() {

    FILE* f = fopen("t.txt", "r");

    if (f == NULL) {
        fputs("Can't open file\n", stderr);
        return 1;
    }


    char str[N];

    while (fgets(str, N, f) != NULL) {
        if (analize_str(str, strlen(str)))
            return true;
    }

    if (ferror(f))
        fputs("Read error\n", stderr);

    return false;
}









































/*

#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>
#include <stdio.h>

using namespace std;

bool find();


int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    find() ? cout << "'n' або 'o' знайдено" << endl : cout << "'n' або 'o' не знайдено" << endl;
    return 0;
}


bool find()
{
    ifstream t("t.txt");
    string s;

    int k = 0;

    while (getline(t, s))
    {
        cout << s << endl;
        for (int i = 0; i < s.length() - 2; i++)
        {
            if (s[i] == 'n' &&
                s[i + 2] == 'o')
            {
                return true;
            }
        }
    }
    return false;
}
*/