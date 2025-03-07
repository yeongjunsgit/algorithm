#include <iostream>
#include <vector>
#include <cmath>

#define pll pair<int, int>

using namespace std;

int N, M;
vector<pll> house, chicken;
vector<vector<int> > chicken_dist;
vector<int> now_chicken;
vector<bool> used;
int chicken_cnt, house_cnt;
int result = 2501;

void combi(int idx, int depth)
{
    if (depth == M) {
        int tmp_result = 0;
        for (int a : now_chicken) {
            tmp_result += a;
        }
        if (tmp_result < result) {
            result = tmp_result;
        }
        
        return;
    }
    else {
        for (int i=idx; i<chicken_cnt; ++i) {
            if (used[i] == false) {
                used[i] = true;
                vector<int> tmp_chicken = now_chicken;
                for (int j=0; j<house_cnt; ++j) {
                    now_chicken[j] = min(now_chicken[j], chicken_dist[i][j]);
                }
                combi(i + 1, depth + 1);
                used[i] = false;
                now_chicken = tmp_chicken;
            }
        }
        
        return;
    }
}

void close_down()
{
    chicken_dist.resize(chicken_cnt, vector<int>(house_cnt, 0));
    now_chicken.resize(house_cnt, 2501);
    used.resize(chicken_cnt, false);
    
    for (int i=0; i<chicken_cnt; ++i) {
        for (int j=0; j<house_cnt; ++j) {
            int now_dist = abs(chicken[i].first - house[j].first) + abs(chicken[i].second - house[j].second);
            chicken_dist[i][j] = now_dist;
        }
    }
    
    return;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    cin >> N >> M;
    
    int num;
    for (int i=0; i<N; ++i) {
        for (int j=0; j<N; ++j) {
            cin >> num;
            if (num == 1) {
                house.push_back({i, j});
            }
            else if (num == 2) {
                chicken.push_back({i, j});
            }
        }
    }
    
    chicken_cnt = chicken.size();
    house_cnt = house.size();
    
    close_down();
    
    combi(0, 0);

    cout << result;

    return 0;
}
