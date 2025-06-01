#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N, num, cnt;
    cin >> N >> cnt;
    for (int i=1; i<N; ++i) {
        cin >> num;
        cnt += num - 1;
    }
    
    cout << cnt;

    return 0;
}