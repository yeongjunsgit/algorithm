#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

#define pcl pair<char, int>

using namespace std;

struct Compare{
    bool operator()(const pcl& a, const pcl& b) {
        if (a.first == b.first) {
            return a.second < b.second;
        }
        return a.first > b.first;
    }
};

int N;
unordered_map<char, int> sentence_cnt, used_cnt;
priority_queue<pcl, vector<pcl>, Compare> que;
vector<char> cards;

void oreno_turn_draw()
{
    string sang_card = "", heu_card = "";
    while (!que.empty() && cards.size() > 0) {
        while (cards.size() > 0 && cards.back() == '1') {
            cards.pop_back();
        }
        if (cards.size() > 0) {
            sang_card += cards.back();
            used_cnt[cards.back()]++;
            cards.pop_back();
        }
        else {
            break;
        }
        
        while (!que.empty() && used_cnt[que.top().first] > 0) {
            used_cnt[que.top().first]--;
            // cout << que.top().second << "\n";
            que.pop();
        }
        if (!que.empty()) {
            heu_card += que.top().first;
            cards[que.top().second] = '1';
            que.pop();
        }
    }
    
    if (heu_card < sang_card) {
        cout << "DA\n" << heu_card;
    }
    else {
        cout << "NE\n" << heu_card;
    }
    
    return;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    string deck;
    cin >> N >> deck;
    
    for (int i=0; i<N; ++i) {
        cards.push_back(deck[i]);
        que.push({deck[i], i});
        sentence_cnt[deck[i]]++;
        used_cnt[deck[i]] = 0;
    }
    
    oreno_turn_draw();

    return 0;
}