#include <iostream>
#include <vector>
#include <utility>
#include <sstream>

using namespace std;

int main()
{
    int N;
    cin >> N;
    
    cin.ignore();
    
    string data;
    getline(cin, data);
    
    istringstream iss(data);
    int num;
    
    vector<int> numbers;
    
    while (iss >> num) {
        numbers.push_back(num);
    }
    
    // 맨처음 dp는 입력
    vector<pair<int, int>> dp;
    dp.push_back({numbers[0], numbers[0]});
    
    // 결과값을 담은 변수 저장
    int result = numbers[0];
    
    // 계속해서 진행하면서 자신의 뒤에서 현재 위치에서 넣을 수 있는 수들의 합 중 최대 값을 저장
    for (int i=1; i<N; ++i) {
        int tmp_max = numbers[i];
        for (int j=0; j<i; ++j) {
            if (dp[j].first < numbers[i]) {
                int tmp = dp[j].second + numbers[i];
                if (tmp_max < tmp) {
                    tmp_max = tmp;
                }
            }
        }
        
        dp.push_back({numbers[i], tmp_max});
        if (result < tmp_max) {
            result = tmp_max;
        }
    }

    cout << result;

    return 0;
}
