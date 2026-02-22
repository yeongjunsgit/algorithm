#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, now_vote, num, cnt = 0;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> now_vote;
    priority_queue<int, vector<int>, less<int>> que;
    for (int i=0; i<N-1; ++i) {
        cin >> num;
        que.push(num);
    }
    while (!que.empty() && now_vote <= que.top()) {
        int tmp = que.top();
        que.pop();
        now_vote++;
        tmp--;
        que.push(tmp);
        cnt++;
    }
    cout << cnt;

    return 0;
}
