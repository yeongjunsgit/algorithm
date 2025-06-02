#include <iostream>
#include <vector>
#include <cmath>

#define pll pair<int, int>

using namespace std;

int D, N;
vector<int> days_temperature(201, 0);
vector<pair<int, pll> > clothes(201);

int get_best_p()
{
    int result = 0;
    vector<vector<int> > DP(D, vector<int>(101, -1));
    for (int j=0; j<N; ++j) {
        if (days_temperature[0] >= clothes[j].second.first && days_temperature[0] <= clothes[j].second.second) {
            DP[0][clothes[j].first] = 0;
        }
    }
    
    for (int i=1; i<D; ++i) {
        for (int j=0; j<N; ++j) {
            if (days_temperature[i] >= clothes[j].second.first && days_temperature[i] <= clothes[j].second.second) {
                for (int k=0; k<=100; ++k) {
                    if (DP[i-1][k] != -1) {
                        DP[i][clothes[j].first] = max(DP[i][clothes[j].first], DP[i-1][k] + abs(k - clothes[j].first));
                    }
                }
            }
        }
    }
    
    for (int i=0; i<=100; ++i) {
        result = max(result, DP[D-1][i]);
    }
    
    return result;
    
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> D >> N;
    int s, e, p;
    for (int i=0; i<D; ++i) {
        cin >> days_temperature[i];
    }
    
    for (int i=0; i<N; ++i) {
        cin >> s >> e >> p;
        clothes[i] = {p, {s, e}};
    }
    
    cout << get_best_p();
    
    return 0;
}
