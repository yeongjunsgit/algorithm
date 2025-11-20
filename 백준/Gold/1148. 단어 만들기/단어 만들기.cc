#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
#include <algorithm>

using namespace std;

vector<unordered_map<char, int> > sentences(200001);

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    string data; int idx = 0;
    while (true) {
        cin >> data;
        idx++;
        if (data == "-") break;
        for (char c : data) {
            sentences[idx][c]++;
        }
    }
    while (true) {
        cin >> data;
        if (data == "#") break;
        unordered_map<char, int> now_match; set<char> c_set; int best = 0, worst = 99999999; vector<char> best_list, worst_list; vector<int> make_idx;
        for (char c : data) {
            now_match[c]++;
            c_set.insert(c);
        }
        
        for (int i=1; i<=idx; ++i) {
            bool is_make = true;
            for (auto tmp : sentences[i]) {
                if (now_match[tmp.first] < tmp.second) {
                    is_make = false;
                    break;
                }
            }
            if (is_make) make_idx.push_back(i);
        }
        
        for (char target : c_set) {
            int matching = 0;
            for (int i : make_idx) {
                if (sentences[i].find(target) == sentences[i].end()) continue;
                else matching++;
            }
            if (matching > best) {
                best = matching;
                best_list = {target};
            }
            else if (matching == best) {
                best_list.push_back(target);
            }
            
            if (matching < worst) {
                worst = matching;
                worst_list = {target};
            }
            else if (matching == worst) {
                worst_list.push_back(target);
            }
        }
        
        sort(best_list.begin(), best_list.end());
        sort(worst_list.begin(), worst_list.end());
        
        for (char c : worst_list) {
            cout << c;
        }
        cout << " " << worst << " ";
        for (char c : best_list) {
            cout << c;
        }
        cout << " " << best << "\n";
    }
    
    return 0;
}
