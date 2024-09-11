#include <iostream>
#include <vector>
#include <queue>
#include <map>

using namespace std;

int T, K;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> T;
    
    for (int t=0; t<T; ++t) {
        cin >> K;
        priority_queue<long long, vector<long long>, less<long long> > max_que;
        priority_queue<long long, vector<long long>, greater<long long> > min_que;
        map<long long, long long> min_used;
        map<long long, long long> max_used;
        char command;
        long long num;
        
        for (int i=0; i<K; ++i) {
            cin >> command >> num;
            if (command == 'I') {
                min_que.push(num);
                max_que.push(num);
                min_used[num] += 1;
                max_used[num] += 1;
            }
            
            else {
                if (!min_que.empty() && !max_que.empty()) {
                    if (num == 1) {
                        while (!max_que.empty() && max_used[max_que.top()] > min_used[max_que.top()]) {
                            max_used[max_que.top()]--;
                            max_que.pop();
                        }
                        if (!max_que.empty()) {
                            max_used[max_que.top()]--;
                            max_que.pop();
                        }
                    }
                    else {
                        while (!min_que.empty() && min_used[min_que.top()] > max_used[min_que.top()]) {

                            min_used[min_que.top()]--;
                            min_que.pop();
                        }
                        if (!min_que.empty()) {
                            min_used[min_que.top()]--;
                            min_que.pop();
                            
                        }
                    }
                }
            }
        }
        while (!min_que.empty() && min_used[min_que.top()] > max_used[min_que.top()]) {
            min_used[min_que.top()]--;
            min_que.pop();
        }
        while (!max_que.empty() && max_used[max_que.top()] > min_used[max_que.top()]) {
            max_used[max_que.top()]--;
            max_que.pop();
        }
        
        if (!min_que.empty() && !max_que.empty() && min_used[min_que.top()] > 0 && max_used[max_que.top()] > 0) {
            cout << max_que.top() << " " << min_que.top() << "\n";
        }
        else {
            cout << "EMPTY" << "\n";
        }
        
    }

    return 0;
}
