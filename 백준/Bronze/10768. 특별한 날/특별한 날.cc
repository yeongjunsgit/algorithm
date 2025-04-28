#include <iostream>

using namespace std;

int main()
{
    int year, month;
    cin >> year >> month;
    if (year >= 3) cout << "After";
    else if (year == 2) {
        if (month < 18) cout << "Before";
        else if (month == 18) cout << "Special";
        else cout << "After";
    }
    else cout << "Before";

    return 0;
}