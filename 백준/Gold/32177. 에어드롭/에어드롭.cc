#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>

#define pll pair<int, int>
#define pld pair<int, double>

using namespace std;

int N, K, T;
vector<int> versions(3001), take_picture(3001);
vector<pll> locas(3001);
vector<int> can_take;


double get_dist(int a, int b)
{
    return sqrt((locas[a].first - locas[b].first) * (locas[a].first - locas[b].first) + (locas[a].second - locas[b].second) * (locas[a].second - locas[b].second) );
}



void bfs()
{
    queue<int> que;
    que.push(0);
    vector<double> visited(3001, 0);
    visited[0] = 1;
    
    while (!que.empty()) {
        int now_idx = que.front();
        que.pop();
        
        for (int i=1; i<=N; ++i) {
            if (i == now_idx || visited[i] == 1) continue;
            double tmp = get_dist(now_idx, i);
            if (tmp <= K && abs(versions[now_idx] - versions[i]) <= T) {
                que.push(i);
                visited[i] = 1;
                if (take_picture[i] == 1) can_take.push_back(i);
            }
        }
    }
    
    return;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int x, y, v, p;
    cin >> N >> K >> T >> x >> y >> v;
    locas[0] = {x, y};
    versions[0] = v;
    for (int i=1; i<=N; ++i) {
        cin >> x >> y >> v >> p;
        locas[i] = {x, y};
        versions[i] = v;
        take_picture[i] = p;
    }
    
    bfs();
    
    sort(can_take.begin(), can_take.end(), less<int>());
    
    if (can_take.size() == 0) {
        cout << 0;
    }
    else {
        for (int a : can_take) cout << a << " ";
    }
    
    return 0;
}

