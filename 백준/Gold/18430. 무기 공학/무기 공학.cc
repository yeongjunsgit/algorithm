#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

int N, M;
vector<vector<int> > board;
vector<vector<int> > visited;
int result = 0;
int now_power = 0;
vector<pair<pair<int, int>, pair<int, int> > > bomaerang_loca = {{{1, 0}, {0, -1}}, {{-1, 0}, {0, -1}}, {{-1, 0}, {0, 1}}, {{1, 0}, {0, 1}}};

void make_bomaerang(int i, int j)
{
    if (i == N) {
        return;
    }
    
    int next_i = i;
    int next_j = j + 1;
    if (next_j == M) {
        next_i++;
        next_j = 0;
    }
    
    if (visited[i][j] == 0) {
        for (int k=0; k<4; ++k) {
            int fnx = i + bomaerang_loca[k].first.first;
            int fny = j + bomaerang_loca[k].first.second;
            int snx = i + bomaerang_loca[k].second.first;
            int sny = j + bomaerang_loca[k].second.second;
            
            if (0 <= fnx && fnx < N && 0 <= fny && fny < M && 0 <= snx && snx < N && 0 <= sny && sny < M) {
                if (visited[fnx][fny] == 0 && visited[snx][sny] == 0) {
                    visited[i][j] = 1;
                    visited[fnx][fny] = 1;
                    visited[snx][sny] = 1;
                    int tmp_power = (board[i][j] * 2) + board[fnx][fny] + board[snx][sny];
                    now_power += tmp_power;
                    if (result < now_power) {
                        result = now_power;
                    }
                    
                    make_bomaerang(next_i, next_j);
                    visited[i][j] = 0;
                    visited[fnx][fny] = 0;
                    visited[snx][sny] = 0;
                    
                    now_power -= tmp_power;
                    
                }
            }
        }
    }
    
    make_bomaerang(next_i, next_j);

    
    return;
}

int main()
{
    cin >> N >> M;
    cin.ignore();

    visited.resize(N, vector<int>(M, 0));
    
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
    
    make_bomaerang(0, 0);
    
    cout << result;

    return 0;
}
