#include <iostream>

using namespace std;

int main()
{
    string data;
    cin >> data;
    
    if (data == "NLCS") cout << "North London Collegiate School";
    else if (data == "BHA") cout << "Branksome Hall Asia";
    else if (data == "KIS") cout << "Korea International School";
    else cout << "St. Johnsbury Academy";

    return 0;
}
