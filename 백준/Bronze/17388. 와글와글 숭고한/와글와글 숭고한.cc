#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int S, K, H;
    cin >> S >> K >> H;
    if (S + K + H >= 100) {
        cout << "OK";
    }
    else {
        if (min({S, K, H}) == S) cout << "Soongsil";
        else if (min({S, K, H}) == K) cout << "Korea";
        else cout << "Hanyang";
    }

    return 0;
}