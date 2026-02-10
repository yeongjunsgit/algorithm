#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>


#define pll pair<int, int>

using namespace std;

struct Compare
{
    bool operator()(const pair<int, pll>& a, const pair<int, pll>& b) {
        return a.first < b.first;
    }
};


int N, W, H, x, y;
unordered_map<string, int> red_stone = {{"redstone_dust", 1}, {"redstone_block", 2}, {"redstone_lamp", 3}};
vector<vector<int> > board(50, vector<int>(50, 0)), visited(50, vector<int>(50, 0));
vector<vector<pll> > kind_loca(4);
vector<pll> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
priority_queue<pair<int, pll>, vector<pair<int, pll> >, Compare> que;


void turn_on_light()
{
    while (!que.empty()) {
        int now_electric = que.top().first;
        pll now_loca = que.top().second;
        que.pop();
        
        if (visited[now_loca.first][now_loca.second] > now_electric || visited[now_loca.first][now_loca.second] == 1) continue;
        
        for (int i=0; i<4; ++i) {
            int nx = now_loca.first + directions[i].first;
            int ny = now_loca.second + directions[i].second;
            if (0 <= nx && nx < H && 0 <= ny && ny < W && (board[nx][ny] == 1 || board[nx][ny] == 3) && visited[nx][ny] < now_electric - 1) {
                visited[nx][ny] = now_electric - 1;
                if (board[nx][ny] == 1) {
                    que.push({visited[nx][ny], {nx, ny}});
                }
            }
            
        }
        
    }
    
    return;
    
}


int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> W >> H >> N;
    string red_kind;
    for (int i=0; i<N; ++i) {
        cin >> red_kind >> y >> x;
        board[x][y] = red_stone[red_kind];
        kind_loca[red_stone[red_kind]].push_back({x, y});
    }
    
    for (pll p : kind_loca[2]) {
        visited[p.first][p.second] = 15;
        for (int i=0; i<4; ++i) {
            int nx = p.first + directions[i].first;
            int ny = p.second + directions[i].second;
            
            if (0 <= nx && nx < H && 0 <= ny && ny < W && (board[nx][ny] == 1 || board[nx][ny] == 3)) {
                visited[nx][ny] = 15;
                if (board[nx][ny] == 1) {
                    que.push({15, {nx, ny}});
                }
            }
        }
    }
    turn_on_light();
    bool all_light = true;
    for (pll p : kind_loca[3]) {
        if (visited[p.first][p.second] == 0) {
            all_light = false;
            break;
        } 
    }
    
    if (all_light) cout << "success";
    else cout << "failed";

    return 0;
}