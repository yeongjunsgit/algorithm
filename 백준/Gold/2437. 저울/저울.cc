#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<int> weights;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    int num;
    bool can_start = false;
    
    for (int i=0; i<N; ++i) {
        cin >> num;
        weights.push_back(num);
        if (num == 1) {
            can_start = true;
        }
    }
    
    sort(weights.begin(), weights.end());
    
    int start = 1;
    for (int i=0; i<N; ++i) {
        if (start < weights[i]) {
            break;
        }
        else {
            start += weights[i];
        }
    }
    
    cout << start;

    return 0;
}
