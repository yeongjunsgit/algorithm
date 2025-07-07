#include <iostream>

using namespace std;

int main()
{
    int N, cnt = 0;
    cin >> N;
    cnt += N / 5;
    if (N % 5 != 0) {
        cnt++;
    }
    cout << cnt;

    return 0;
}