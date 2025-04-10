#include <iostream>

using namespace std;

int main()
{
    int N;
    cin >> N;
    
    if (N == 64) {
        cout << 1;
    }
    else {
        int idx = 0;
        int stick = 64;
        
        while (N > 0) {
            int new_stick = stick / 2;
            if (new_stick <= N) {
                N -= new_stick;
                idx++;
            }
            stick = new_stick;
        }
        cout << idx;
    }
    return 0;
}
