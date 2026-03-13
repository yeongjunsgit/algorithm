#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N, num, cnt = 0;
    cin >> N;
    for (int i=1; i<=N; ++i) {
        cin >> num;
        if (num != i) cnt++;
    }
    cout << cnt;
    
    return 0;
}
