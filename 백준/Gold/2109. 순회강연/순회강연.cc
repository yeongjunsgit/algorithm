#include <iostream>
#include <vector>
#include <queue>
#include <numeric>

using namespace std;

struct Compare {
    bool operator() (const pair<int, int>& a, const pair<int, int>& b) const {
            return a.first < b.first;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N;
    cin >> N;
    
    vector<int> pay_day(10001, 0);
    int result = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> check_que; 
    
    for (int i=0; i<N; ++i) {
        int pay, day;
        cin >> pay >> day;
        
        check_que.push({pay, day});
    }
    
    while (!check_que.empty()) {
        pair<int, int> now = check_que.top();
        check_que.pop();
        
        if (pay_day[now.second] < now.first) {
            pay_day[now.second] = now.first;
        }
        
        else {
            for (int i=now.second-1; i>0; --i) {
                if (pay_day[i] < now.first) {
                    pay_day[i] = now.first;
                    break;
                }
            }
        }
    }
    

    result = accumulate(pay_day.begin(), pay_day.end(), 0);

    cout << result;
    

    return 0;
}
