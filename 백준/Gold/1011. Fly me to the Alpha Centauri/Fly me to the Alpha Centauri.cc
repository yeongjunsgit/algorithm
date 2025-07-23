#include <iostream>

using namespace std;

int T;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> T;
    int s, e;
    for (int t=0; t<T; ++t) {
        int result = 0;
        cin >> s >> e;
        int tmp = e - s, power = 2;
        if (tmp == 1) {
            result = 1;
        }
        else {
            while (tmp > 0) {
                if (power <= tmp) {
                    tmp -= power;
                    result += 2;
                    power += 2;
                }
                else {
                    if (power / 2 >= tmp) result++;
                    else result += 2;
                    tmp = 0;
                }
            }
        }
        
        cout << result << "\n";
        
    }

    return 0;
}