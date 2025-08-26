#include <iostream>

using namespace std;

int main()
{
    long long a, b, c;
    cin >> a >> b >> c;
    long long result = a * max(b, c) / min(b, c);
    cout << result;

    return 0;
}