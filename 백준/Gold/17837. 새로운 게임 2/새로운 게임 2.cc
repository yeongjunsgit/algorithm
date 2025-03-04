#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>

#define pll pair<int, int>

using namespace std;

int N, K;
vector<vector<int> > board;
vector<vector<vector<int> > > stack_board;

vector<pll> direction = {{0, 0}, {0, 1}, {0, -1}, {-1, 0}, {1, 0}};
unordered_map<int, pll> my_pawns;
unordered_map<int, int> pawn_dir, pawn_idx;
map<vector<pair<int, pll> >, int> previous;
int play_time = 1;

void change_dir(int a)
{
    if (pawn_dir[a] == 1) {
        pawn_dir[a] = 2;
    }
    else if (pawn_dir[a] == 2) {
        pawn_dir[a] = 1;
    }
    else if (pawn_dir[a] == 3) {
        pawn_dir[a] = 4;
    }
    else if (pawn_dir[a] == 4) {
        pawn_dir[a] = 3;
    }
    
    return;
}

int move_pawn(int loca, pll now_pawns, int nx, int ny, bool is_blue, vector<int>& up_on_the_pawn)
{
    if (0 <= nx && nx < N && 0 <= ny && ny < N) {
        if (board[nx][ny] == 0) {
            int now_size = up_on_the_pawn.size();
            for (int a=now_size - 1; a>=0; --a) {
                my_pawns[up_on_the_pawn[a]] = {nx, ny};
                stack_board[nx][ny].push_back(up_on_the_pawn[a]);
                pawn_idx[up_on_the_pawn[a]] = stack_board[nx][ny].size() - 1;
                if (stack_board[nx][ny].size() >= 4) {
                    return play_time;
                }
            }
        }
        else if (board[nx][ny] == 1) {
            for (int a : up_on_the_pawn) {
                my_pawns[a] = {nx, ny};
                stack_board[nx][ny].push_back(a);
                pawn_idx[a] = stack_board[nx][ny].size() - 1;
                if (stack_board[nx][ny].size() >= 4) {
                    return play_time;
                }
            }
        }
        else {
            if (is_blue != true) {
                change_dir(loca);
                int nnx = now_pawns.first + direction[pawn_dir[loca]].first;
                int nny = now_pawns.second + direction[pawn_dir[loca]].second;
                int tr = move_pawn(loca, now_pawns, nnx, nny, true, up_on_the_pawn);
                return tr;
            }
            else {
                int upper_size = up_on_the_pawn.size();
                for (int i=upper_size - 1; i>=0; --i) {
                    stack_board[now_pawns.first][now_pawns.second].push_back(up_on_the_pawn[i]);
                }
            }
        }
    }
    else {
        if (is_blue != true) {
            change_dir(loca);
            int nnx = now_pawns.first + direction[pawn_dir[loca]].first;
            int nny = now_pawns.second + direction[pawn_dir[loca]].second;
            int tr = move_pawn(loca, now_pawns, nnx, nny, true, up_on_the_pawn);
            return tr;
        }
        else {
            int upper_size = up_on_the_pawn.size();
            for (int i=upper_size - 1; i>=0; --i) {
                stack_board[now_pawns.first][now_pawns.second].push_back(up_on_the_pawn[i]);
            }
        }
    }
    
    return -1;
}

int lets_play()
{
    while (play_time <= 1000) {
        vector<pair<int, pll> > tmp;
        
        for (int i=1; i<=K; ++i) {
            pll now_pawns = my_pawns[i];
            vector<int> up_on_the_pawn;
            int area_size = stack_board[now_pawns.first][now_pawns.second].size();
            while (area_size - 1 >= pawn_idx[i]) {
                up_on_the_pawn.push_back(stack_board[now_pawns.first][now_pawns.second][area_size - 1]);
                stack_board[now_pawns.first][now_pawns.second].pop_back();
                area_size--;
            }
            
            int nx = now_pawns.first + direction[pawn_dir[i]].first;
            int ny = now_pawns.second + direction[pawn_dir[i]].second;
            
            int tmp_result = move_pawn(i, now_pawns, nx, ny, false, up_on_the_pawn);
            
            if (tmp_result != -1) {
                return tmp_result;
            }
            
            // for (int i=0; i<N; ++i) {
            //     for (int j=0; j<N; ++j) {
            //         cout << stack_board[i][j].size() << " ";
            //     }
            //     cout << "\n";
            // }
            // cout << "\n";
            
        }
        
        // cout << "--------------\n";
        
        for (int i=1; i<=K; ++i) {
            tmp.push_back({pawn_dir[i], {my_pawns[i].first, my_pawns[i].second}});
            // cout << "나는 " << i << "이고 내 방향은 " << pawn_dir[i] <<"이고 내위치는 " << my_pawns[i].first << " " << my_pawns[i].second << "야\n";
        }
        
        if (previous.find(tmp) != previous.end()) {
            return -1;
        }
        else {
            previous[tmp] = 1;
        }
        play_time++;
    }
    
    return -1;
}


int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    cin >> N >> K;
    board.resize(N, vector<int>(N, 0));
    stack_board.resize(N, vector<vector<int> >(N, vector<int>()));
    int num, x, y, dir;
    
    for (int i=0; i<N; ++i) {
        for (int j=0; j<N; ++j) {
            cin >> num;
            board[i][j] = num;
        }
    }
    
    vector<pair<int, pll> > first_time;
    
    for (int i=1; i<=K; ++i) {
        cin >> x >> y >> dir;
        my_pawns[i] = {x - 1, y - 1};
        pawn_dir[i] = dir;
        pawn_idx[i] = 0;
        stack_board[x - 1][y - 1].push_back(i);
        first_time.push_back({dir, {x - 1, y - 1}});
    }
    previous[first_time] = 1;
    
    cout << lets_play();

    return 0;
}
