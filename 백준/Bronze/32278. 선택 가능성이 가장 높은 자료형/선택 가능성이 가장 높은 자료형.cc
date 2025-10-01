#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    long long N;
    cin >> N;
    if (-32768 <= N && N <= 32767) cout << "short";
    else if (-2147483648 <= N && N <= 2147483647) cout << "int";
    else cout << "long long";

    return 0;
}