#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

int N, M;

int result = 0;

void check_bar(vector<vector<int> >& board, pair<int, int> now)
{
    int base = board[now.first][now.second];
    if (now.second + 3 < M) {
        int tmp = base;
        for (int i=1; i<4; ++i) {
            tmp += board[now.first][now.second + i];
        }
        
        if (result < tmp) {
            result = tmp;
        }
    }
    
    if (now.first + 3 < N) {
        int tmp = base;
        for (int i=1; i<4; ++i) {
            tmp += board[now.first + i][now.second];
        }
        
        if (result < tmp) {
            result = tmp;
        }
    }
}

void check_box(vector<vector<int> >& board, pair<int, int> now)
{
    if (now.first + 1 < N && now.second + 1 < M) {
        int tmp = board[now.first][now.second] + board[now.first][now.second + 1] + board[now.first + 1][now.second] + board[now.first + 1][now.second + 1];
    
        if (result < tmp) {
            result = tmp;
        }
    }
}

void check_L(vector<vector<int> >& board, pair<int, int> now)
{
    int base = board[now.first][now.second];
    
    if (now.first + 2 < N) {
        int tmp = base + board[now.first + 1][now.second] + board[now.first + 2][now.second];
        if (now.second - 1 >= 0) {
            int tmp_two = tmp + board[now.first + 2][now.second - 1];
            if (result < tmp_two) {
                result = tmp_two;
            }
        }
        
        if (now.second + 1 < M) {
            int tmp_two = tmp + board[now.first + 2][now.second + 1];
            if (result < tmp_two) {
                result = tmp_two;
            }
        }
    }
    
    if (now.first - 2 >= 0) {
        int tmp = base + board[now.first - 1][now.second] + board[now.first - 2][now.second];
        if (now.second - 1 >= 0) {
            int tmp_two = tmp + board[now.first - 2][now.second - 1];
            if (result < tmp_two) {
                result = tmp_two;
            }
        }
        
        if (now.second + 1 < M) {
            int tmp_two = tmp + board[now.first - 2][now.second + 1];
            if (result < tmp_two) {
                result = tmp_two;
            }
        }
    }
    
    if (now.second + 2 < M) {
        int tmp = base + board[now.first][now.second + 1] + board[now.first][now.second + 2];
        if (now.first - 1 >= 0) {
            int tmp_two = tmp + board[now.first - 1][now.second + 2];
            if (result < tmp_two) {
                result = tmp_two;
            }
        }
        if (now.first + 1 < N) {
            int tmp_two = tmp + board[now.first + 1][now.second + 2];
            if (result < tmp_two) {
                result = tmp_two;
            }
        }
    }
    
    if (now.second - 2 >= 0) {
        int tmp = base + board[now.first][now.second - 1] + board[now.first][now.second - 2];
        if (now.first - 1 >= 0) {
            int tmp_two = tmp + board[now.first - 1][now.second - 2];
            if (result < tmp_two) {
                result = tmp_two;
            }
        }
        if (now.first + 1 < N) {
            int tmp_two = tmp + board[now.first + 1][now.second - 2];
            if (result < tmp_two) {
                result = tmp_two;
            }
        }
    }
    
    
}

void check_twist(vector<vector<int> >& board, pair<int, int> now)
{
    int base = board[now.first][now.second];
    
    if (now.first + 2 < N) {
        int check = base + board[now.first + 1][now.second];
        if (now.second - 1 >= 0) {
            int tmp = check + board[now.first + 1][now.second - 1] + board[now.first + 2][now.second - 1];
            if (result < tmp) {
                result = tmp;
            }
        }
        if (now.second + 1 < M) {
            int tmp = check + board[now.first + 1][now.second + 1] + board[now.first + 2][now.second + 1];
            if (result < tmp) {
                result = tmp;
            }
        }
        
    }
    
    if (now.second + 2 < M) {
        int check = base + board[now.first][now.second + 1];
        if (now.first - 1 >= 0) {
            int tmp = check + board[now.first - 1][now.second + 1] + board[now.first - 1][now.second + 2];
            if (result < tmp) {
                result = tmp;
            }
        }
        if (now.first + 1 < N) {
            int tmp = check + board[now.first + 1][now.second + 1] + board[now.first + 1][now.second + 2];
            if (result < tmp) {
                result = tmp;
            }
        }
    }
    
    
}

void check_spike(vector<vector<int> >& board, pair<int, int> now)
{
    int base = board[now.first][now.second];
    
    // ㅗ
    if (now.first - 1 >= 0 && now.second - 1 >= 0 && now.second + 1 < M) {
        int tmp = base + board[now.first - 1][now.second] + board[now.first][now.second + 1] + board[now.first][now.second - 1];
        if (result < tmp) {
            result = tmp;
        }
    }
    // ㅜ
    if (now.first + 1 < N && now.second - 1 >= 0 && now.second + 1 < M) {
        int tmp = base + board[now.first + 1][now.second] + board[now.first][now.second + 1] + board[now.first][now.second - 1];
        if (result < tmp) {
            result = tmp;
        }
    }
    // ㅏ
    if (now.first + 1 < N && now.first - 1 >= 0 && now.second + 1 < M) {
        int tmp = base + board[now.first + 1][now.second] + board[now.first - 1][now.second] + board[now.first][now.second + 1];
        if (result < tmp) {
            result = tmp;
        }
    }
    // ㅓ
    if (now.first + 1 < N && now.first - 1 >= 0 && now.second - 1 >= 0) {
        int tmp = base + board[now.first + 1][now.second] + board[now.first - 1][now.second] + board[now.first][now.second - 1];
        if (result < tmp) {
            result = tmp;
        }
    }
    
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> N >> M;
    cin.ignore();
    
    vector<vector<int> > board;
    int num;
    string data;
    
    for (int i=0; i<N; ++i) {
        getline(cin, data);
        vector<int> one_line;
        istringstream iss(data);
        
        while (iss >> num) {
            one_line.push_back(num);
        }
        
        board.push_back(one_line);
        
    }
    
    for (int i=0; i<N; ++i) {
        for (int j=0; j<M; ++j) {
            check_bar(board, {i, j});
            check_box(board, {i, j});
            check_L(board, {i, j});
            check_twist(board, {i, j});
            check_spike(board, {i, j});
        }
    }
    
    cout << result;

    return 0;
}
