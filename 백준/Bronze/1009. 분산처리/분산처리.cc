/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <cmath>

using namespace std;

int T;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> T;
    
    int a, b;
    
    for (int t=0; t<T; ++t) {
        cin >> a >> b;
        
        int tmp = a % 10;
        int target, result;
        if (tmp == 1 || tmp == 5 || tmp == 6) {
            cout << tmp << "\n";
        }
        else if (tmp == 2 || tmp == 3 || tmp == 7 || tmp == 8) {
            target = b % 4;
            if (target == 0) {
                target = 4;
            }
            
            result = pow(tmp, target);
            result %= 10;
            cout << result << "\n";
            
        }
        else if (tmp == 4 || tmp == 9) {
            target = b % 2;
            if (target == 0) {
                target = 2;
            }
            
            result = pow(tmp, target);
            result %= 10;
            cout << result << "\n";
        }
        else {
            cout << 10 << "\n";
        }
    }

    return 0;
}