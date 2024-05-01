#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N;
    cin >> N;
    
    int dp[N+1]{0};
    // 아무것도 못넣은 것도 경우의 수?
    dp[2] = 3;
    
    for (int i=3; i<N+1; ++i) {
        // 홀수일 경우 주어진 타일로는 절대 채울 수 없다 (벽의 넓이가 홀수)
        // 어떤 문제는 못넣은것도 경우의 수라고하고 어떤건 아니고 어이가 없어용!!!
        if (i % 2 == 1) {
            dp[i] = 0;
        }
        // 짝수일때는 2칸의 타일에서 발생할 수 있는 경우는 3개의 경우의수
        // 칸이 2칸 마다 특별한 패턴이 추가됨 (2개)
        // 각 사이즈마다 특별한 패턴을 가능한 만큼 곱한 값을 더해줘야함
        else {
            dp[i] = dp[i-2] * 3 + 2;
            for (int j=4; j<i; j+=2) {
                dp[i] += dp[i-j] * 2;
            } 
        }
    }
    
    cout << dp[N];
    

    return 0;
}
