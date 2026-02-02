#include <iostream>
#include <vector>
#include <unordered_map>

#define pss pair<string, string>

using namespace std;

int N;
unordered_map<string, vector<string> > couple_match;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    string now_name, now_ring;
    for (int i=0; i<N; ++i) {
        cin >> now_name >> now_ring;
        if (now_ring != "-") {
            couple_match[now_ring].push_back(now_name);
        }
    }
    int cnt = 0;
    vector<pss> matched;
    for (auto a : couple_match) {
        if (a.second.size() == 2) {
            cnt++;
            matched.push_back({a.second[0], a.second[1]});
        }
    }
    
    cout << cnt << "\n";
    for (auto a : matched) {
        cout << a.first << " " << a.second << "\n";
    }
    

    return 0;
}
