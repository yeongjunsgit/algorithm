#include <iostream>

using namespace std;

int main()
{
    int N, M;
    cin >> N >> M;
    
    int tmp = N % M;
    
    int target = N % 100;
    target -= tmp;
    
    if (target <= 0) {
        while (target < 0) {
            target += M;
        }
    }
    else {
        while (target > 0) {
            target -= M;
        }
        if (target < 0) {
            target += M;
        }
    }
    
    if (target < 10) {
        cout << 0 << target;
    }
    else {
        cout << target;
    }

    return 0;
}