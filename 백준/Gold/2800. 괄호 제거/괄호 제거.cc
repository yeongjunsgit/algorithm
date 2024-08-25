#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

string my_data;

int N, M;

struct Compare {
  bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
      return a.first > b.first;
  }  
};

void combi(vector<pair<int, int>>& match, vector<bool>& used, map<string, int>& results, vector<bool>& match_used, int idx, int picked)
{
    if (idx == M) {
        string tmp = "";
        for (int k=0; k<N; ++k) {
            if (used[k] == false) {
                tmp += my_data[k];
            }
        }
        results[tmp] = 1;
        return;
    }
    
    else {
        for (int i = picked - 1; i<M; ++i) {
            if (idx == 0 && i == picked - 1) {
                continue;
            }
            if (i == picked - 1) {
                combi(match, used, results, match_used, idx+1, picked);
            }
            else {
                if (match_used[i] == false) {
                    match_used[i] = true;
                    used[match[i].first] = true;
                    used[match[i].second] = true;
                    combi(match, used, results, match_used, idx+1, i+1);
                    match_used[i] = false;
                    used[match[i].first] = false;
                    used[match[i].second] = false;
                }
            }
        }
        return;
    }
}

int main()
{
    cin >> my_data;
    
    N = my_data.size();
    vector<int> stacker;
    vector<pair<int, int>> match;
    
    for (int i=0; i<N; ++i) {
        if (my_data[i] == '(') {
            stacker.push_back(i);
        }
        else if (my_data[i] == ')') {
            match.push_back({stacker.back(), i});
            stacker.pop_back();
        }
    }
    
    vector<bool> used(N, false);
    map<string, int> results;
    
    sort(match.begin(), match.end(), Compare());
    
    M = match.size();
    vector<bool> match_used(M, false);
    
    combi(match, used, results, match_used, 0, 0);
    
    for (auto r : results) {
        cout << r.first << "\n";
    }

    return 0;
}
