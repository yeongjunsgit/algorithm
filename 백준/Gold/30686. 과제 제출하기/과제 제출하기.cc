#include <iostream>
#include <vector>

using namespace std;

int N, M, result = 999999999;
vector<int> study_continue(1001), used(7, 0);
vector<vector<int> > need_intelligence(7);

void combi(int depth, int now_cnt, vector<int> continue_time)
{
    if (depth == M) {
        result = min(result, now_cnt);
        return;
    }
    
    for (int i=0; i<M; ++i) {
        if (used[i] == 1) continue;
        int next_cnt = now_cnt;
        vector<int> next_continue_time;
        next_continue_time = continue_time;
        for (int j : need_intelligence[i]) {
            if (continue_time[j] == 0) {
                next_cnt++;
                if (next_cnt > result) break;
                next_continue_time[j] = study_continue[j];
            }
        }
        if (next_cnt < result) {
            for (int j=1; j<=N; ++j) {
                if (next_continue_time[j] != 0) next_continue_time[j]--;
            }
            used[i] = 1;
            combi(depth + 1, next_cnt, next_continue_time);
            used[i] = 0;
        }
    }
    
    return;
}


int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int cnt, num;
    cin >> N >> M;
    for (int i=1; i<=N; ++i) {
        cin >> study_continue[i];
    }
    for (int i=0; i<M; ++i) {
        cin >> cnt;
        for (int j=0; j<cnt; ++j) {
            cin >> num;
            need_intelligence[i].push_back(num);
        }
    }
    vector<int> continue_time(N+1, 0);
    
    combi(0, 0, continue_time);
    
    cout << result;

    return 0;
}
