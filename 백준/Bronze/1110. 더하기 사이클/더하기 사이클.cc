#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    string N;
    cin >> N;
    
    int A, B;
    
    if (N.size() == 1) {
        A = 0;
        B = stoi(N);
    }
    
    else {
        int p = 0;
        for (int c : N) {
            if (p == 0) {
                A = (c - '0');
                p += 1;
            }
            else {
                B = (c - '0');
            }
        }
    }
    
    int progressing = 0;
    
    while (true) {
        progressing += 1;
        
        int sum_AB = A + B;
        int tmp_A = sum_AB % 10;
        int tmp = (B * 10) + tmp_A;
        
        string tmp_N = to_string(tmp);
        if (tmp_N == N) {
            cout << progressing;
            break;
        }
        
        else {
            A = B;
            B = tmp_A;
        }
    }

    return 0;
}
