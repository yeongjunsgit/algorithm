/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

using namespace std;

int main()
{
    int N, num1, num2;
    cin >> N;
    
    for (int i=1; i<=N; ++i) {
        cin >> num1 >> num2;
        cout << "Case " << i << ": " << num1 + num2 << "\n";
    }

    return 0;
}