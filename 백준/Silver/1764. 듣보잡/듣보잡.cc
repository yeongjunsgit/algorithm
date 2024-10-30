#include <iostream>
#include <unordered_map>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N, M;
    cin >> N >> M;
    string data;
    unordered_map<string, int> match_time;
    vector<string> passed;
    
    for (int i=0; i<N; ++i) {
        cin >> data;
        match_time[data] = 1;
    }
    
    for (int i=0; i<M; ++i) {
        cin >> data;
        if (match_time.find(data) != match_time.end()) {
            passed.push_back(data);
        }
    }
    
    sort(passed.begin(), passed.end());
    
    cout << passed.size() << "\n";
    for (string a : passed) {
        cout << a << "\n";
    }
    

    return 0;
}
