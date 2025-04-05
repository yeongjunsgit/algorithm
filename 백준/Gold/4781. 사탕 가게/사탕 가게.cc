#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, money, kcal;
double M, candy;

void buy_candy(vector<pair<int, int> >& infos)
{
    vector<int> DP(money + 1, -1);
    DP[0] = 0;
    int best_kcal = 0;
    
    for (int i=0; i<N; ++i) {
        pair<int, int> now_candy = infos[i];
        
        for (int j=1; j<=money; ++j) {
            if (j - now_candy.second >= 0 && DP[j - now_candy.second] != -1) {
                DP[j] = max(DP[j], DP[j - now_candy.second] + now_candy.first);
                best_kcal = max(best_kcal, DP[j]);
            }
        }
    }
    
    cout << best_kcal << "\n";
    
    return;
    
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    while (true) {
        cin >> N >> M;
        if (N == 0 && M == 0) break;
        money = M * 100 + 0.5;
        vector<pair<int, int> > infos;
        for (int i=0; i<N; ++i) {
            cin >> kcal >> candy;
            int price = candy * 100 + 0.5;
            infos.push_back({kcal, price});
        }
        
        buy_candy(infos);
    }

    return 0;
}
