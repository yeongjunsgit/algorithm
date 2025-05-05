#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main()
{
    unordered_map<int, int> x_loca, y_loca;
    int N, M;
    for (int i=0; i<3; ++i) {
        cin >> N >> M;
        x_loca[N]++;
        y_loca[M]++;
    }
    
    for (auto a : x_loca) {
        if (a.second == 1) cout << a.first << " ";
    }
    for (auto a : y_loca) {
        if (a.second == 1) cout << a.first << " ";
    }

    return 0;
}