#include <iostream>
#include <vector>

using namespace std;

int N;
vector<vector<char> > board(2000, vector<char>(2000));
vector<vector<int> > visited(2000, vector<int>(2000, 0));

vector<pair<int, int> > directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

void cant_boom()
{
    for (int i=0; i<N; ++i) {
        for (int j=0; j<N; ++j) {
            if (board[i][j] == 'O') {
                for (int k=0; k<4; ++k) {
                    int nx = i, ny = j;
                    while (true) {
                        nx += directions[k].first;
                        ny += directions[k].second;
                        if (0 <= nx && nx < N && 0 <= ny && ny < N && board[nx][ny] == '.') {
                            visited[nx][ny] = -1;
                        }
                        else break;
                    }
                }
            }
        }
    }
    
    for (int i=0; i<N; ++i) {
        for (int j=0; j<N; ++j) {
            if (board[i][j] == '.' && visited[i][j] != -1) {
                cout << 'B';
            }
            else {
                cout << board[i][j];
            }
        }
        cout << "\n";
    }
    
    return;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    for (int i=0; i<N; ++i) {
        for (int j=0; j<N; ++j) {
            cin >> board[i][j];
        }
    }

    cant_boom();
    
    return 0;
}
