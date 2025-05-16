#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N, K;
    cin >> N >> K;
    
    queue<int> que;
    
    for (int i=1; i<=N; ++i) {
        if (N % i == 0) {
            que.push(i);
        }
    }
    int result = 0;
    for (int i=0; i<K; ++i) {
        if (!que.empty()) {
            result = que.front();
            que.pop();
        }
        else {
            result = 0;
            break;
        }
    }
    
    cout << result;

    return 0;
}