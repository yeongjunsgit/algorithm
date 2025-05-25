#include <iostream>

using namespace std;

int main()
{
    string N;
    while (true) {
        int cnt = 1;
        cin >> N;
        if (N == "0") break;
        for (char c : N) {
            cnt++;
            if (c == '1') cnt += 2;
            else if (c == '0') cnt += 4; 
            else cnt += 3;
        }
        
        cout << cnt << "\n";
    }

    return 0;
}