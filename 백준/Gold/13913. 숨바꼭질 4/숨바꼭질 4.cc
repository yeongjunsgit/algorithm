#include <iostream>
#include <vector>
#include <queue>

#define pll pair<int, int>

using namespace std;

struct Compare
{
    bool operator()(const pll& a, const pll& b) {
        return a.first > b.first;
    }
};

int S, E;
vector<int> DP(100001, -1), before(100001, -1);

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> S >> E;
    DP[S] = 0;
    priority_queue<pll, vector<pll>, Compare> que;
    que.push({0, S});
    while (!que.empty()) {
        int now_turn = que.top().first;
        int now_loca = que.top().second;
        que.pop();
        if (DP[now_loca] < now_turn) continue;
        if (DP[E] != -1 && now_turn >= DP[E]) continue;
        // cout << "[" << now_loca << "] "; 
        // +1 할 경우
        if (now_loca + 1 <= 100000 && (DP[now_loca + 1] == -1 || DP[now_loca + 1] > now_turn + 1)) {
            DP[now_loca + 1] = now_turn + 1;
            que.push({now_turn + 1, now_loca + 1});
            before[now_loca + 1] = now_loca;
            // cout << now_loca + 1 << " ";
        }
        // -1 할 경우
        if (now_loca - 1 >= 0 && (DP[now_loca - 1] == -1 || DP[now_loca - 1] > now_turn + 1)) {
            DP[now_loca - 1] = now_turn + 1;
            que.push({now_turn + 1, now_loca - 1});
            before[now_loca - 1] = now_loca;
            // cout << now_loca - 1 << " ";
        }
        // *2 하는 경우
        if (now_loca * 2 <= 100000 && (DP[now_loca * 2] == -1 || DP[now_loca * 2] > now_turn + 1)) {
            DP[now_loca * 2] = now_turn + 1;
            que.push({DP[now_loca * 2], now_loca * 2});
            before[now_loca * 2] = now_loca;
            // cout << now_loca * 2 << " ";
        }
        
        // cout << "\n";
    }
    
    vector<int> passed;
    passed.push_back(E);
    int now = E;
    while (before[now] != -1) {
        passed.push_back(before[now]);
        now = before[now];
    }
    
    cout << DP[E] << "\n";
    while (!passed.empty()) {
        cout << passed.back() << " ";
        passed.pop_back();
    }
    

    return 0;
}