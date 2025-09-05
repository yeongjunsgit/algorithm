#include <iostream>

using namespace std;

int main()
{
    int N, M, A, B;
    cin >> N >> M >> A >> B;
    
    int need_chair = (N * 3) - M;
    if (need_chair > 0) cout << need_chair * A + B;
    else cout << 0;

    return 0;
}
