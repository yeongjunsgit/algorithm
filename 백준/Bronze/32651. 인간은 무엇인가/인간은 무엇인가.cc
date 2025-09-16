#include <iostream>

using namespace std;

int main()
{
    int N;
    cin >> N;
    
    if (N % 2024 == 0 && N <= 100000) cout << "Yes";
    else cout << "No";

    return 0;
}
