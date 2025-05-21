#include <iostream>

using namespace std;

int main()
{
    long long N, cnt = 0, idx = 0;
    cin >> N;
    
    while (N > 0) {
        idx++;
        if (N >= idx) {
            N -= idx;
            cnt++;
        }
        else {
            break;
        }
    }
    
    cout << cnt;

    return 0;
}