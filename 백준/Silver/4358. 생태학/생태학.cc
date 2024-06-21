#include <iostream>
#include <iomanip>
#include <vector>
#include <map>
#include <cmath>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie();
    
    int trees = 0;
    string data;
    map<string, double> kind_tree;
    
    while (getline(cin, data)) {
        trees += 1;
        
        if (kind_tree.find(data) == kind_tree.end()) {
            kind_tree[data] = 1;
        }
        else {
            kind_tree[data] += 1;
        }
    }
    
    for (const auto& T : kind_tree) {
        double tmp = T.second / trees * 100;
        double roundedValue = round(tmp * 10000) / 10000;
        
        cout << T.first << " " << fixed << setprecision(4) << roundedValue << "\n";
    }

    return 0;
}
