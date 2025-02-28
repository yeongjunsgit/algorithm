#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    
    int N, target, num;
    cin >> N >> target;
    
    int result = 0;
    vector<int> coins;
    for (int i=0; i<N; ++i) {
        cin >> num;
        coins.push_back(num);
    }
    
    for (int i=N-1; i>=0; --i) {
        if (coins[i] <= target) {
            result += target / coins[i];
            target %= coins[i];
        }
    }

    cout << result;

    return 0;
}
