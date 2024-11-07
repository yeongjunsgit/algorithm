#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N, num;
    cin >> N;
    priority_queue<int, vector<int>, greater<int> > que;
    
    for (int i=0; i<N; ++i) {
        cin >> num;
        que.push(num);
    }
    
    while (!que.empty()) {
        int now = que.top();
        que.pop();
        
        cout << now << "\n";
    }

    return 0;
}
