#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int N;

int check_money(int total_money, vector<int>& coins, unordered_map<int, int>& coins_cnt)
{
    int half_money = total_money / 2;
    vector<vector<int> > dp(N, vector<int>(50001, 0));
    
    for (int i=0; i<N; ++i) {
        int repeat = coins_cnt[coins[i]];
        if (i == 0) {
            dp[i][0] = 1;
            for (int j=1; j<=repeat; ++j) {
                int tmp = coins[i] * j;
                if (tmp <= 50000) {
                    dp[i][tmp] = 1;
                    if (tmp == half_money) {
                        return 1;
                    }
                }
            }
        }
        else {
            for (int j=0; j<=50000; ++j) {
                if (dp[i-1][j] == 1) {
                    dp[i][j] = 1;
                }
                else {
                    for (int k=1; k<=repeat; ++k) {
                        int tmp = coins[i] * k;
                        if (j - tmp >= 0) {
                            if (dp[i-1][j - tmp] == 1) {
                                dp[i][j] = 1;
                                if (j == half_money) {
                                    return 1;
                                }
                                break;
                            }
                        }
                        else {
                            break;
                        }
                    }
                }
            }
        }
    }
    
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    for (int t=0; t<3; ++t) {
        cin >> N;
        int total_money = 0;
        vector<int> coins;
        unordered_map<int, int> coins_cnt;
        int coin, cnt;
        for (int i=0; i<N; ++i) {
            cin >> coin >> cnt;
            total_money += (coin * cnt);
            coins.push_back(coin);
            coins_cnt[coin] = cnt;
        }
        
        if (total_money % 2 == 0) {
            cout << check_money(total_money, coins, coins_cnt) << "\n";
        }
        else {
            cout << 0 << "\n";
        }
    }

    return 0;
}