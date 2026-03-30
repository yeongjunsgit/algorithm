#include <iostream>
#include <string>

using namespace std;

int main()
{
    string a, b;
    cin >> a >> b;
    
    int N = a.size(), M = b.size(), cnt = 0;
    
    if (M > N) cout << 0;
    else {
        int cnt = 0;
        for (int i=0; i<N; ++i) {
            if (a[i] == b[i]) {
                if (a[i] == '8') {
                    cnt++;
                }
                
            }
            else break;
        }
        
        cout << cnt;
    }
    
    

    return 0;
}
