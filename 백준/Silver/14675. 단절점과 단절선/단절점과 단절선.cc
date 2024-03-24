#include <iostream>
#include <vector>
#include <utility>
#include <sstream>

using namespace std;

int main()
{
    // 빠른 입출력을 위한 코드!
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N;
    cin >> N;
    
    vector<pair<int, int>> layers;
    
    vector<int> tree[N+1];
    
    for (int i=0; i<N-1; ++i) {
        int n1, n2;
        cin >> n1 >> n2;
        pair<int, int> layer = {n1, n2};
        
        layers.push_back(layer);
        
        tree[n1].push_back(n2);
        tree[n2].push_back(n1);
    }
    
    
    int K;
    cin >> K;
    
    for (int i=0; i<K; ++i) {
        int c1, c2;
        cin >> c1 >> c2;
        
        if (c1 == 1) {
            if (tree[c2].size() >= 2) {
                cout << "yes";
            }
            else {
                cout << "no";
            }
        }
        else if (c1 == 2) {
            cout << "yes";
        }
        cout << "\n";
    }

    return 0;
}