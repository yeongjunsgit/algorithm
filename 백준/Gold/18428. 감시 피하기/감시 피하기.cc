#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N;
int in_sight = 0;
bool is_ok = false;
vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

bool teachers_sight(vector<vector<char>>& graph, int x, int y) {
    for (int i=0; i<4; ++i) {
        int nx = x;
        int ny = y;
        while (true) {
            nx += directions[i].first;
            ny += directions[i].second;
            
            if (0 <= nx && nx < N && 0 <= ny && ny < N) {
                if (graph[nx][ny] == 'O') {
                    break;
                }
                else if (graph[nx][ny] == 'S') {
                    return false;
                }
            }
            else {
                break;
            }
        }
    }
    
    return true;
}


void check_combination(vector<vector<char>>& graph, vector<pair<int, int>>& wall_place, vector<pair<int, int>>& teachers, int idx, int before) {
    if (idx == 3) {
        for (auto t : teachers) {
            bool now_check = teachers_sight(graph, t.first, t.second);
            if (now_check == false) {
                return;
            }
        }
        is_ok = true;
        return;
    }
    
    if (is_ok == true) {
        return;
    }
    
    for (int i=before; i<wall_place.size(); ++i) {
        pair<int, int> p = wall_place[i];
        graph[p.first][p.second] = 'O';
        check_combination(graph, wall_place, teachers, idx + 1, i+1);
        graph[p.first][p.second] = 'X';
    }
    return;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N;
	vector<vector<char>> graph;
	char one;
	vector<pair<int, int>> wall_place;
	vector<pair<int, int>> teachers;
	

	for (int i=0; i<N; ++i) {
		vector<char> one_line;
		for (int j=0; j<N; ++j) {
			cin >> one;
			one_line.push_back(one);

			if (one == 'X') {
				wall_place.push_back({i, j});
			}
			else if (one == 'T') {
				teachers.push_back({i, j});
			}
			
		}
		graph.push_back(one_line);
	}

	
	check_combination(graph, wall_place, teachers, 0, 0);

    
    if (is_ok == true) {
        cout << "YES";
    }
    
    else {
        cout << "NO";
    }


	return 0;
}
