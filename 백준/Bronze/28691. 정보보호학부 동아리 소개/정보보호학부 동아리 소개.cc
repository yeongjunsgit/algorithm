#include <iostream>

using namespace std;

int main()
{
    char tmp;
    cin >> tmp;
    
    if (tmp == 'M') cout << "MatKor";
    else if (tmp == 'W') cout << "WiCys";
    else if (tmp == 'C') cout << "CyKor";
    else if (tmp == 'A') cout << "AlKor";
    else cout << "$clear";
    

    return 0;
}