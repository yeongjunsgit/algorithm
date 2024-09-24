#include <iostream>
#include <sstream>
#include <vector>
#include <queue>

using namespace std;

struct Compare {
    bool operator()(const pair<int, pair<int, int> >& a, const pair<int, pair<int, int> >& b) {
        return a.first > b.first;
    }
};

int N;
vector<vector<int> > board;
vector<vector<int> > visited;
vector<pair<int, int> > direction = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
priority_queue<pair<int, pair<int, int> >, vector<pair<int, pair<int, int> > >, Compare> ququque;
int result = 0;

void check_loca()
{
    while(!ququque.empty()) {
        pair<int, pair<int, int> > now = ququque.top();
        ququque.pop();
        
        for (int i=0; i<4; ++i) {
            int nx = now.second.first + direction[i].first;
            int ny = now.second.second + direction[i].second;
            
            if (0 <= nx && nx < N && 0 <= ny && ny < N) {
                if (board[nx][ny] < board[now.second.first][now.second.second]) {
                    visited[now.second.first][now.second.second] = max(visited[nx][ny] + 1, visited[now.second.first][now.second.second]);
                }
            }
            if (result < visited[now.second.first][now.second.second]) {
                result = visited[now.second.first][now.second.second];
            }
        }
    }
    
    return;
}

int main()
{
    cin >> N;
    cin.ignore();
    
    visited.resize(N, vector<int>(N, 1));
    string data;
    int num;
    
    for (int i=0; i<N; ++i) {
        vector<int> one_line;
        getline(cin, data);
        istringstream iss(data);
        int idx = 0;
        
        while (iss >> num) {
            one_line.push_back(num);
            ququque.push({num, {i, idx}});
            idx++;
        }
        
        board.push_back(one_line);
        
    }

    check_loca();
    
    cout << result;

    return 0;
}
