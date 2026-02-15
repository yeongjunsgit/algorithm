#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int Y, C, P;
    cin >> Y >> C >> P;
    
    cout << min({Y, C / 2, P});

    return 0;
}
