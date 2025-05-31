#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int T, M;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> T;
    for (int t=0; t<T; ++t) {
        cin >> M;
        int mid, num, front_size = 0, back_size = 0;
        vector<int> mid_nums;
        cin >> mid;
        mid_nums.push_back(mid);
        priority_queue<int, vector<int>, greater<int> > back_que;
        priority_queue<int, vector<int>, less<int> > front_que;
        
        for (int i=1; i<M; ++i) {
            cin >> num;
            if (num < mid) {
                front_que.push(num);
                front_size++;
                if (front_size == back_size + 2) {
                    back_que.push(mid);
                    mid = front_que.top();
                    front_que.pop();
                    front_size--;
                    back_size++;
                }
            }
            else if (num > mid) {
                back_que.push(num);
                back_size++;
                if (back_size == front_size + 2) {
                    front_que.push(mid);
                    mid = back_que.top();
                    back_que.pop();
                    back_size--;
                    front_size++;
                }
            }
            else {
                if (front_size > 0 && front_que.top() == mid) {
                    back_que.push(num);
                    back_size++;
                    if (back_size == front_size + 2) {
                        front_que.push(mid);
                        back_que.pop();
                        back_size--;
                        front_size++;
                    }
                    
                }
                else {
                    front_que.push(num);
                    front_size++;
                    if (front_size == back_size + 2) {
                        back_que.push(mid);
                        front_que.pop();
                        back_size++;
                        front_size--;
                    }
                }
            }
            
            if (i % 2 == 0) mid_nums.push_back(mid);
        }
        
        cout << mid_nums.size() << "\n";
        for (int a : mid_nums) {
            cout << a << " ";
        }
        cout << "\n";
        
    }
    
    return 0;
}
