#include <iostream>

using namespace std;

int main()
{
    int A, B, K, X;
    cin >> A >> B >> K >> X;
    
    if (B < K - X || A > K + X) cout << "IMPOSSIBLE";
    else {
        int result = min(B, K + X) - max(A, K - X) + 1;
        cout << result;
    }
    return 0;
}
