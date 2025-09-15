#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T, X, N, M, num;
    string result = "YES";
    cin >> T >> X >> N;
    for (int i=0; i<N; ++i) {
        cin >> M;
        bool is_ok = false;
        for (int j=0; j<M; ++j) {
            cin >> num;
            if (num == X) is_ok = true;
        }
        if (!is_ok) result = "NO";
    }
    cout << result;

    return 0;
}