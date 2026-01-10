#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    int N, M, K;
    cin >> N;
    for (int i=0; i<N; ++i) {
        cin >> M >> K;
        if (M >= K) cout << "MMM BRAINS\n";
        else cout << "NO BRAINS\n";
    }

    return 0;
}
