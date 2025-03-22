#include <iostream>
#include <vector>

using namespace std;

int T, N;

int card_draw(vector<vector<int> >& DP, vector<int>& cards, int left, int right, int depth)
{
    // 카드의 구간이 유효하지 않을 때 즉, 뽑을 카드가 없을 때 0을 반환
    if (left > right) {
        return 0;
    }
    // 이미 경험한 적 있는 경우라면 기록된 값을 반환
    if (DP[left][right] > 0) {
        return DP[left][right];
    }
    if (depth % 2 == 0) {
        // 내 턴에는 나의 값을 최대로 해야하기 문에 최대값을 기록한다.
        return DP[left][right] = max(card_draw(DP, cards, left + 1, right, depth + 1) + cards[left], card_draw(DP, cards, left, right - 1, depth + 1) + cards[right]);
    }
    else {
        // 상대 턴에는 나의 값을 최소로 만들려고 하기 때문에 최소값을 기록한다.
        return DP[left][right] = min(card_draw(DP, cards, left + 1, right, depth + 1), card_draw(DP, cards, left, right - 1, depth + 1));
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    cin >> T;
    
    for (int t=0; t<T; ++t) {
        cin >> N;
        vector<vector<int> > DP(N, vector<int>(N, 0));
        vector<int> cards(N, 0);
        for (int i=0; i<N; ++i) {
            cin >> cards[i];
        }
        
        cout << card_draw(DP, cards, 0, N-1, 0) << "\n";
        
    }

    return 0;
}