#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<vector<int> > board(500, vector<int>(500, 0) ), see_size(501, vector<int>(501, 0) ), result(500, vector<int>(500, 0) );

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;
    for (int i=0; i<N; ++i) {
        for (int j=0; j<M; ++j) {
            cin >> board[i][j];
        }
    }
    for (int i=0; i<M; ++i) {
        cin >> see_size[N][i];
    }
    for (int i=N-1; i>=0; --i) {
        cin >> see_size[i][M];
    }
    for (int i=N-1; i>=0; --i) {
        for (int j=M-1; j>=0; --j) {
            if (board[i][j] == 1) {
                result[i][j] = min(see_size[N][j], see_size[i][M]);
            }
            // cout << "현재 위치는 {" << i << ", " << j << "} 이고, 결과값은 " << result[i][j] << " 이고, 위치값은 " << see_size[i][j] << "이다\n";
        
        }
    }
    bool is_ok = true;
    for (int i=0; i<N; ++i) {
        if (!is_ok) break;
        bool check = false;
        for (int j=0; j<M; ++j) {
            if (result[i][j] == see_size[i][M]) check = true;
        }
        if (!check) is_ok = false;
    }
    if (is_ok == true) {
        for (int j=0; j<M; ++j) {
            if (!is_ok) break;
            bool check = false;
            for (int i=0; i<N; ++i) {
                if (result[i][j] == see_size[N][j]) check = true;
            }
            if (!check) is_ok = false;
        }
    }
    
    if (!is_ok) {
        cout << -1;
    }
    else {
        for (int i=0; i<N; ++i) {
            for (int j=0; j<M; ++j) {
                if (board[i][j] != 0) {
                    cout << result[i][j] << " ";
                }
                else {
                    cout << 0 << " ";
                }
            }
            cout << "\n";
        }
    }

    return 0;
}
