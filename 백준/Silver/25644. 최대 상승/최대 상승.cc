#include <iostream>
#include <vector>

using namespace std;

int N, result = 0;
vector<int> day_price(200000), future_best(200000, 0);

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    for (int i=0; i<N; ++i) {
        cin >> day_price[i];
    }
    future_best[N-1] = day_price[N-1];
    for (int i=N-2; i>=0; --i) {
        future_best[i] = max(future_best[i+1], day_price[i]);
        int tmp = future_best[i] - day_price[i];
        result = max(result, tmp);
    }
    
    cout << result;

    return 0;
}
