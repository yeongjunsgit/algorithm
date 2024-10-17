#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>
#include <cmath>

using namespace std;

int N, T;

int result = 99999999;

struct pair_hash {
    template <class T1, class T2>
    std::size_t operator() (const std::pair<T1, T2>& p) const {
        auto h1 = std::hash<T1>{}(p.first);
        auto h2 = std::hash<T2>{}(p.second);
        return h1 ^ h2;
    }
};

unordered_map<pair<int, int>, int, pair_hash> homes;

struct my_node {
    int x;
    int y;
    int moved;
};

struct Compare {
    bool operator()(const my_node& a, const my_node& b) {
        return a.moved > b.moved;
    }
};

void find_best()
{
    priority_queue<my_node, vector<my_node>, Compare> que;
    que.push({0, 0, 0});
    
    while (!que.empty()) {
        my_node now = que.top();
        que.pop();
        
        if (now.moved > result) {
            continue;
        }
        
        for (int i=-2; i<=2; ++i) {
            for (int j=-2; j<=2; ++j) {
                if (i == 0 && j == 0) {
                    continue;
                }
                int nx = now.x + i;
                int ny = now.y + j;
                if (homes.find({nx, ny}) != homes.end() && nx >= 0 && ny >= 0) {
                    if (ny == T) {
                        if (result > now.moved + 1) {
                            result = now.moved + 1;
                        }
                    }
                    else {
                        if (homes[{nx, ny}] > now.moved + 1 && result > now.moved + 1) {
                            homes[{nx, ny}] = now.moved + 1;
                            que.push({nx, ny, now.moved + 1});
                        }
                    }
                }
            }
        }
    }
    
    if (result == 99999999) {
        cout << -1;
    }
    else {
        cout << result;
    }
    
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> N >> T;
    homes[{0, 0}] = 0;
    int s, e;
    
    for (int i=0; i<N; ++i) {
        cin >> s >> e;
        homes[{s, e}] = 99999999;
    }
    
    find_best();

    return 0;
}
