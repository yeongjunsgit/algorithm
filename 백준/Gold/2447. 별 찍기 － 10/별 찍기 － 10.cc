#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int N;
vector<vector<char> > board;

void draw_star(int depth, int x, int y)
{
    if (depth == 1) {
        for (int i=0; i<3; ++i) {
            for (int j=0; j<3; ++j) {
                if (i == 1 && j == 1) {
                    continue;
                }
                board[i+x][j+y] = '*';
            }
        }
        return;
    }
    else {
        int next_powpow = pow(3, depth - 1);
        for (int i=0; i<3; ++i) {
            for (int j=0; j<3; ++j) {
                if (i == 1 && j == 1) {
                    continue;
                }
                draw_star(depth - 1, x + (next_powpow * i), y + (next_powpow * j));
            }
        }
        return;
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    board.resize(N, vector<char>(N, ' '));
    
    int powpow = 0;
    int tmp = N;
    while (tmp != 1) {
        tmp /= 3;
        powpow++;
    }
    
    draw_star(powpow, 0, 0);
    
    for (int i=0; i<N; ++i) {
        for (int j=0; j<N; ++j) {
            cout << board[i][j];
        }
        cout << "\n";
    }

    return 0;
}