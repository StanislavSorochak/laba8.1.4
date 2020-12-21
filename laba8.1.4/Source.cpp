// Дано літерний рядок, який містить послідовність символів s[0], ..., s[n], ...
// 1) вияснити число входжень в послідовність групи букв "abc".
// 2) замінити кожну групу букв "abc" парою зірочок "**".
#include <iostream>
using namespace std;

char* change(char* str, const char* g, const char* g1, const char* zamina)
{
    char* d = new char[strlen(str) / 2 * 3 + 1];
    char* t = d;
    int j, k, l = 0;
    for (int i = 0; str[i] != '\0'; i++)
    {
        j = 0;
        k = i;
        l = 0;
        while (g[j] != '\0')
        {
            if (((str[k] == g[j]) || (str[k] == g1[j])) && str[k] != '\0')
            {
                if (j == 1)
                    l++;
                j++;
                k++;
            }
            else
                break;
        }
        if (g[j] == '\0' && (str[k - 1] != str[k - 2]))
        {
            *t++ = '*'; *t++ = '*'; *t++ = '*';
            i = k - 1;
        }
        else
        {
            if (l == 1)
            {
                *t++ = str[k - 2];
                i = k - 2;
            }
        }
        if (j == 0)
        {
            *t++ = str[k];
            i = k;
        }
        if (j == 1)
        {
            *t++ = str[k - 1];
            *t++ = str[k];
            i = k;
        }
    }
    *t = '\0';
    strcpy_s(str, strlen(str) / 2 * 3 + 1, d);
    return d;
}

int main()
{
    char str[102] = "asbdjkasabcalsdklasdjabcklmn";
    cout << "Done string: " << endl << endl << str << endl << endl;
    char g[] = "abc";
    char g1[] = "abc";
    char zamina[] = "**";

    cout << "Changed string: " << endl << endl;
    cout << change(str, g, g1, zamina) << endl;

    return 0;
}
