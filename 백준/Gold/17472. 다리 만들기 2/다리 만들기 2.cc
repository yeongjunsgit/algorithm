#include <iostream>
#include <sstream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N, M;

int color = 2;
vector<int> parents;
vector<vector<int> > board, graph;
vector<pair<int, int> > direction = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
vector<pair<int, int> > islands(8, {0, 0});

struct my_info
{
    int x;
    int y;
    int dir;
    int power;
};

struct Compare
{
    bool operator()(const my_info& a, my_info& b) {
        return a.dir > b.dir;
    }
};

void coloring(int x, int y)
{
    queue<pair<int, int> > que;
    que.push({x, y});
    board[x][y] = color;
    islands[color] = {x, y};
    
    while (!que.empty()) {
        pair<int, int> now = que.front();
        que.pop();
        
        for (int i=0; i<4; ++i) {
            int nx = now.first + direction[i].first;
            int ny = now.second + direction[i].second;
            
            if (0 <= nx && nx < N && 0 <= ny && ny < M && board[nx][ny] == 1) {
                que.push({nx, ny});
                board[nx][ny] = color;
            }
        }
    }
    
    return;
    
}

void find_island()
{
    
    for (int i=0; i<N; ++i) {
        for (int j=0; j<M; ++j) {
            if (board[i][j] == 1) {
                coloring(i, j);
                color++;
            }
        }
    }
    
    return;
}

void make_graph()
{
    for (int i=2; i<color; ++i) {
        queue<my_info> que;
        que.push({islands[i].first, islands[i].second, -1, 0});
        vector<vector<int> > visited(N, vector<int>(M, 101));
        visited[islands[i].first][islands[i].second] = 0;
        
        while (!que.empty()) {
            my_info now = que.front();
            que.pop();
            for (int j=0; j<4; ++j) {
                int nx = now.x + direction[j].first;
                int ny = now.y + direction[j].second;
                
                if (0 <= nx && nx < N && 0 <= ny && ny < M) {
                    if (board[nx][ny] == i && visited[nx][ny] == 101) {
                        visited[nx][ny] = 0;
                        que.push({nx, ny, -1, 0});
                    }
                    else if (board[nx][ny] == 0) {
                        if (now.dir != -1 && now.dir != j) {
                            continue;
                        }
                        que.push({nx, ny, j, now.power + 1});
                    }
                    else {
                        if (now.dir != j) {
                            continue;
                        }
                        visited[nx][ny] = now.power;
                        if (visited[nx][ny] != 1 && graph[i][board[nx][ny]] > visited[nx][ny]) {
                            graph[i][board[nx][ny]] = visited[nx][ny];
                            graph[board[nx][ny]][i] = visited[nx][ny];
                        }
                    }
                }
            }
        }
    }
    
    return;
}

int find_root(int x)
{
    if (parents[x] == x) {
        return x;
    }
    return parents[x] = find_root(parents[x]);
}

void make_bridge()
{
    priority_queue<my_info, vector<my_info>, Compare> que;
    for (int i=2; i<color; ++i) {
        for (int j=i+1; j<color; ++j) {
            if (graph[i][j] != 101) {
                que.push({i, j, graph[i][j], 0});
            }
        }
    }
    
    parents.resize(color, 0);
    for (int i=2; i<color; ++i) {
        parents[i] = i;
    }
    
    int result = 0;
    
    while (!que.empty()) {
        my_info now = que.top();
        que.pop();
        
        int rx = find_root(now.x);
        int ry = find_root(now.y);
        
        if (rx == ry) {
            continue;
        }
        if (rx > ry) {
            swap(rx, ry);
        }
        parents[ry] = rx;
        result += now.dir;
    }
    
    
    bool is_connect = true;
    for (int i=2; i<color; ++i) {
        find_root(i);
        if (parents[i] != 2) {
            is_connect = false;
            break;
        }
    }
    
    if (is_connect == true) {
        cout << result;
    }
    else {
        cout << -1;
    }
    
    return;
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> N >> M;
    cin.ignore();
    graph.resize(8, vector<int>(8, 101));
    string data;
    int num;
    for (int i=0; i<N; ++i) {
        getline(cin, data);
        vector<int> one_line;
        istringstream iss(data);
        while (iss >> num) {
            one_line.push_back(num);
        }
        board.push_back(one_line);
    }
    
    find_island();
    make_graph();
    make_bridge();

    return 0;
}
