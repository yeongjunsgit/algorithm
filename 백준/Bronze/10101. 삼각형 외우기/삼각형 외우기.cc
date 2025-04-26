#include <iostream>

using namespace std;

int main()
{
    int one, two, three;
    cin >> one >> two >> three;
    
    int sum = one + two + three;
    
    if (sum == 180) {
        if (one == two && one == three) cout << "Equilateral";
        else if (one == two || two == three || one == three) cout << "Isosceles";
        else cout << "Scalene";
    }
    else cout << "Error";

    return 0;
}