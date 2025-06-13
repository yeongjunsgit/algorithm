#include <iostream>
#include <vector>

using namespace std;

int N, M;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;
    int num, idx = 0;
    vector<int> musics(100001);
    for (int i=1; i<=N; ++i) {
        cin >> num;
        for (int j=0; j<num; ++j) {
            musics[idx + j] = i;
        }
        idx += num;
    }
    
    for (int i=1; i<=M; ++i) {
        cin >> num;
        cout << musics[num] << "\n";
    }
    

    return 0;
}