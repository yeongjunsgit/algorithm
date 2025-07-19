#include <iostream>

using namespace std;

int main()
{
    string A;
    int cnt = 0;
    cin >> A;
    for (char c : A) {
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') cnt++;
    }
    cout << cnt;

    return 0;
}