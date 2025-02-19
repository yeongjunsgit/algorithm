#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

int T, F;

string find_root(string now, unordered_map<string, string>& parents)
{
    if (parents[now] == now) {
        return parents[now];
    }
    
    return parents[now] = find_root(parents[now], parents);
}


void union_root(string x, string y, unordered_map<string, string>& parents, unordered_map<string, int>& parents_power)
{
    string rx = find_root(x, parents);
    string ry = find_root(y, parents);
    
    if (rx == ry) {
        cout << parents_power[rx] << "\n";
        return;
    }
    
    if (rx > ry) {
        swap(rx, ry);
    }
    
    parents[ry] = rx;
    parents_power[rx] += parents_power[ry];
    
    cout << parents_power[rx] << "\n";
    
    return;
    
}


int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    cin >> T;
    
    for (int t=0; t<T; ++t) {
        cin >> F;
        unordered_map<string, string> parents;
        unordered_map<string, int> parents_power;
        
        string s, e;
        for (int f=0; f<F; ++f) {
            cin >> s >> e;
            if (parents.find(s) == parents.end()) {
                parents[s] = s;
                parents_power[s] = 1;
            }
            if (parents.find(e) == parents.end()) {
                parents[e] = e;
                parents_power[e] = 1;
            }
            
            union_root(s, e, parents, parents_power);
            
        }
        
    }

    return 0;
}
