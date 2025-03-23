#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int T, A, B, C;
    cin >> T;
    
    A = B = C = 0;
    
    if (T >= 300) {
        A += T / 300;
        T %= 300;
    }
    if (T >= 60) {
        B += T / 60;
        T %= 60;
    }
    if (T >= 10) {
        C += T / 10;
        T %= 10;
    }
    
    if (T == 0) {
        cout << A << " " << B << " " << C;
    }
    else {
        cout << -1;
    }

    return 0;
}