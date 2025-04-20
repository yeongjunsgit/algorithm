#include <iostream>

using namespace std;

int main()
{
    int num, sum1 = 0, sum2 = 0;
    for (int i=0; i<4; ++i) {
        cin >> num;
        sum1 += num;
    }
    for (int i=0; i<4; ++i) {
        cin >> num;
        sum2 += num;
    }

    cout << max(sum1, sum2);

    return 0;
}