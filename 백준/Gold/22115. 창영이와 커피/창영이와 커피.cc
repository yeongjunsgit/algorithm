#include <iostream>
#include <vector>

using namespace std;

int N, K;
vector<int> coffee_select(100001, 111), caffeine(100);

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> K;
    for (int i=0; i<N; ++i) {
        cin >> caffeine[i];
    }
    coffee_select[0] = 0;
    for (int i=0; i<N; ++i) {
        for (int j=K; j>=0; --j) {
            if (coffee_select[j] > -1 && j + caffeine[i] <= K && coffee_select[j + caffeine[i]] > coffee_select[j] + 1) {
                coffee_select[j + caffeine[i]] = coffee_select[j] + 1;
            } 
        } 
    }
    
    if (coffee_select[K] == 111) cout << -1;
    else cout << coffee_select[K];

    return 0;
}

