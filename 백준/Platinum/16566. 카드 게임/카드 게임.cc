#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

int N, M, K;
vector<int> cards, bigger_card;
unordered_map<int, int> card_cnt;


void get_data()
{
    cin >> N >> M >> K;
    cards.resize(M);
    bigger_card.resize(N + 1);
    for (int i=0; i<M; ++i) {
        cin >> cards[i];
    }
    sort(cards.begin(), cards.end(), less<int>());
    
    int tmp = 0;
    for (int i=0; i<M; ++i) {
        if (cards[i] > tmp) {
            card_cnt[cards[i]] = 1;
            for (int j=tmp; j<cards[i]; ++j) {
                bigger_card[j] = cards[i];
            }
            tmp = cards[i];
        }
        else if (cards[i] == tmp) {
            card_cnt[cards[i]]++;
        }
    }
    
    return;
}


int get_number(int now)
{
    int next_num = bigger_card[now];
    if (card_cnt[next_num] > 0) {
        card_cnt[next_num]--;
        return next_num;
    }
    else {
        return bigger_card[now] = get_number(next_num);
    }
}


void pick_cards()
{
    int num;
    for (int k=0; k<K; ++k) {
        cin >> num;
        cout << get_number(num) << "\n";
    }
    
    return;
}


int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    get_data();
    pick_cards();
    
    return 0;
}
