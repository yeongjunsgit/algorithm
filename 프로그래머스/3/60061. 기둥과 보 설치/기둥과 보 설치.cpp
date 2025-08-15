#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Compare
{
    bool operator()(vector<int>& a, vector<int>& b) {
        if (a[0] == b[0]) {
            if (a[1] == b[1]) {
                return a[2] < b[2];
            }
            return a[1] < b[1];
        }
        return a[0] < b[0];
    }
};

vector<vector<int> > column_info(101, vector<int>(101)), row_info(101, vector<int>(101));

bool set_struct(int x, int y, int kind, int n)
{
    // 기둥은 바닥(x == 0)이나, 다른 보나, 다른 기둥위에 설치할 수 있다!
    if (kind == 0) {
        if (y == 0 || (y - 1 >= 0 && column_info[y-1][x] == 1) || row_info[y][x] == 1 || (x - 1 >= 0 && row_info[y][x-1] == 1) ) {
            column_info[y][x] = 1;
            // cout << kind << " 구조물이 {" << x << ", " << y << "} 좌표에 설치 성공!\n";
            return true;
        }
    }
    // 보는 다른 기둥이 양쪽 중 한 쪽에 있거나, 양쪽 끝이 보여야만 설치할 수 있다.
    else if (kind == 1) {
        if ((y - 1 >= 0 && column_info[y-1][x] == 1) || (y - 1 >= 0 && x + 1 <= n && column_info[y-1][x+1] == 1) || (x - 1 >= 0 && x + 1 < n && row_info[y][x-1] == 1 && row_info[y][x+1] == 1)) {
            row_info[y][x] = 1;
            // cout << kind << " 구조물이 {" << x << ", " << y << "} 좌표에 설치 성공!\n";
            return true;
        }
    }
    // cout << kind << " 구조물이 {" << x << ", " << y << "} 좌표에 설치 실패!\n";
    return false;
}

vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
    vector<vector<int>> answer;
    int M = build_frame.size();
    for (int i=0; i<M; ++i) {
        // 기둥인 경우
        if (build_frame[i][2] == 0) {
            // 삭제인 경우
            if (build_frame[i][3] == 0 && column_info[build_frame[i][1]][build_frame[i][0]] == 1) {
                column_info[build_frame[i][1]][build_frame[i][0]] = 0;
                bool check = true;
                // 기둥은 삭제될 때, 자신을 기준으로 새워진 기둥이 있는지, 자신을 기준으로 세워진 보가 안전한지를 확인해야한다.
                if (build_frame[i][1] + 1 < n && column_info[build_frame[i][1] + 1][build_frame[i][0]] == 1) {
                    if (check) check = set_struct(build_frame[i][0], build_frame[i][1] + 1, 0, n);
                }
                if (build_frame[i][1] + 1 <= n && row_info[build_frame[i][1] + 1][build_frame[i][0]] == 1) {
                    if (check) check = set_struct(build_frame[i][0], build_frame[i][1] + 1, 1, n);
                }
                if (build_frame[i][1] + 1 <= n && build_frame[i][0] - 1 >= 0 && row_info[build_frame[i][1] + 1][build_frame[i][0] - 1] == 1) {
                    if (check) check = set_struct(build_frame[i][0] - 1, build_frame[i][1] + 1, 1, n);
                }
                // 한개라도 만들어지지 않으면 없으면 안되는 기둥이므로 다시 원복
                if (!check) {
                    column_info[build_frame[i][1]][build_frame[i][0]] = 1;
                    // cout << build_frame[i][2] << " 구조물이 {" << build_frame[i][0] << ", " << build_frame[i][1] <<"} 좌표에서 삭제 실패!\n";
                }
                else {
                    // cout << build_frame[i][2] << " 구조물이 {" << build_frame[i][0] << ", " << build_frame[i][1] <<"} 좌표에서 삭제 성공!\n";
                }
            }
            // 설치인 경우
            else {
                set_struct(build_frame[i][0], build_frame[i][1], build_frame[i][2], n);
            }
        }
        // 보인 경우
        else {
            // 삭제인 경우
            if (build_frame[i][3] == 0 && row_info[build_frame[i][1]][build_frame[i][0]] == 1) {
                row_info[build_frame[i][1]][build_frame[i][0]] = 0;
                bool check = true;
                // 보는 삭제될 때 양옆에 기둥이 있는지, 양 옆의 보가 본인을 기준으로 생기는지를 판단해주어야 한다.
                if (build_frame[i][0] + 1 <= n && column_info[build_frame[i][1]][build_frame[i][0] + 1] == 1) {
                    if (check) check = set_struct(build_frame[i][0] + 1, build_frame[i][1], 0, n);
                }
                if (column_info[build_frame[i][1]][build_frame[i][0]] == 1) {
                    if (check) check = set_struct(build_frame[i][0], build_frame[i][1], 0, n);
                }
                if (build_frame[i][0] + 1 < n && row_info[build_frame[i][1]][build_frame[i][0] + 1] == 1) {
                    if (check) check = set_struct(build_frame[i][0] + 1, build_frame[i][1], 1, n);
                }
                if (build_frame[i][0] - 1 >= 0 && row_info[build_frame[i][1]][build_frame[i][0] - 1] == 1) {
                    if (check) check = set_struct(build_frame[i][0] - 1, build_frame[i][1], 1, n);
                }
                
                if (!check) row_info[build_frame[i][1]][build_frame[i][0]] = 1;
                
            }
            // 설치인 경우
            else {
                set_struct(build_frame[i][0], build_frame[i][1], build_frame[i][2], n);
            }
        }
    }
    
    for (int i=0; i<=n; ++i) {
        for (int j=0; j<=n; ++j) {
            if (column_info[i][j] == 1) answer.push_back({j, i, 0});
            if (row_info[i][j] == 1) answer.push_back({j, i, 1});
        }
    }
    
    sort(answer.begin(), answer.end(), Compare());
    
    return answer;
}
