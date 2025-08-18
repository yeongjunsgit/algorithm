#include <iostream>

using namespace std;

int main()
{
    int A, B, chicken;
    cin >> A >> B >> chicken;
    if (chicken * 2 > A + B) cout << A + B;
    else cout << A + B - chicken * 2;
    

    return 0;
}