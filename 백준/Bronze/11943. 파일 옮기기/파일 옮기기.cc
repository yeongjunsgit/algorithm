#include <iostream>

using namespace std;

int main()
{
    int sa, so, ea, eo;
    cin >> sa >> so >> ea >> eo;
    cout << min(sa + eo, so + ea);

    return 0;
}