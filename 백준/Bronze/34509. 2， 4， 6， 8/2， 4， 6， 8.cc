#include <iostream>

using namespace std;

int main()
{
    for (int i=10; i<=99; ++i) {
        int reverse_tmp = (i % 10 * 10) + (i / 10);
        if (reverse_tmp % 4 == 0) {
            int each_tmp = (i / 10) + (i % 10);
            if (each_tmp % 6 == 0) {
                if (i / 10 != 8 && i % 10 != 8) {
                    cout << i;
                    break;
                }
            }
        }
    }

    return 0;
}