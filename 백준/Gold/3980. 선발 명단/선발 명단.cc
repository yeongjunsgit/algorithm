#include <iostream>
#include <vector>
#include <map>

using namespace std;

void combinations(vector<vector<int>>& peoples, vector<bool>& used, vector<bool>& card_set, map<int, vector<int>>& able_idx, vector<int>& combi, int& result, int idx) {
    if (idx == 11) {
        int tmp = 0;
        for (int i=0; i<11; ++i) {
            tmp += combi[i];
        }
        if (result < tmp) {
            result = tmp;
        }
        return;
    }
    
    else {
        if (card_set[idx] == true) {
            combinations(peoples, used, card_set, able_idx, combi, result, idx + 1);
        }
        else {
            for (int num : able_idx[idx]) {
                if (used[num] == false) {
                    used[num] = true;
                    card_set[idx] = true;
                    combi[idx] = peoples[num][idx];
                    combinations(peoples, used, card_set, able_idx, combi, result, idx + 1);
                    used[num] = false;
                    card_set[idx] = false;
                    combi[idx] = 0;
                }
                else {
                    continue;
                }
            }
        }
        return;
    }
    
}

int main()
{
    int T;
    cin >> T;
    
    for (int t=0; t<T; ++t) {
        vector<vector<int>> peoples;
        int result = 0;
        vector<bool> used(11, false);
        vector<bool> card_set(11, false);
        map<int, vector<int>> able_idx;
        vector<int> combi(11, 0);
        
        int num;
        for (int e=0; e<11; ++e) {
            vector<int> person;
            int zero_back = 0;
            for (int i=0; i<11; ++i) {
                cin >> num;
                person.push_back(num);
                if (num == 0) {
                    zero_back += 1;
                }
                else {
                    if (able_idx.find(i) == able_idx.end()) {
                        able_idx[i] = {e};
                    }
                    else {
                        able_idx[i].push_back(e);
                    }
                }
            }
            
            if (zero_back == 10) {
                for (int i=0; i<11; ++i) {
                    if (person[i] != 0) {
                        used[e] = true;
                        card_set[i] = true;
                        combi[i] = person[i];
                    }
                }
            }
            
            peoples.push_back(person);
            
        }
        
        combinations(peoples, used, card_set, able_idx, combi, result, 0);
        
        cout << result << "\n";
        
    }

    return 0;
}
