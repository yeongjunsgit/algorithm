#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Compare {
    bool operator()(const pair<int, string>& a, const pair<int, string>& b) {
        return a.first < b.first;
    }  
};

int N;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> N;
    
    int age;
    string nickname;
    vector<pair<int, string> > visitor;
    
    for (int i=0; i<N; ++i) {
        cin >> age >> nickname;
        
        visitor.push_back({age, nickname});
    }
    
    stable_sort(visitor.begin(), visitor.end(), Compare());
    
    for (auto a : visitor) {
        cout << a.first << " " << a.second << "\n";
    }

    return 0;
}
