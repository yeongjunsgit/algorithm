#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N;
    double water;
    cin >> N >> water;
    
    double leaf_node = 0.0;
    
    bool isleaf[N+1]{false};
    bool counted[N+1]{false};
    
    for (int i=1; i<N; ++i) {
        int s, e;
        cin >> s >> e;
        
        if (isleaf[s] == false && counted[s] == false && s != 1) {
            isleaf[s] = true;
            leaf_node += 1;
        }
        else if (isleaf[s] == true && counted[s] == false && s != 1) {
            leaf_node -= 1;
            counted[s] = true;
        }
        
        if (isleaf[e] == false && counted[e] == false && e != 1) {
            leaf_node += 1;
            isleaf[e] = true;
        }
        else if (isleaf[e] == true && counted[e] == false && e != 1) {
            leaf_node -= 1;
            counted[e] = true;
        }

    }
    
    double result = round((water / leaf_node) * 1e10) / 1e10;
    
    cout << fixed << setprecision(10) << result;

    return 0;
}
