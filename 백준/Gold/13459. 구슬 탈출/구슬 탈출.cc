#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <unordered_set>

// std::pair에 대한 해시 함수 정의
struct pair_hash {
    template <class T1, class T2>
    std::size_t operator() (const std::pair<T1, T2> &p) const {
        auto hash1 = std::hash<T1>{}(p.first);
        auto hash2 = std::hash<T2>{}(p.second);
        // 더 나은 해시 결합을 위한 방법
        return hash1 ^ (hash2 + 0x9e3779b9 + (hash1 << 6) + (hash1 >> 2));
    }
};

// std::pair<std::pair<int, int>, std::pair<int, int>>에 대한 해시 함수 정의
struct nested_pair_hash {
    std::size_t operator() (const std::pair<std::pair<int, int>, std::pair<int, int>> &p) const {
        auto hash1 = pair_hash{}(p.first);
        auto hash2 = pair_hash{}(p.second);
        // 더 나은 해시 결합을 위한 방법
        return hash1 ^ (hash2 + 0x9e3779b9 + (hash1 << 6) + (hash1 >> 2));
    }
};


using namespace std;

int main()
{
    int N, M;
    cin >> N >> M;
    
    cin.ignore();
    
    vector<vector<char>> board;
    
    string data;
    pair<int, int> red_bizz;
    pair<int, int> blue_bizz;
    pair<int, int> finish_point;
    
    for (int i=0; i<N; ++i) {
        vector<char> one_line;
        getline(cin, data);
        for (int j=0; j<M; ++j) {
            one_line.push_back(data[j]);
            if (data[j] == 'O') {
                finish_point = {i, j};
            }
            else if (data[j] == 'R') {
                red_bizz = {i, j};
            }
            else if (data[j] == 'B') {
                blue_bizz = {i, j};
            }
        }
        
        board.push_back(one_line);
    }
    
    unordered_set<pair<pair<int, int>, pair<int, int>>, nested_pair_hash> visited;
    
    visited.insert({red_bizz, blue_bizz});
    
    queue<pair<pair<int, int>, pair<int, int>>> que;
    queue<int> try_que;
    
    que.push({red_bizz, blue_bizz});
    try_que.push(0);
    
    vector<pair<int, int>> direction = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    
    int result = 0;
    
    while (!que.empty()) {
        if (result == 1) {
            break;
        }
        pair<pair<int, int>, pair<int, int>> now = que.front();
        que.pop();
        int trial = try_que.front();
        try_que.pop();
        
        for (int i=0; i<4; ++i) {
            pair<int, int> now_direction = direction[i];
            pair<int, int> now_red = now.first;
            pair<int, int> now_blue = now.second;
            
            bool red_goal = false;
            bool blue_goal = false;
            
            while (true) {
                int red_nx = now_direction.first + now_red.first; 
                int red_ny = now_direction.second + now_red.second;
                
                if (0 <= red_nx && red_nx < N && 0 <= red_ny && red_ny < M) {
                    if (board[red_nx][red_ny] == '#') {
                        break;
                    }
                    
                    else if (board[red_nx][red_ny] == 'O') {
                        red_goal = true;
                        break;
                    }
                    
                    else {
                        now_red = {red_nx, red_ny};
                        continue;
                    }
                }
            }
            
            while (true) {
                int blue_nx = now_direction.first + now_blue.first; 
                int blue_ny = now_direction.second + now_blue.second;
                
                if (0 <= blue_nx && blue_nx < N && 0 <= blue_ny && blue_ny < M) {
                    if (board[blue_nx][blue_ny] == '#') {
                        break;
                    }
                    
                    else if (board[blue_nx][blue_ny] == 'O') {
                        blue_goal = true;
                        break;
                    }
                    
                    else {
                        now_blue = {blue_nx, blue_ny};
                        continue;
                    }
                }
            }
            
            if (red_goal == true) {
                if (blue_goal == true) {
                    continue;
                }
                else {
                    result = 1;
                    break;
                }
            }
            
            else {
                if (blue_goal == true) {
                    continue;
                }
                else {
                    if (now_red == now_blue) {
                        if (i == 0) {
                            if (now.first.second > now.second.second) {
                                now_blue.second -= 1;
                            }
                            else {
                                now_red.second -= 1;
                            }
                        }
                        else if (i == 1) {
                            if (now.first.first > now.second.first) {
                                now_blue.first -= 1;
                            }
                            else {
                                now_red.first -= 1;
                            }
                        }
                        else if (i == 2) {
                            if (now.first.second < now.second.second) {
                                now_blue.second += 1;
                            }
                            else {
                                now_red.second += 1;
                            }
                        }
                        else if (i == 3) {
                            if (now.first.first < now.second.first) {
                                now_blue.first += 1;
                            }
                            else {
                                now_red.first += 1;
                            }
                        }
                    }
                    
                    if (visited.find({now_red, now_blue}) == visited.end()) {
                        if (trial + 1 < 10) {
                            que.push({now_red, now_blue});
                            visited.insert({now_red, now_blue});
                            try_que.push(trial + 1);
                        }
                    }
                }
            }
            
        }
    }
    
    cout << result;

    return 0;
}
