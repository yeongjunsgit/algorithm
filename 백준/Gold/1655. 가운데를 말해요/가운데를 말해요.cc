#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N, num, mid;
    priority_queue<int, vector<int>, greater<int> > high_que;
    priority_queue<int, vector<int>, less<int> > low_que;
    
    cin >> N;

    int low_size = 0, high_size = 0;
    for (int i=1; i<=N; ++i) {
        cin >> num;
        
        if (i == 1) {
            mid = num;
        }
        else {
            if (num < mid) {
                if (low_size - high_size <= 0) {
                    if (i % 2 == 0 && num < mid) {
                        high_que.push(mid);
                        high_size++;
                        low_que.push(num);
                        mid = low_que.top();
                        low_que.pop();
                    }
                    else{
                        low_que.push(num);
                        low_size++;
                    }
                }
                else {
                    high_que.push(mid);
                    high_size++;
                    low_que.push(num);
                    mid = low_que.top();
                    low_que.pop();
                }
            }
            else if (num > mid) {
                if (high_size - low_size <= 0) {
                    high_que.push(num);
                    high_size++;
                }
                else {
                    low_que.push(mid);
                    low_size++;
                    high_que.push(num);
                    mid = high_que.top();
                    high_que.pop();
                }
            }
            else {
                if (low_size > high_size) {
                    high_size++;
                    high_que.push(num);
                }
                else {
                    low_size++;
                    low_que.push(num);
                }
            }
        }
        
        
        cout << mid << "\n";
    }

    return 0;
}
