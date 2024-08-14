#include <iostream>

using namespace std;

int main()
{
    int N;
    cin >> N;
    
    long long start = 1;
    
    for (int i=1; i<=N; ++i) {
        start *= i;
    }

    cout << start;

    return 0;
}