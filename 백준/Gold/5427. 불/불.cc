#include <iostream>
#include <vector>
#include <queue>

#define pll pair<int, int>

using namespace std;

int T, N, M;
vector<pll> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

bool bfs(vector<vector<char> >& board, queue<pll>& que, queue<pll>& next_que, bool is_fire)
{
	while (!que.empty()) {
		pll now = que.front();
		que.pop();
		if (is_fire == false && board[now.first][now.second] == '*') continue;
		
		for (int i=0; i<4; ++i) {
			int nx = now.first + directions[i].first;
			int ny = now.second + directions[i].second;

			if (0 <= nx && nx < N && 0 <= ny && ny < M) {
			    if (board[nx][ny] != '#' && board[nx][ny] != '*') {
    				if (is_fire == true) {
    					board[nx][ny] = '*';
    					next_que.push({nx, ny});
    				}
    				else {
    				    if (board[nx][ny] == '.') {
        				    board[nx][ny] = '@';
        				    next_que.push({nx, ny});
    				    }
    				}
			    }
			}
			else {
			    if (is_fire == false) {
			        return true;
			    }
			}
		}
	}
	
	return false;
}

int get_out(queue<pll>& que, vector<vector<char> >& board, pll start)
{
    queue<pll> sang_que;
    sang_que.push(start);
    int turn = 0;
    while (!sang_que.empty() || !que.empty()) {
        turn++;
        queue<pll> next_que, next_sang_que;
        
        bool is_over = bfs(board, sang_que, next_sang_que, false);
        if (is_over) return turn;
        bfs(board, que, next_que, true);
        
        que = next_que;
        sang_que = next_sang_que;
    }

    return -1;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> T;
	for (int t=0; t<T; ++t) {
		cin >> M >> N;
		vector<vector<char> > board(N, vector<char>(M, ' '));
		queue<pll> que;
		pll start;
		for (int i=0; i<N; ++i) {
			for (int j=0; j<M; ++j) {
				cin >> board[i][j];
				if (board[i][j] == '*') que.push({i, j});
				else if (board[i][j] == '@') start = {i, j};
			}
		}
		
        int result = get_out(que, board, start);
        if (result == -1) {
            cout << "IMPOSSIBLE \n"; 
        }
        else {
            cout << result << "\n";
        }
	}

	return 0;
}