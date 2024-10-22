#include <iostream>
#include <sstream>
#include <vector>
#include <queue>
#include <cmath>
#include <string>

using namespace std;

int N, M, H, K;
vector<pair<int, int> > mint_choco_milk;
pair<int, int> my_home;
int result = 0;
vector<vector<int> > graph;
vector<bool> visited;

struct my_node {
    int dist;
    int loca;
    string passed;
};

struct Compare {
    bool operator()(const my_node& a, const my_node& b) {
        return a.dist > b.dist;
    }
};

void dfs(int now, int HP, int eating)
{
    if (result == K - 1) {
        return;
    }
    
    if (eating > result) {
        int go_home = HP - graph[now][K-1];
        if (go_home >= 0) {
            result = eating;
        }
    }
    
    for (int i=0; i<K-1; ++i) {
        int tmp_dist = HP - graph[now][i];
        if (tmp_dist >= 0 && visited[i] == false) {
            visited[i] = true;
            dfs(i, tmp_dist + H, eating + 1);
            visited[i] = false;
        }
    }
    
    return;
}

void eat_mincho()
{
    mint_choco_milk.push_back(my_home);
    K = mint_choco_milk.size();
    graph.resize(K, vector<int>(K, 0));
    visited.resize(K, false);
    
    for (int i=0; i<K-1; ++i) {
        pair<int, int> base = mint_choco_milk[i];
        for (int j=i+1; j<K; ++j) {
            pair<int, int> target = mint_choco_milk[j];
            int now_dist = abs(base.first - target.first) + abs(base.second - target.second); 
            
            graph[i][j] = now_dist;
            graph[j][i] = now_dist;
        }
    }
    
    dfs(K - 1, M, 0);
    
    cout << result;
    
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> N >> M >> H;
    cin.ignore();
    
    string data;
    int num;
    
    for (int i=0; i<N; ++i) {
        getline(cin, data);
        istringstream iss(data);
        int idx = 0;
        
        while (iss >> num) {
            if (num == 1) {
                my_home = {i, idx};
            }
            else if (num == 2) {
                mint_choco_milk.push_back({i, idx});
            }
            idx++;
        }
    }
    
    eat_mincho();
    
    return 0;
}
