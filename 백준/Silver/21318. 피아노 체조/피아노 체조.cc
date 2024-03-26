#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N;
    cin >> N;
    
    cin.ignore();
    
    string data;
    getline(cin, data);
    
    istringstream iss(data);
    int num;
    
    int numbers[N];
    int idx = 0;
    
    while (iss >> num) {
        numbers[idx] = num;
        idx += 1;
    }
    
    int Q;
    cin >> Q;
    
    int dp[N+1];
    dp[0] = 0;
    
    for (int i = 1; i<N; ++i) {
        if (numbers[i-1] > numbers[i]) {
            dp[i] = dp[i-1] + 1;
        }
        else {
            dp[i] = dp[i-1];
        }
    }
    
    dp[N] = dp[N-1];
    
    for (int i = 0; i<Q; ++i) {
        int start, over;
        cin >> start >> over;
        
        if (over + 1 <= N) {
            if (numbers[over-1] > numbers[over]) {
                cout << dp[over] - dp[start-1] - 1 << "\n";
            }
            else {
                cout << dp[over] - dp[start-1] << "\n";
            }
        }
        else {
            cout << dp[over] - dp[start-1] << "\n";
        }
        
    }

    return 0;
}
