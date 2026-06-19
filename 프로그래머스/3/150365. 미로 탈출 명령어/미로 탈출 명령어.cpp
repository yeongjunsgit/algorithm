#include <string>
#include <vector>
#include <cmath>

#define pll pair<int, int>

using namespace std;

string result = "";
vector<pll> direction = {{1, 0}, {0, -1}, {0, 1}, {-1, 0}};
vector<char> dict_match = {'d', 'l', 'r', 'u'};


bool dfs(int n, int m, int r, int c, int k, int depth, string now_passed, pll now_loca)
{
    // 가장 처음에 목적지에 도착한 것이 사전순으로 가장 빠른 경로
    if (depth == k && now_loca.first == r && now_loca.second == c) {
        result = now_passed;
        return true;
    }
    
    // 현재 위치에서 목적지까지의 거리를 계산한다.
    int move_way = abs(now_loca.first - r) + abs(now_loca.second - c);
    // 만약, 현재 위치에서 목적지까지의 거리가 모자라면 돌아간다.
    if (k - depth < move_way) return false;
    // 만약 현재 위치에서 목적지까지의 거리가 홀수인데, 남은 턴이 짝수이면 도착이 불가능하므로, 돌아간다.
    if ((k - depth) % 2 == 0 && move_way % 2 != 0) return false;
        
    // 4방향으로 순회하고, 각 위치에서 격자를 벗어나지 않으면 해당 위치로 재귀
    for (int i=0; i<4; ++i) {
        int nx = now_loca.first + direction[i].first;
        int ny = now_loca.second + direction[i].second;
        if (0 < nx && nx <= n && 0 < ny && ny <= m) {
            string next_word = now_passed + dict_match[i];
            bool tmp = dfs(n, m, r, c, k, depth + 1, next_word, {nx, ny});
            if (tmp) return tmp;
        }
    }
    
    return false;
    
}


string solution(int n, int m, int x, int y, int r, int c, int k) {
    string answer = "";
    dfs(n, m, r, c, k, 0, "", {x, y});
    if (result == "") answer = "impossible";
    else answer = result;
    
    return answer;
}