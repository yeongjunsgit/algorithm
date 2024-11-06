#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, K;

vector<vector<char> > road_jack;

long long real_result = 200000000000001;

void hit_the_road(int x, int y)
{
    if (road_jack[x][y] != '.') {
        return;
    }

    int road_size = N * min(K, 3);
    queue<pair<int, int> > que;
    que.push({ x, y });
    vector<vector<long long> > visited(2, vector<long long>(road_size + 1, 600001));
    visited[x][y] = 0;

    while (!que.empty()) {
        pair<int, int> now = que.front();
        que.pop();

        if (now.second + 1 <= road_size && visited[now.first][now.second + 1] > visited[now.first][now.second] + 1 && road_jack[now.first][(now.second + 1) % N] == '.') {
            if (now.second + 1 < road_size) {
                que.push({ now.first, now.second + 1 });
                visited[now.first][now.second + 1] = visited[now.first][now.second] + 1;
            }
            else {
                visited[now.first][now.second + 1] = visited[now.first][now.second] + 1;
            }
        }

        if (now.first + 1 == 1 && visited[now.first + 1][now.second] > visited[now.first][now.second] + 1 && road_jack[now.first + 1][(now.second) % N] == '.') {
            que.push({ now.first + 1, now.second });
            visited[now.first + 1][now.second] = visited[now.first][now.second] + 1;
        }

        if (now.first - 1 == 0 && visited[now.first - 1][now.second] > visited[now.first][now.second] + 1 && road_jack[now.first - 1][(now.second) % N] == '.') {
            que.push({ now.first - 1, now.second });
            visited[now.first - 1][now.second] = visited[now.first][now.second] + 1;
        }
    }

    long long result = 600001;

    if (K == 1) {
        result = min(visited[0][N - 1], visited[1][N - 1]);
    }
    else {
        if (road_jack[0][N] == '#' && road_jack[1][N] == '#') {
            result = 600001;
        }
        else if (road_jack[0][N] == '#') {
            result = visited[1][N - 1];
        }
        else if (road_jack[1][N] == '#') {
            result = visited[0][N - 1];
        }
        else {
            result = min(visited[0][N - 1], visited[1][N - 1]);
        }

        // cout << result << "\n";
        // cout << visited[0][N] << " " << visited[1][N] << " " << visited[0][2 * N] << " " << visited[1][2 * N] << " " << visited[0][road_size - 1] << " " << visited[1][road_size - 1] << "\n";

        if (result != 600001) {
            if (K - 2 >= 0) {
                result += (min(visited[0][N * 2], visited[1][N * 2]) - min(visited[0][N], visited[1][N])) * (K - 2);
                // cout << (min(visited[0][N * 2], visited[1][N * 2]) - min(visited[0][N], visited[1][N])) << " " << (min(visited[0][N * 2], visited[1][N * 2]) - min(visited[0][N], visited[1][N])) * (K - 2) << "\n";
            }
            // cout << min(visited[0][road_size - 1], visited[1][road_size - 1]) << " " << min(visited[0][road_size - N], visited[1][road_size - N]) << "\n";
            result += (min(visited[0][road_size - 1], visited[1][road_size - 1]) - min(visited[0][road_size - N], visited[1][road_size - N])) + 1;
            // cout << (min(visited[0][road_size - 1], visited[1][road_size - 1]) - min(visited[0][road_size - N], visited[1][road_size - N])) + 1 << "\n";
        }
    }

    if (result != 600001) {
        // cout << result << "\n";
        if (real_result > result) {
            real_result = result;
        }
    }

    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> K;

    string data;
    for (int i = 0; i < 2; ++i) {
        cin >> data;
        vector<char> one_line;
        for (char c : data) {
            one_line.push_back(c);
        }
        one_line.push_back(one_line.front());
        road_jack.push_back(one_line);
    }

    hit_the_road(0, 0);
    hit_the_road(1, 0);

    if (real_result == 200000000000001) {
        cout << -1;
    }
    else {
        cout << real_result;
    }

    return 0;
}
