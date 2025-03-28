#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int sum, gap;
    cin >> sum >> gap;
    int x = (sum + gap) / 2;
    int y = sum - x;
    
    if (x + y == sum && abs(x - y) == gap && x >= 0 && y >= 0) {
        cout << max(x, y) << " " << min(x, y);
    }
    else {
        cout << -1;
    }

    return 0;
}