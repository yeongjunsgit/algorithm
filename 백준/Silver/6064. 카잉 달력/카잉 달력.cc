#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int T, M, N, x, y;

void solution()
{
    cin >> M >> N >> x >> y;
    if (M < N) {
        swap(M, N);
        swap(x, y);
    }
    int s = 1, e = 1;
    long long result = 1;
    
    while (true) {
        int tmp = e + (x-s);
        if (tmp > N) {
            while (tmp > N) {
                tmp -= N;
            }
        }
        if (tmp == y) {
            result += x-s;
            break;
        }
        else {
            result += M;
            e = (e + M) - N;
            if (e > N) {
                while (e > N) {
                    e -= N;
                }
            }
            
            if (s == 1 && e == 1) {
                result = -1;
                break;
            }
        }
    }
    
    cout << result << "\n";
    
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> T;
    
    for (int t=0; t<T; ++t) {
        solution();
    }

    return 0;
}
