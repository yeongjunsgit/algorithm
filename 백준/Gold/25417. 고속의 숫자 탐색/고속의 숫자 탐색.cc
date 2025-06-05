#include <iostream>
#include <vector>
#include <queue>

#define pll pair<int, int>

using namespace std;

int s, e;
int board[5][5];
vector<pll> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};


struct Compare
{
	bool operator()(const pair<int, pll>& a, const pair<int, pll>& b) {
		return a.first > b.first;
	}
};


int let_s_move()
{
	vector<vector<int> > visited(5, vector<int>(5, 999999));
	priority_queue<pair<int, pll>, vector<pair<int, pll> >, Compare> que;
	que.push({0, {s, e}});
    visited[s][e] = 0;

	while (!que.empty()) {
		int now_turn = que.top().first;
		pll now = que.top().second;
		que.pop();
		if (board[now.first][now.second] == 1) return now_turn;

		for (int i=0; i<4; ++i) {
			int nx = now.first + directions[i].first;
			int ny = now.second + directions[i].second;

			if (0 <= nx && nx < 5 && 0 <= ny && ny < 5 && visited[nx][ny] > now_turn + 1 && board[nx][ny] != -1) {
				visited[nx][ny] = now_turn + 1;
				que.push({now_turn + 1, {nx, ny}});
			}
            if (0 <= nx && nx < 5 && 0 <= ny && ny < 5 && board[nx][ny] != -1 && board[nx][ny] != 7) {
				while (true) {
					if (0 <= nx + directions[i].first && nx + directions[i].first < 5 && 0 <= ny + directions[i].second && ny + directions[i].second < 5 && board[nx + directions[i].first][ny + directions[i].second] != -1) {
						nx += directions[i].first;
						ny += directions[i].second;
						if (board[nx][ny] == 7) {
							break;
						}
					}
					else break;
				}

				if (visited[nx][ny] > now_turn + 1) {
				    visited[nx][ny] = now_turn + 1;
					que.push({now_turn + 1, {nx, ny}});
				}
            }
		}
	}

	return -1;

}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int i=0; i<5; ++i) {
		for (int j=0; j<5; ++j) {
			cin >> board[i][j];
		}
	}
	cin >> s >> e;

	cout << let_s_move();

	return 0;
}
