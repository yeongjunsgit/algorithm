#include <iostream>

using namespace std;

int N, M, cnt = 0;
string quest;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;
    for (int i=0; i<N; ++i) {
        cin >> quest;
        int o = 0, x = 0;
        for (int i=0; i<M; ++i) {
            if (quest[i] == 'O') o++;
            else x++;
        }
        if (o > x) cnt++;
    }

    cout << cnt;

    return 0;
}