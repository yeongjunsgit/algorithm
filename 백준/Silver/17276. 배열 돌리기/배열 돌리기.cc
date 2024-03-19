#include <iostream>
#include <vector>
#include <utility>

using namespace std;


int main()
{
    int T;
    cin >> T;
    
    for (int t = 0; t < T; ++t) {
        int N, D;
        cin >> N >> D;
        
        bool right;
        
        if (D > 0) {
            right = true;
        } else {
            right = false;
        }
        
        int d;
        d = D / 45;
        
        vector<vector<int>> arr(N);
        
        for (int i = 0; i < N; ++i) {
            for (int j=0; j < N; ++j) {
                int tmp;
                cin >> tmp;
                arr[i].push_back(tmp);
            }
        }
        
        vector<pair<int, int>> right_cycle {{0, 0}, {0, N/2}, {0, N-1}, {N/2, N-1},
            {N-1, N-1}, {N-1, N/2}, {N-1, 0}, {N/2, 0}
        };
        
        vector<vector<int>> new_arr(N);

        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                new_arr[i].push_back(arr[i][j]);
            }
        }
        
        int shell = N / 2;
        
        for (int s=0; s < shell; ++s) {
            for (int e=0; e < 8; ++e) {
                int x, y;
                x = right_cycle[e].first;
                y = right_cycle[e].second;
                if (x == 0) {
                    x += s;
                } else if (x == N-1) {
                    x -= s;
                }
                if (y == 0) {
                    y += s;
                } else if (y == N-1) {
                    y -= s;
                }
                
                if (right == true) {
                    int new_loca = (e + d) % 8;
                    int nx, ny;
                    nx = right_cycle[new_loca].first;
                    ny = right_cycle[new_loca].second;
                    
                    if (nx == 0) {
                        nx += s;
                    } else if (nx == N-1) {
                        nx -= s;
                    }
                    if (ny == 0) {
                        ny += s;
                    } else if (ny == N-1) {
                        ny -= s;
                    }
                    
                    new_arr[nx][ny] = arr[x][y];
                    
                } else {
                    int new_loca = e - (-d);
                    if (new_loca < 0) {
                        while (new_loca < 0) {
                            new_loca = 8 - (-new_loca);
                        }
                    }

                    int nx, ny;
                    nx = right_cycle[new_loca].first;
                    ny = right_cycle[new_loca].second;
                    
                    if (nx == 0) {
                        nx += s;
                    } else if (nx == N-1) {
                        nx -= s;
                    }
                    if (ny == 0) {
                        ny += s;
                    } else if (ny == N-1) {
                        ny -= s;
                    }
                    
                    new_arr[nx][ny] = arr[x][y];
                }
                
            }
        }
        
        for (int i=0; i < N; ++i) {
            for (int j=0; j < N; ++j) {
                cout << new_arr[i][j] << " ";
            }
            cout << endl;
        }
    }
    
    return 0;
}
