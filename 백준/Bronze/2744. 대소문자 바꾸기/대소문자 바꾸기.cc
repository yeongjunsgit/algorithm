#include <iostream>

using namespace std;

int main()
{
    string data;
    cin >> data;
    char tmp;
    for (char a : data) {
        if ('a' <= a && a <= 'z') {
            tmp = a - ' ';
            cout << tmp;
        }
        else {
            tmp = a + ' ';
            cout << tmp;
        }
    }

    return 0;
}