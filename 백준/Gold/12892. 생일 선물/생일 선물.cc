// 문제를 보니 슬라이딩 윈도우를 이용하면 풀릴것 같았다. 그런데 값이...너무 큰데...?
// long long으로도 커버가 안될거같은데... big integer를 쓰는 문제인건가...?
// que가 전부 비어있을 경우를 생각하지 못했다..! !que.empty() 조건을 걸어주었다!


#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>

#define pll pair<int, int>

using namespace std;

int N, D, s, e;
vector<pll> gifts;

struct Compare
{
    bool operator()(const pll& a, const pll& b) {
        return a.first < b.first;
    }
};


int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> D;
    for (int i=0; i<N; ++i) {
        cin >> s >> e;
        gifts.push_back({s, e});
    }
    sort(gifts.begin(), gifts.end(), Compare());
    
    deque<pll> que;
    que.push_back(gifts[0]);
    long long now_happy = gifts[0].second, max_happy = now_happy;
    for (int i=1; i<N; ++i) {
        while (!que.empty() && gifts[i].first - que.front().first >= D) {
            now_happy -= que.front().second;
            que.pop_front();
        }
        now_happy += gifts[i].second;
        que.push_back(gifts[i]);
        max_happy = max(max_happy, now_happy);
    }
    cout << max_happy;

    return 0;
}
