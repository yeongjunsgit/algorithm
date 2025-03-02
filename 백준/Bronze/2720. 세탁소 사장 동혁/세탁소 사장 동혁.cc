#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    int T, C;
    cin >> T;
    
    for (int t=0; t<T; ++t) {
        cin >> C;
        int Q = 0, D = 0, N = 0, P = 0;
        
        while (C > 0) {
            if (C >= 25) {
                Q += C / 25;
                C %= 25;
            }
            else if (C >= 10) {
                D += C / 10;
                C %= 10;
            }
            else if (C >= 5) {
                N += C / 5;
                C %= 5;
            }
            else if (C >= 1) {
                P += C / 1;
                C %= 1;
            }
        }
        
        cout << Q << " " << D << " " << N << " " << P << "\n";
        
    }
    
    return 0;
}
