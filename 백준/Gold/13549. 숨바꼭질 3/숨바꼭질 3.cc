#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M;

int main()
{
    cin >> N >> M;
    
    vector<int> streets(100001, 100001);
    queue<pair<int, int> > que;
    que.push({N, 0});
    streets[N] = 0;
    while (!que.empty()) {
        pair<int, int> now = que.front();
        que.pop();
        
        if (streets[now.first] < now.second) {
            continue;
        }
        
        if (now.first + 1 < 100001 && streets[now.first + 1] > now.second + 1) {
            if (now.first + 1 != M) {
                que.push({now.first + 1, now.second + 1});
                
            }
            streets[now.first + 1] = now.second + 1;
        }
        
        if (now.first - 1 >= 0 && streets[now.first - 1] > now.second + 1) {
            if (now.first - 1 != M) {
                que.push({now.first - 1, now.second + 1});
            }
            streets[now.first - 1] = now.second + 1;
        }
        
        if (now.first * 2 < 100001 && streets[now.first * 2] > now.second) {
            if (now.first * 2 != M) {
                que.push({now.first * 2, now.second});
            }
            streets[now.first * 2] = now.second;
        }
    }
    
    cout << streets[M];

    return 0;
}