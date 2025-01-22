#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<vector<char> > board;
bool is_pass[27] = {false};
int result = 1;

vector<pair<int, int> > direction = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

void dfs(int x, int y, int now)
{
    if (now > result) {
        result = now;
    }
    
    for (int i=0; i<4; ++i) {
        int nx = x + direction[i].first;
        int ny = y + direction[i].second;
        
        if (0 <= nx && nx < N && 0 <= ny && ny < M && is_pass[board[nx][ny] - 'A'] == false) {
            is_pass[board[nx][ny] - 'A'] = true;
            dfs(nx, ny, now + 1);
            is_pass[board[nx][ny] - 'A'] = false;
        }
    }
    
    return;
}

int main()
{  
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> N >> M;
    
    string data;
    for (int i=0; i<N; ++i) {
        cin >> data;
        vector<char> one_line;
        for (char c : data) {
            one_line.push_back(c);
        }
        board.push_back(one_line);
    }
    
    is_pass[board[0][0] - 'A'] = true;
    dfs(0, 0, 1);
    
    cout << result;

    return 0;
}
