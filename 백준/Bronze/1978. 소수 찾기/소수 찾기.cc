#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

int main()
{
    int N;
    int result = 0;
    cin >> N;
    cin.ignore();
    
    vector<int> dp(1001, 0);
    
    for (int i=2; i<=1000; ++i) {
        if (dp[i] == 0) {
            dp[i] = 1;
            int my_baesu = i;
            int idx = 2;
            while (my_baesu * idx <= 1000) {
                dp[my_baesu * idx] = 2;
                idx++;
            }
        }
    }

    string data;
    int num;
    getline(cin, data);
    istringstream iss(data);
    while (iss >> num) {
        if (dp[num] == 1) {
            result++;
        }
    }
    
    cout << result;

    return 0;
}
