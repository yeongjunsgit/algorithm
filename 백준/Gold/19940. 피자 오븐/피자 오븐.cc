#include <iostream>
#include <vector>

using namespace std;

int T, N;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> T;
    for (int t=0; t<T; ++t) {
        cin >> N;
        vector<int> now = {0, 0, 0, 0, 0};
        if (N >= 60) {
            int power = N / 60;
            now[0] += power;
            N %= 60;
        }
        
        if (N > 35) {
            now[0]++;
            int tmp = 60;
            int tmp_N = N;
            
            while (tmp > tmp_N) {
                tmp -= 10;
                now[2]++;
                if (tmp < tmp_N) {
                    if (N % 10 >= 5) {
                        tmp += 10;
                        now[2]--;
                    }
                    break;
                }
            }
            N %= 10;
            
            if (N < 5) {
                now[3] += N;
            }
            else {
                now[4] += 10 - N;
            }
        }
        else {
            now[1] += N / 10;
            N %= 10;
            
            if (N <= 5) {
                now[3] += N;
            }
            else {
                now[1]++;
                now[4] += 10 - N;
            }
        }
        
        for (int a : now) {
            cout << a << " ";
        }
        cout << "\n";
        
    }
    
    return 0;
}
