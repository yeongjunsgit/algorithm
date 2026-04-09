#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N, per, water, ramen_cnt;
    cin >> N;
    for (int i=0; i<N; ++i) {
        cin >> per >> water >> ramen_cnt;
        cout << per * (ramen_cnt - 1) + water << "\n";
        
    }
    
    return 0;
}
