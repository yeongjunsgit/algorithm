#include <iostream>

using namespace std;

int main()
{
    int N, M;
    cin >> N >> M;
    
    int need = N / M;
    if (N % M != 0) need++;
    
    cout << need;
    

    return 0;
}
