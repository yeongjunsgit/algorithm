#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

unordered_set<string> visited;
int result = 999999999;
queue<pair<string, int> > que;
vector<pair<int, int> > directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

int lets_move()
{
    while (!que.empty()) {
        string now = que.front().first;
        int depth = que.front().second;
        que.pop();

        if (now == "123456780") {
            return depth;
        }
        else {
            int zero_idx;
            for (int i=0; i<9; ++i) {
                if (now[i] == '0') {
                    zero_idx = i;
                    break;
                }
            }
            // 현재 0의 string 상의 index 값을 2차원 배열 퍼즐 판의 인덱스 값으로 치환
            int x = zero_idx / 3;
            int y = zero_idx % 3;
            for (int i=0; i<4; ++i) {
                int nx = x + directions[i].first;
                int ny = y + directions[i].second;
                
                if (0 <= nx && nx < 3 && 0 <= ny && ny < 3) {
                    int new_idx = nx * 3 + ny;
                    string next = now;
                    swap(next[zero_idx], next[new_idx]);
                    if (visited.find(next) == visited.end()) {
                        visited.insert(next);
                        que.push({next, depth + 1});
                    }
                }
            }
        }
    }
    
    return -1;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    string start = "";
    string S;
    for (int i=0; i<3; ++i) {
        for (int j=0; j<3; ++j) {
            cin >> S;
            start += S;
        }
    }
    que.push({start, 0});
    
    cout << lets_move();
    
    return 0;
}
