#include <iostream>
#include <iomanip>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
#include <set>

#define pll pair<int, int>

using namespace std;

double R;
int N, D, TX, TY;
vector<pll> towers(1000);
set<int> attack_tower;
vector<vector<int> > graph(1000);
double result = 0;

struct Compare {
    bool operator()(const pll& a, const pll& b) {
        return a.first > b.first;
    }
};


double check_connect(pll a, pll b) {
    return sqrt(pow(a.first - b.first, 2) + pow(b.second - a.second, 2));
}

void check_damage()
{
    
    for (int i=0; i<N; ++i) {
        if (attack_tower.find(i) == attack_tower.end()) {
            priority_queue<pll, vector<pll>, Compare> que;
            que.push({0, i});
            vector<int> visited(N, 99999999);
            visited[i] = 0;
            
            while (!que.empty()) {
                int now_move = que.top().first;
                int now = que.top().second;
                que.pop();
                
                if (attack_tower.find(now) != attack_tower.end()) {
                    double F_move = now_move;
                    result += D / pow(2, F_move);
                    break;
                }
                
                for (int a : graph[now]) {
                    if (visited[a] > now_move + 1) {
                        visited[a] = now_move + 1;
                        que.push({now_move + 1, a});
                    }
                }
            }
        }
    }
    
    return;
}

void print_result()
{
    double tmp = result;
    int is_secondDecimal = static_cast<int>(result * 100) % 10;
    
    if (is_secondDecimal != 0) cout << fixed << setprecision(2) << result;
    else cout << fixed << setprecision(1) << result;
    
    return;
}


int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> R >> D >> TX >> TY;
    int s, e;
    for (int i=0; i<N; ++i) {
        cin >> s >> e;
        towers[i] = {s, e};
        if (check_connect(towers[i], {TX, TY}) <= R) {
            attack_tower.insert(i);
            result += D;
        }
    }
    
    for (int i=0; i<N-1; ++i) {
        for (int j=i+1; j<N; ++j) {
            if (check_connect(towers[i], towers[j]) <= R) {
                graph[i].push_back(j);
                graph[j].push_back(i);
            }
        }
    }
    
    check_damage();
    print_result();

    return 0;
}
