#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    for (int i=0; i<3; ++i) {
        int cnt = 0, num;
        for (int j=0; j<4; ++j) {
            cin >> num;
            cnt += num;
        }
        if (cnt == 0) cout << "D\n";
        else if (cnt == 1) cout << "C\n";
        else if (cnt == 2) cout << "B\n";
        else if (cnt == 3) cout << "A\n";
        else if (cnt == 4) cout << "E\n";
    }    
    
    

    return 0;
}
