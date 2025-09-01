#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    float guard, piercing;
    cin >> guard >> piercing;
    
    float monster = guard - (guard * piercing / 100);
    
    if (monster < 100) cout << 1;
    else cout << 0;

    return 0;
}