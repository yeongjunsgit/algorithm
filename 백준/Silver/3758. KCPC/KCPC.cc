#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <numeric>

using namespace std;

struct info {
    int id;
    int team_score;
    int request_num;
    int last_request;
};

struct Compare {
    bool operator() (const info& a, const info& b) const {
        if (a.team_score != b.team_score) {
            return a.team_score > b.team_score;
        }
        
        if (a.request_num != b.request_num) {
            return a.request_num < b.request_num;
        }
        
        return a.last_request < b.last_request;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    cin >> T;
    
    for (int a=0; a<T; ++a) {
        // 각각 n = 팀의 개수, k는 문제의 개수, t = 우리 팀 번호, m = 총 제출 횟수
        int n, k, t, m;
        cin >> n >> k >> t >> m;
        
        int request_entry[n+1]{0};
        int last_entry[n+1]{-1};
        vector<vector<int>> score_info(n+1, vector<int>(k+1));
        
        for (int i=0; i<m; ++i) {
            // id = 제출한 팀번호, num = 문제번호, score = 획득한 점수
            int id, num, score;
            cin >> id >> num >> score;
            
            request_entry[id] += 1;
            last_entry[id] = i;
            if (score_info[id][num] < score){
                score_info[id][num] = score;
            }
            
        }
        
        vector<info> info_lis; 
        
        for (int i=1; i<n+1; ++i) {
            int tmp_score = accumulate(score_info[i].begin(), score_info[i].end(), 0);
            info now_info = {i, tmp_score, request_entry[i], last_entry[i]};
            info_lis.push_back(now_info);
        }
        
        sort(info_lis.begin(), info_lis.end(), Compare());
        
        for (int i=0; i<n; ++i) {
            if (info_lis[i].id == t) {
                cout << i+1;
            }
        }
        
        cout << '\n';
    }

    return 0;
}
