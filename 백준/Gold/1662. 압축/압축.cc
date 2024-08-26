#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N;

struct Compare {
    bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
        return a.first < b.first;
    }
};

int main()
{
    string my_data;
    cin >> my_data;
    
    N = my_data.size();
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> que;
    vector<int> stacker;
    
    for (int i=0; i<N; ++i) {
        if (my_data[i] == '(') {
            stacker.push_back(i);
        }
        else if (my_data[i] == ')') {
            que.push({stacker.back(), i});
            stacker.pop_back();
        }
    }
    
    int result = 0;
    int tmp = 0;
    int idx = 0;
    int loca = -1;
    
    vector<int> loca_sum(N, 0);
    vector<bool> used(N, false);
    
    while (!que.empty()) {
        pair<int, int> now = que.top();
        que.pop();
        
        if (idx == 0) {
            idx++;
            tmp = (my_data[now.first - 1] - '0') * (now.second - now.first - 1);
            loca = now.first - 1;
            for (int i=loca; i<=now.second; ++i) {
                used[i] = true;
            }
        }
        else {
            if (now.first < loca && loca < now.second) {
                used[now.first] = true;
                used[now.second] = true;
                for (int i=now.first+1; i<now.second; ++i) {
                    if (used[i] == false) {
                        used[i] = true;
                        tmp++;
                    }
                    else {
                        if (loca_sum[i] > 0) {
                            tmp += loca_sum[i];
                            loca_sum[i] = 0;
                        }
                    }
                }
                tmp *= (my_data[now.first - 1] - '0');
                used[now.first - 1] = true;
                loca = now.first;
            }
            else {
                loca_sum[loca] = tmp;
                tmp = (my_data[now.first - 1] - '0') * (now.second - now.first - 1);
                loca = now.first - 1;
                for (int i=loca; i<=now.second; ++i) {
                    used[i] = true;
                }
            }
            
        }
    }
    
    result = tmp;

    for (int i=0; i<N; ++i) {
        if (used[i] == false) {
            result++;
            used[i] = true;
        }
        else {
            if (loca_sum[i] > 0) {
                result += loca_sum[i];
                loca_sum[i] = 0;
            }
        }
    }

    cout << result;

    return 0;
}
