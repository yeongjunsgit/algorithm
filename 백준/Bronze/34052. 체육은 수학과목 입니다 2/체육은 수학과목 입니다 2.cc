#include <iostream>

using namespace std;

int main()
{
    int N, num = 300;
    for (int i=0; i<4; ++i) {
        cin >> N;
        num += N;
    }
    
    if (num <= 1800) cout << "Yes";
    else cout << "No";

    return 0;
}