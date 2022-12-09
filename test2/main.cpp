#include<iostream>
#include<math.h>
#include <Windows.h>
using namespace std;

string text = "РАУТ03";
const int N1 = 44,
          N2 = 6;
const int mas[N2] = { /*31, 61, 23, 21, 75, 80*/430, 1, 1146, 3309, 3142, 3430 };

double p = 59;
double q = 61;
double e = 7;

const char table[N1] = {"А","Б","В","Г","Д","Е","Ї","Ж","З","И","Й",
        "К","Л","М","Н","О","П","Р","С","Т","У","Ф","Х","Ц",
        "Ч","Ш","Щ","Є","Ґ","Ь","І","Ю","Я","_",
        "0","1","2","3","4","5","6","7","8","9"};

int gcd(int a, int b) {
    int t;
    while (1) {
        t = a % b;
        if (t == 0)
            return b;
        a = b;
        b = t;
    }
}

void Encrypt() {


    double n = p * q;
    double track;
    double phi = (p - 1) * (q - 1);
    while (e < phi)
    {
        track = gcd(e, phi);
        if (track == 1)
            break;
        else
            e++;
    }
    for (int i = 0; i < text.length(); i++)
    {
        for (int j = 0; j < N1; j++)
        {
            if (text[i] == table[j])
            {
                int d = 0;
                for (int i = 0; i <= 9; i++) {
                    int x = 1 + (i * phi);
                    if (fmod(x, e) == 0)      //d is for private key exponent
                    {
                        d = x / e;
                        break;
                    }
                }
                double message = j+1;
                double c = pow(message, e);
                double m = pow(c, d);
                c = fmod(c, n);
                m = fmod(m, n);
                cout << "\n" << "Encrypted message = " << c;
                cout << "\n" << "Decrypted message = " << m;
            }
        }
    }
    cout << endl;
}

void Decrypt() {
    cout << endl << "Result: ";
    for (int i = 0; i < N2; i++)
    {
        double n = p * q;
        double track;
        double phi = (p - 1) * (q - 1);

        while (e < phi)
        {
            track = gcd(e, phi);
            if (track == 1)
                break;
            else
                e++;
        }

        double d1 = 1 / e;
        double d = fmod(d1, phi);
        double message = mas[i];
        double c = pow(message, e);
        double m = pow(c, d);
        c = fmod(c, n);
        m = fmod(m, n);
        int c1 = c;
        cout << table[c1 - 1];
        /*cout << "\n" << "Encrypted message = " << c;
        cout << "\n" << "Decrypted message = " << m;*/
    }
    cout << endl;
}


int main() {

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int chs;
    do
    {
        cout << endl;
        cout << "Виберіть дію" << endl;
        cout << "1) Encrypt " << endl;
        cout << "2) Decrypt " << endl;
        cout << "0) вихід " << endl << endl;
        cout << "Введіть пункт >> ";
        cin >> chs;
        switch (chs)
        {
        case 1:
            Encrypt();
            break;
        case 2:
            Decrypt();
            break;
        default:
            cout << "Такого пункту немає!!!!!" << endl;
            break;
        }

    } while (chs != 0);

    return 0;
}