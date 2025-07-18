#include <iostream>

using namespace std;

int main()
{
    int N, cnt = 1;
    cin >> N;
    for (int i=0; i<N; ++i) {
        cnt *= 2;
    }
    cout << cnt;

    return 0;
}