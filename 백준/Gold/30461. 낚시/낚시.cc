#include <iostream>
#include <vector>

using namespace std;

int N, M, Q, s, e;
vector<vector<int> > ocean_world(2001, vector<int>(2001, 0));

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M >> Q;
    for (int i=1; i<=N; ++i) {
        for (int j=1; j<=M; ++j) {
            cin >> ocean_world[i][j];
            ocean_world[i][j] += ocean_world[i-1][j];
        }
    }
    for (int i=1; i<=N; ++i) {
        for (int j=1; j<=M; ++j) {
            ocean_world[i][j] += ocean_world[i-1][j-1];
        }
    }
    
    for (int i=0; i<Q; ++i) {
        cin >> s >> e;
        cout << ocean_world[s][e] << "\n";
    }
    

    return 0;
}

