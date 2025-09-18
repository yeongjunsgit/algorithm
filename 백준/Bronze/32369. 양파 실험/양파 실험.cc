#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int N, A, B, good_onion = 1, bad_onion = 1;
    cin >> N >> A >> B;
    
    for (int i=0; i<N; ++i) {
        good_onion += A;
        bad_onion += B;
        
        if (good_onion < bad_onion) swap(good_onion, bad_onion);
        else if (good_onion == bad_onion) bad_onion -= 1;
        
    }

    cout << good_onion << " " << bad_onion << "\n";

    return 0;
}
