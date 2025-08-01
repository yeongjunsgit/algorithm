#include <iostream>
#include <vector>
#include <queue>

#define pll pair<int, int>

using namespace std;

int N, M, K, D, H;

struct line_info
{
    int liner;
    int days;
    int hurry;
};

struct Compare 
{
    bool operator()(const line_info& a, const line_info& b) {
        if (a.days == b.days) {
            if (a.hurry == b.hurry) {
                return a.liner > b.liner;
            }
            return a.hurry < b.hurry;
        }
        return a.days < b.days;
    }
};


vector<queue<line_info> > toilet_line(100000);
vector<int> used(100000, 0);
pll my_loca;

int waiting_my_turn()
{
    int cnt = 0;
    priority_queue<line_info, vector<line_info>, Compare> que;
    for (int i=0; i<M; ++i) {
        que.push(toilet_line[i].front());
        toilet_line[i].pop();
    }
    
    while (!que.empty()) {
        line_info now = que.top();
        que.pop();
        if (now.liner == my_loca.first && used[now.liner] == my_loca.second) {
            return cnt;
        }
        used[now.liner]++;
        cnt++;
        if (!toilet_line[now.liner].empty()) {
            que.push(toilet_line[now.liner].front());
            toilet_line[now.liner].pop();
        }
    }
}


int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M >> K;
    
    for (int i=0; i<N; ++i) {
        cin >> D >> H;
        toilet_line[i % M].push({i % M, D, H});
        if (i == K) my_loca = {i % M, i / M};
    }
    
    cout << waiting_my_turn();

    return 0;
}
