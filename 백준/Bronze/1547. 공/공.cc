#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    vector<int> cups(4, 0);
    cups[1] = 1;
    int N, s, e;
    cin >> N;
    for (int i=0; i<N; ++i) {
        cin >> s >> e;
        swap(cups[s], cups[e]);
    }
    
    for (int i=1; i<=3; ++i) {
        if (cups[i] == 1) {
            cout << i;
            break;
        }
    }

    return 0;
}