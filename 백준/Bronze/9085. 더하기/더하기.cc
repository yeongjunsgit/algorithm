#include <iostream>

using namespace std;

int T, N, num;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> T;
    for (int t=0; t<T; ++t) {
        cin >> N;
        int result = 0;
        for (int i=0; i<N; ++i) {
            cin >> num;
            result += num;
        }
        cout << result << "\n";
        
    }
    

    return 0;
}