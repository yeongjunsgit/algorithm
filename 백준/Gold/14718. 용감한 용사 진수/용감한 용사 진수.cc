#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

int N, K, best_status = 3000001;
vector<vector<int> > soldiers(100, vector<int>(3) );
vector<vector<int> > each_status(3);

void get_best()
{
    for (int i=0; i<N; ++i) {
        for (int j=0; j<N; ++j) {
            for (int z=0; z<N; ++z) {
                int now_status = each_status[0][i] + each_status[1][j] + each_status[2][z];
                if (best_status <= now_status) continue;
                int cnt = 0;
                for (int q=0; q<N; ++q) {
                    if (soldiers[q][0] <= each_status[0][i] && soldiers[q][1] <= each_status[1][j] && soldiers[q][2] <= each_status[2][z]) {
                        cnt++;
                    }
                }
                if (cnt >= K) best_status = min(best_status, now_status);
            }
        }
    }
    
    return;
}



int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> K;
    for (int i=0; i<N; ++i) {
        for (int j=0; j<3; ++j) {
            cin >> soldiers[i][j];
            each_status[j].push_back(soldiers[i][j]);
        }
    }
    
    for (int i=0; i<3; ++i) {
        sort(each_status[i].begin(), each_status[i].end(), less());
    }
    
    get_best();

    cout << best_status;

    return 0;
}
