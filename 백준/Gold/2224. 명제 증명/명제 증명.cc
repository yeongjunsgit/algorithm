#include <iostream>
#include <vector>

using namespace std;

int N;
vector<vector<int> > board(55, vector<int>(55, 0));

int make_idx(char a)
{
    if ('A' <= a && a <= 'Z') {
        return a - 65;
    }
    else {
        return a - 71;
    }
}

char make_char(int a) {
    if (0 <= a && a <= 25) {
        return a + 65;
    }
    else {
        return a + 71;
    }
}


void find_relation()
{
    int cnt = 0;
    for (int k=0; k<52; ++k) {
        for (int i=0; i<52; ++i) {
            for (int j=0; j<52; ++j) {
                if (i == j) continue;
                if (board[i][j] == 0) {
                    if (board[i][k] == 1 && board[k][j] == 1) board[i][j] = 1;
                }
            }
        }
    }
    for (int i=0; i<52; ++i) {
        for (int j=0; j<52; ++j) {
            if (i != j && board[i][j] == 1) {
                cnt++;
            }
        }
    }
    
    cout << cnt << "\n";
    
    for (int i=0; i<52; ++i) {
        for (int j=0; j<52; ++j) {
            if (i != j && board[i][j] == 1) {
                cout << make_char(i) << " => " << make_char(j) << "\n";
            }
        }
    }
    
    return;

}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    char s, e;
    for (int i=0; i<N; ++i) {
        cin >> s >> e >> e >> e;
        int s_idx = make_idx(s);
        int e_idx = make_idx(e);
        board[s_idx][e_idx] = 1;
        
    }
    
    find_relation();

    return 0;
}
