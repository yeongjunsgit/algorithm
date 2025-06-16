#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

#define pll pair<int, int>

using namespace std;

int N, M;
map<int, long long> loca_score;
vector<pll> my_nodes(200001);

long long get_best()
{
    long long result = 0;
    long long tmp = 0;

    for (auto p : loca_score) {
        tmp += p.second;
        result = max(result, tmp);
    }
    
    return result;
    
}


int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;
    
    for (int i=0; i<N; ++i) {
        cin >> my_nodes[i].first >> my_nodes[i].second;
    }
    int s, e;
    long long dist;
    for (int i=0; i<M; ++i) {
        cin >> s >> e >> dist;
        int s_y = my_nodes[s - 1].second;
        int e_y = my_nodes[e - 1].second;
        
        if (s_y > e_y) swap(s_y, e_y);
        loca_score[s_y] += dist;
        loca_score[e_y + 1] -= dist;
        
    }
    
    cout << get_best();

    return 0;
}
