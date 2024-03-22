#include <iostream>
#include <queue>
#include <vector>
#include <utility>

using namespace std;

int main()
{
    int N;
    cin >> N;
    
    priority_queue<int, vector<int>, greater<int>> pq;
    
    for (int i=0; i<N; ++i) {
        int T;
        cin >> T;
        pq.push(T);
    }
    
    int result = 0;
    
    while (pq.size() > 1) {
        int first_num = pq.top();
        pq.pop();
        int second_num =pq.top();
        pq.pop();
        
        result += first_num + second_num;
        
        int tmp = first_num + second_num;
        pq.push(tmp);
    }
    
    cout << result;

    return 0;
}