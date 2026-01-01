#include <iostream>
#include <vector>
#include <map>

using namespace std;

int T, N;


int get_waiting_time(vector<char>& now_waiting, map<char, int>& char_cnt)
{
    map<char, int> now_cnt;
    int waiting_people = 0, waiting_time = 0;
    for (char c : now_waiting) {
        waiting_time += waiting_people * 5;
        now_cnt[c]++;
        if (now_cnt[c] == char_cnt[c]) waiting_people -= char_cnt[c];
    }
    
    return waiting_time;
    
}


int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> T;
    for (int t=0; t<T; ++t) {
        cin >> N;
        vector<char> waiting_people(N), sorted_people;        
        map<char, int> char_cnt;
        for (int i=0; i<N; ++i) {
            cin >> waiting_people[i];
            char_cnt[waiting_people[i]]++;
        }
        for (auto a : char_cnt) {
            for (int i=0; i<a.second; ++i) {
                sorted_people.push_back(a.first);
            }
        }
        
        cout << get_waiting_time(waiting_people, char_cnt) - get_waiting_time(sorted_people, char_cnt) << "\n";
        
        
    }
    
    return 0;
}
