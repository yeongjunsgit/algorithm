#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

struct Compare {
    bool operator()(const string& a, const string& b) {
        if (a.size() == b.size()) {
            return a < b;
        }
        else {
            return a.size() < b.size();
        }
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N;
    cin >> N;
    
    string data;
    unordered_map<string, bool> multi_check;
    vector<string> sentence;
    
    for (int i=0; i<N; ++i) {
        cin >> data;
        
        if (multi_check.find(data) == multi_check.end()) {
            sentence.push_back(data);
            multi_check[data] = true;
        }
        
    }
    
    sort(sentence.begin(), sentence.end(), Compare());
    
    for (auto a : sentence) {
        cout << a << "\n";
    }

    return 0;
}
