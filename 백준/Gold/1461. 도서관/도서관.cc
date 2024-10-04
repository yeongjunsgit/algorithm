#include <iostream>
#include <sstream>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

int N, M;
priority_queue<int, vector<int>, less<int> > plus_que;
priority_queue<int, vector<int>, greater<int> > minus_que;

void check_walk()
{
    int result = 0;
    bool final_book = false;
    while (!plus_que.empty() || !minus_que.empty()) {
        int plus_max;
        int minus_max;
        if (plus_que.empty()) {
            plus_max = 0;
        }
        else {
            plus_max = plus_que.top();
        }
        if (minus_que.empty()) {
            minus_max = 0;
        }
        else {
            minus_max = abs(minus_que.top());
        }
        int idx = 0;
        
        if (plus_max > minus_max) {
            while (!plus_que.empty()) {
                plus_que.pop();
                idx++;
                if (idx == M) {
                    break;
                }
            }
            if (final_book == false) {
                final_book = true;
                result += plus_max;
            }
            else {
                result += plus_max * 2;
            }
        }
        else {
            while (!minus_que.empty()) {
                minus_que.pop();
                idx++;
                if (idx == M) {
                    break;
                }
            }
            if (final_book == false) {
                final_book = true;
                result += minus_max;
            }
            else {
                result += minus_max * 2;
            }
        }
    }
    
    cout << result;
    
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> N >> M;
    cin.ignore();
    
    string data;
    int num;
    getline(cin, data);
    istringstream iss(data);
    
    while (iss >> num) {
        if (num > 0) {
            plus_que.push(num);
        }
        else {
            minus_que.push(num);
        }
    }
    
    check_walk();
    
    return 0;
}
