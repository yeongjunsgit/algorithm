#include <iostream>
#include <sstream>
#include <vector>
#include <cmath>

using namespace std;


int main()
{
    
    int N;
    vector<vector<int>> arr;
    
    // 변수들에 입력값 넣기
    cin >> N;
    
    cin.ignore();
    
    
    for (int i=0; i<N; ++i) {
        string data;
        getline(cin, data);
        
        vector<int> tmp_arr;
        
        istringstream iss(data);
        int num;
        
        while (iss >> num) {
            tmp_arr.push_back(num);
        }
        
        arr.push_back(tmp_arr);
    }
    
    // 토네이도의 이동에 관여할 변수
    vector<pair<int, int>> direction = {{0, -1}, {1, 0}, {0, 1}, {-1, 0}};
    vector<vector<pair<int, int>>> spread_loca = {{{-1, 1}, {1, 1}, {-2, 0}, {2, 0}, {0, -2}, {1, 0}, {-1, 0}, {-1, -1}, {1, -1}}, 
        {{-1, 1}, {-1, -1}, {0, -2}, {0, 2}, {2, 0}, {0, -1}, {0, 1}, {1, 1}, {1, -1}},
        {{1, -1}, {-1, -1}, {-2, 0}, {2, 0}, {0, 2}, {-1, 0}, {1, 0}, {1, 1}, {-1, 1}},
        {{1, -1}, {1, 1}, {0, -2}, {0, 2}, {-2, 0}, {0, -1}, {0, 1}, {-1, 1}, {-1, -1}}
    };
    
    int movement = 0;
    int now_direction = 0;
    
    // 격자 밖으로 나가는 모래를 담을 변수
    int wasted_send = 0;
    
    // 현재 위치를 나타낼 now_point
    pair<int, int> now_point = {N/2, N/2}; 
    
    // 토네이도 순회 시작
    while (now_point.first != 0 || now_point.second != 0) {
        int x = direction[now_direction].first;
        int y = direction[now_direction].second;
        
        // 토네이도가 가로 방향으로 이동시에 이동 량을 1증가
        if (y != 0) {
            movement += 1;
        }
        
        
        // 이동량 만큼 현재 방향으로 이동함
        for (int i=0; i<movement; ++i) {
            now_point.first += x;
            now_point.second += y;
            
            int now_send = arr[now_point.first][now_point.second];
            int calcul_send = 0;
            arr[now_point.first][now_point.second] = 0;
            
            // 해당 위치의 모래를 주어진 규칙에 따라 흩뿌린다.
            int percentage = 0;
            
            if (now_send != 0) {
                for (int j=0; j<9; ++j) {
                    // 1%
                    if (j < 2) {
                        percentage = 1;
                    }
                    // 2%
                    else if (j == 2 || j == 3) {
                        percentage = 2;
                    }
                    // 5%
                    else if (j == 4) {
                        percentage = 5;
                    }
                    // 7%
                    else if (j == 5 || j == 6) {
                        percentage = 7;
                    }
                    // 10%
                    else if (j == 7 || j == 8) {
                        percentage = 10;
                    }
                    pair<int,int> blow_loca = spread_loca[now_direction][j];
                    int nx, ny;
                    nx = now_point.first + blow_loca.first;
                    ny = now_point.second + blow_loca.second;
                    
                    double my_percent = static_cast<double>(now_send) / 100 * percentage;
                    
                    if ((0 <= nx && nx < N) && (0 <= ny && ny < N)) {
                        arr[nx][ny] += static_cast<int>(floor(my_percent));
                        calcul_send += static_cast<int>(floor(my_percent));
                    }
                    else {
                        wasted_send += static_cast<int>(floor(my_percent));
                        calcul_send += static_cast<int>(floor(my_percent));
                    }
                    
                }
                if ((0 <= now_point.first + x && now_point.first + x < N) && 
                (0 <= now_point.second + y && now_point.second + y < N)) {
                    arr[now_point.first + x][now_point.second + y] += (now_send - calcul_send);
                }
                else {
                    wasted_send += (now_send - calcul_send);
                }
            }
            
            if (now_point.first == 0 && now_point.second == 0) {
                break;
            }
            
        }
        now_direction = (now_direction + 1) % 4;
    }
    
    cout << wasted_send;
    
    return 0;
}