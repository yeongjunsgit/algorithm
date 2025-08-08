#include <iostream>

using namespace std;

int N, M, K;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M >> K;
    cout << K / M << " " << K % M;
    
    return 0;
}