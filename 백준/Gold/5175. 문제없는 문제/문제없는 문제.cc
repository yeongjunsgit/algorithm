#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int T, N, M;


void get_best_combi(vector<vector<string> >& quiz, vector<int>& algo_cnt, vector<string>& best_combi, vector<int>& now, int& best_cnt, string combi, int idx, int now_cnt, int now_check)
{
    for (int i=idx; i<N; ++i) {
        int next_cnt = now_cnt + 1;
        int next_check = now_check;
        if (next_cnt > best_cnt) continue;
        for (auto s : quiz[i]) {
            int int_s = stoi(s);
            if (!now[int_s]) {
                next_check++;
            }
            now[int_s]++;
        }
        char now_quiz = i + 'A';
        string next_combi = combi + now_quiz;
        
        if (next_check == M) {
            if (next_cnt < best_cnt) {
                best_combi = {next_combi};
                best_cnt = next_cnt;
            }
            else if (next_cnt == best_cnt) {
                best_combi.push_back(next_combi);
            }
        }
        else {
            get_best_combi(quiz, algo_cnt, best_combi, now, best_cnt, next_combi, i+1, next_cnt, next_check);
        }
        for (auto s : quiz[i]) {
            int int_s = stoi(s);
            now[int_s]--;
        }
    }
    
    return;
}


int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> T;
    
    for (int t=1; t<=T; ++t) {
        cin >> M >> N;
        cin.ignore();
        string data, tmp;
        vector<vector<string> > quiz(N);
        vector<int> algo_cnt(N);
        for (int n=0; n<N; ++n) {
            int cnt;
            getline(cin, data);
            istringstream iss(data);
            while (iss >> tmp) {
                quiz[n].push_back(tmp);
                cnt++;
            }
            algo_cnt[n] = cnt;
        }
        vector<string> best_combi;
        vector<int> now(M+1, 0);
        int best_cnt = 999999999;
        
        get_best_combi(quiz, algo_cnt, best_combi, now, best_cnt, "", 0, 0, 0);
        
        sort(best_combi.begin(), best_combi.end(), less<string>());
        
        cout << "Data Set " << t << ": ";
        for (char c : best_combi[0]) {
            cout << c << " ";
        }
        cout << "\n\n";
        
    }

    return 0;
}
