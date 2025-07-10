#include <iostream>

using namespace std;

int main()
{
    int T, F;
    cin >> T >> F;
    if (T > F) cout << "flight";
    else cout << "high speed rail";

    return 0;
}