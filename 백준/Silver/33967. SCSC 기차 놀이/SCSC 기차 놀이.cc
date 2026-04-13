#include <iostream>

using namespace std;

int N;
string SCSC_train;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> SCSC_train;
    int cnt = 0;
    char before = '[';
    for (int i=1; i<N; ++i) {
        if (SCSC_train[i] == '2' && before == '2') cnt += 2;
        else if (SCSC_train[i] == '5' && before == '5') cnt += 2;
        else if (before == ']' && SCSC_train[i] == '[') cnt += 0;
        else cnt++;
        
        before = SCSC_train[i];
        
    }
    
    cout << cnt;

    return 0;
}