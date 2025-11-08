#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>

using namespace std;

int N;
vector<long long> lower_nums(1000001, -1);


void get_nums()
{
    int idx = 10;
    queue<long long> que;
    for (long long i=0; i<10; ++i) {
        lower_nums[i] = i;
        que.push(i);
    }
    
    while (!que.empty()) {
        queue<long long> next_que;
        vector<long long> tmp;
        long long M;
        if (que.front() != 0) {
            M = log10(que.front());
        }
        else {
            M = 0;
        }
        long long next_size = pow(10, M+1);
        while (!que.empty()) {
            long long now = que.front();
            que.pop();
            long long top_num = now / pow(10, M);
            for (int j=9; j>0; --j) {
                if (j > top_num) {
                    long long next_num = j * next_size + now;
                    next_que.push(next_num);
                    tmp.push_back(next_num);
                }
            }
        }
        sort(tmp.begin(), tmp.end(), less<int>());
        for (long long a : tmp) {
            lower_nums[idx] = a;
            idx++;
        }
        que = next_que;
    }
    
    return;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    
    get_nums();
    
    cout << lower_nums[N];

    return 0;
}