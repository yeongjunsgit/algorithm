#include <iostream>

using namespace std;

int main()
{
    int N, num, cnt = 0;
    cin >> N;
    for (int i=0; i<5; ++i) {
        cin >> num;
        if (N == num) cnt++;
    }
    
    cout << cnt;

    return 0;
}