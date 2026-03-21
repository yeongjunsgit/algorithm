#include <iostream>
#include <vector>
#include <map>

#define pll pair<int, int>

using namespace std;

int N, M;
vector<vector<int> > board(101, vector<int>(101, 0));
map<char, string> match_command;
map<char, pll> directions = {{'W', {-1, 0}}, {'A', {0, -1}}, {'S', {1, 0}}, {'D', {0, 1}} };
vector<char> buttons = {'W', 'A', 'S', 'D'};
string commands;
pll now_loca;

void movement(char target)
{
    int nx = now_loca.first + directions[target].first;
    int ny = now_loca.second + directions[target].second;
    if (1 <= nx && nx <= N && 1 <= ny && ny <= N && board[nx][ny] != 1) {
        now_loca = {nx, ny};
    }
    
    return;
}


int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;
    for (int i=1; i<=N; ++i) {
        for (int j=1; j<=N; ++j) {
            cin >> board[i][j];
            if (board[i][j] == 2) now_loca = {i, j};
        }
    }
    
    for (int i=0; i<4; ++i) {
        cin >> commands;
        match_command[buttons[i]] = commands;
    }    
    cin >> commands;
    char now = '-';
    for (char c : commands) {
        // 현재 누른 버튼이 이전에도 누른 버튼이라면 Stay
        if (now == c) {
            if (match_command[now] == "Stay") {
                movement(now);
            }
        }
        // 새롭게 누른 버튼이라면 Down
        else {
            for (char a : buttons) {
                if (a == now || a == c) {
                    if (a == c && match_command[c] == "Down") {
                        movement(c);
                    }
                    if (a == now && match_command[now] == "Up") {
                        movement(now);
                    }
                }
            }
            
            now = c;
        }
    }
    
    cout << now_loca.first << " " << now_loca.second;

    return 0;
}

