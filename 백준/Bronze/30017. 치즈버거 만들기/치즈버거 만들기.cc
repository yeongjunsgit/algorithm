#include <iostream>

using namespace std;

int main()
{
    int P, C;
    cin >> P >> C;
    
    if (P <= C + 1) {
        cout << P * 2 - 1;
    }
    else {
        cout << C * 2 + 1;
    }
    
    return 0;
}
