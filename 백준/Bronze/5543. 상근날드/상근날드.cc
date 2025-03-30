#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int s, j, h, coke, cider;
    cin >> s >> j >> h >> coke >> cider;
    
    int drink = min(coke, cider);
    int burger = min({s, j, h});
    
    cout << drink + burger - 50;

    return 0;
}