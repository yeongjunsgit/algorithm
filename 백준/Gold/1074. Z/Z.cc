/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>

using namespace std;

int N, nx, ny;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    cin >> N >> ny >> nx;
    int result = 0;
    while (nx > 0) {
        int x_line = 1; 
        while (true) {
            if (x_line * 2 <= nx) x_line *= 2;
            else break;
        }
        result += x_line * x_line;
        nx -= x_line;
    }
    while (ny > 0) {
        int y_line = 1;
        while (true) {
            if (y_line * 2 <= ny) y_line *= 2;
            else break;
        }
        result += y_line * y_line * 2;
        ny -= y_line;
    }
    
    cout << result;
    
    return 0;
}
