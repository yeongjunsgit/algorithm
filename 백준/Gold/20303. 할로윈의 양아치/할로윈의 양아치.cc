#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M, K;

vector<int> candies, parents;
vector<pair<int, int> > root_candy;

int find_root(int x)
{
    if (parents[x] == x) {
        return parents[x];
    }
    
    return parents[x] = find_root(parents[x]);
}

void union_root(int x, int y)
{
    int rx = find_root(x);
    int ry = find_root(y);
    
    if (rx == ry) {
        return;
    }
    
    if (rx > ry) {
        swap(rx, ry);
    }
    
    parents[ry] = rx;
    root_candy[rx].first += root_candy[ry].first;
    root_candy[rx].second += root_candy[ry].second;
    
    return;
}

void check_best()
{
    vector<pair<int, int> > unions;
    for (int i=1; i<=N; ++i) {
        if (parents[i] == i) {
            unions.push_back(root_candy[i]);
        }
    }
    int T = unions.size();
    
    vector<vector<int> > backpack(T, vector<int>(K+1, 0));
    
    for (int i=0; i<T; ++i) {
        for (int j=0; j<=K; ++j) {
            if (j < unions[i].first) {
                if (i != 0) {
                    backpack[i][j] = backpack[i-1][j];
                }
            }
            else {
                if (i != 0) {
                    backpack[i][j] = max(backpack[i-1][j], backpack[i-1][j - unions[i].first] + unions[i].second);
                }
                else {
                    backpack[i][j] = unions[i].second;
                }
            }
        }
    }
    
    cout << backpack[T-1][K-1];
    
    return;

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> N >> M >> K;
    cin.ignore();
    
    string data;
    int num;
    getline(cin, data);
    istringstream iss(data);
    candies.push_back(0);
    
    while (iss >> num) {
        candies.push_back(num);
    }
    
    parents.resize(N+1, 0);
    root_candy.resize(N+1, {0, 0});
    for (int i=1; i<=N; ++i) {
        parents[i] = i;
        root_candy[i] = {1, candies[i]};
    }
    
    int s, e;
    
    for (int i=0; i<M; ++i) {
        cin >> s >> e;
        if (s > e) {
            swap(s, e);
        }
        union_root(s, e);
        
    }
    
    check_best();

    return 0;
}
