#include <iostream>
#include <sstream>
#include <deque>
#include <vector>

using namespace std;

int T, N, M, K;

void sliding(vector<int>& moneys, int& cnt)
{
    deque<int> que;
    int now = 0;
    
    for (int i=0; i<N; ++i) {
        if (que.size() < M) {
            que.push_back(moneys[i]);
            now += moneys[i];
            if (que.size() == M && now < K) {
                cnt++;
            }
        }
        else {
            now -= que.front();
            que.pop_front();
            
            que.push_back(moneys[i]);
            now += moneys[i];
            if (now < K) {
                cnt++;
            }
        }
    }
    if (N != M) {
        for (int i=0; i<M-1; ++i) {
            now -= que.front();
            que.pop_front();
            que.push_back(moneys[i]);
            now += moneys[i];
            if (now < K) {
                cnt++;
            }
        }
    }
    
    cout << cnt << "\n";
    
    return;
}


int main()
{
    cin >> T;
    
    for (int t=0; t<T; ++t) {
        cin >> N >> M >> K;
        cin.ignore();
        
        string data;
        int num;
        vector<int> moneys;
        int cnt = 0;
        getline(cin, data);
        
        istringstream iss(data);
        while (iss >> num) {
            moneys.push_back(num);
        }
        
        sliding(moneys, cnt);
        
    }

    return 0;
}
