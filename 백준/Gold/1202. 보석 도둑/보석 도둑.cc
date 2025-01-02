#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;


int N, K;
vector<int> backpack;
vector<pair<int, int> > jewelry;

void pick_up()
{
    long long result = 0;
    int idx = 0;
    priority_queue<int, vector<int>, less<int> > que;
    
    for (int i=0; i<K; ++i) {
        while (backpack[i] >= jewelry[idx].first && idx != N) {
            que.push(jewelry[idx].second);
            idx++;
        }
        if (!que.empty()) {
            result += que.top();
            que.pop();
        }
    }
    
    cout << result;
    
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> N >> K;
    int price, weight;
    
    for (int i=0; i<N; ++i) {
        cin >> weight >> price;
        
        jewelry.push_back({weight, price});
    }
    
    for (int i=0; i<K; ++i) {
        cin >> weight;
        backpack.push_back(weight);
    }
    
    sort(backpack.begin(), backpack.end());
    sort(jewelry.begin(), jewelry.end());
    
    pick_up();

    return 0;
}
