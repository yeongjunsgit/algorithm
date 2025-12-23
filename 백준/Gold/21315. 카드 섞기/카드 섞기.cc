#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;


int N, result = 0, now_size = 1, multifle = 0;
vector<int> base_card_set, answer;


void shuffle_deck(vector<int> deck, bool second_time, int now)
{
    for (int k=1; k<=multifle; ++k) {
        if (result != 0) return;
        vector<int> tmp;
        tmp = deck;
        int last_idx = 0, size_check = N;
        for (int i=k; i>=0; --i) {
            int pick_size = pow(2, i);
            
            rotate(tmp.begin(), tmp.end() - (pick_size + last_idx), tmp.end() - last_idx);
            last_idx += (size_check - pick_size);
            size_check = N - last_idx;
        }
        
        if (!second_time) shuffle_deck(tmp, true, k);
        else {
            if (answer == tmp) {
                result = now * 10 + k;
                return;
            }
        }
    }
    
    return;
    
}


int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    base_card_set.resize(N); answer.resize(N);
    for (int i=0; i<N; ++i) {
        base_card_set[i] = i+1;
        cin >> answer[i];
    }
    
    while (now_size * 2 < N) {
        now_size *= 2;
        multifle++;
    }
    
    shuffle_deck(base_card_set, false, 0);
    
    cout << result / 10 << " " << result % 10;

    return 0;
}
