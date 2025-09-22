#include <iostream>

using namespace std;

int main()
{
    long long N, M, S, N_price, M_price;
    cin >> N >> M >> S;
    S *= 100;
    N_price = (S - (S * N / 100) ) * (M + 1);
    M_price = M * S;
    
    cout << min(N_price / 100, M_price / 100);
    
    return 0;
}