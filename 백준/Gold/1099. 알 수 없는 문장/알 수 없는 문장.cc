#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

int N, M;
string target;
vector<string> sentences(50);
vector<int> dp(51, 99999999), sentences_size(50);


int check_sen(int now_idx, int start_idx)
{
    if (start_idx + sentences_size[now_idx] > M) return -1;
    
    int cnt = 0;
    string tmp = target.substr(start_idx, sentences_size[now_idx]);
    unordered_map<char, int> check_list;
    for (char c : tmp) {
        check_list[c]++;
    }
    
    for (int i=0; i<sentences_size[now_idx]; ++i) {
        if (sentences[now_idx][i] == tmp[i]) {
            check_list[tmp[i]]--;
            if (check_list[sentences[now_idx][i]] < 0) return -1;
        }
        else {
            if (check_list.find(sentences[now_idx][i]) != check_list.end()) {
                cnt++;
                check_list[sentences[now_idx][i]]--;
                if (check_list[sentences[now_idx][i]] < 0) return -1;
            }
            else return -1;
        }
    }
    
    return cnt;
}


int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> target >> N;
    for (int i=0; i<N; ++i) {
        cin >> sentences[i];
        sentences_size[i] = sentences[i].size();
    }
    dp[0] = 0;
    M = target.size();
    for (int i=0; i<M; ++i) {
        if (dp[i] != 99999999) {
            for (int j=0; j<N; ++j) {
                int check = check_sen(j, i);
                if (check != -1) dp[i + sentences_size[j]] = min(dp[i + sentences_size[j]], dp[i] + check);
            }
        }
    }
    if (dp[M] != 99999999) cout << dp[M];
    else cout << -1;

    return 0;
}