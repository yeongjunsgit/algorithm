#include <iostream>

using namespace std;

int N, M, K;

int main()
{
    cin >> N >> M >> K;
    int O = M, X = N - M;
    int OO = min(O, K), XX = min(X, N - K);
    
    cout << OO + XX;

    return 0;
}