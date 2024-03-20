#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

int main()
{
    int N;
    cin >> N;
    
    vector<vector<int>> arr;
    
    for (int i =0; i<N; ++i) {
        int A, B, C;
        cin >> A >> B >> C;
        
        vector<int> tmp_vec(3);
        tmp_vec[0] = A;
        tmp_vec[1] = B;
        tmp_vec[2] = C;
        
        arr.push_back(tmp_vec);
    }
    
    // sort(arr.begin(), arr.end());
    
    // vector<vector<int>> dp
    int result = 0;    
    int dp[N];
    
    for (int i = 0; i < N; ++i) {
        vector<int> target = arr[i];
        int tmp = target[2];
        int tmp_done = 0;
        
        if (i-2 >= 0) {
            for (int j=0; j <= i-2; ++j) {
                int tmp_sum = tmp + dp[j];
                if (tmp_sum > tmp_done) {
                    tmp_done = tmp_sum;
                }
            }
            dp[i] = tmp_done;
            if (result < tmp_done) {
                result = tmp_done;
            }
        }
        else {
            dp[i] = tmp;
            if (result < tmp) {
                result = tmp;
            }
        }
    }
    
    cout << result;

    return 0;
}
