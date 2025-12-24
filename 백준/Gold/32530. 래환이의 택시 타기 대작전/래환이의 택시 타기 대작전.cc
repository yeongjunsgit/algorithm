#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N;


int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    string leave_time;
    priority_queue<int, vector<int>, greater<int> > que;
    for (int i=0; i<N; ++i) {
        cin >> leave_time;
        int tmp = 0;
        tmp += (leave_time[0] - '0') * 600;
        tmp += (leave_time[1] - '0') * 60;
        tmp += (leave_time[3] - '0') * 10;
        tmp += (leave_time[4] - '0');
        
        que.push(tmp);
    }
    int cnt = 0;
    vector<int> base;
    while (!que.empty()) {
        if (base.empty()) {
            base.push_back(que.top());
            que.pop();
        }
        else {
            bool is_ok = true;
            for (int i : base) {
                if (i + 10 < que.top() - 10) {
                    is_ok = false;
                    break;
                }
            }
            if (is_ok) {
                if (base.size() < 2) {
                    base.push_back(que.top());
                }
                else if (base.size() == 2) {
                    cnt++;
                    base = {};
                }
            }
            else {
                cnt++;
                base = {que.top()};
            }
            que.pop();
        }
    }
    if (base.size() > 0) cnt++;
    
    cout << cnt;

    return 0;
}
