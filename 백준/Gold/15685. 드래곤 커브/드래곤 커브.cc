#include <iostream>
#include <vector>
#include <map>

using namespace std;

int N;
vector<vector<int> > board(101, vector<int>(101, 0));
map<int, pair<int, int> > directions = { {0, {0, 1}}, {1, {-1, 0}}, {2, {0, -1}}, {3, {1, 0}} };

void Dragon_Curve(int x, int y, int dir, int gen)
{
    board[y][x] = 1;
    vector<int> dir_lis = {dir};
    int ny = y + directions[dir].first;
    int nx = x + directions[dir].second;
    if (0 <= nx && nx < 101 && 0 <= ny && ny < 101) {
        board[ny][nx] = 1;
    }
    int dir_size = 1;
    
    // cout << y << " " << x << "\n";
    // cout << ny << " " << nx << "\n";
    
    for (int i=0; i<gen; ++i) {
        int tmp_size = 0;
        vector<int> tmp_lis;
        for (int j=dir_size- 1; j>=0; --j) {
            int next_dir = (dir_lis[j] + 1) % 4;
            ny += directions[next_dir].first;
            nx += directions[next_dir].second;
            if (0 <= nx && nx < 101 && 0 <= ny && ny < 101) {
                board[ny][nx] = 1;
            }
            tmp_size++;
            tmp_lis.push_back(next_dir);
            // cout << next_dir << " | " <<  ny << " " << nx << "\n";
        }
        dir_size += tmp_size;
        
        for (int k=0; k<tmp_size; ++k) {
            dir_lis.push_back(tmp_lis[k]);
        }
    }
    
    return;
}

void Check_Square()
{
    int result = 0;
    
    for (int i=0; i<100; ++i) {
        for (int j=0; j<100; ++j) {
            if (board[i][j] == 1 && board[i+1][j] == 1 && board[i][j+1] == 1 && board[i+1][j+1] == 1) {
                result++;
            }
        }
    }
    
    cout << result;
    
    return;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    cin >> N;
    
    int x, y, dir, gen;
    for (int i=0; i<N; ++i) {
        cin >> x >> y >> dir >> gen;
        Dragon_Curve(x, y, dir, gen);
    }
    
    Check_Square();

    return 0;
}
