#include <iostream>

using namespace std;

int N, left_money, cnt = 0;

void check_coin(int target)
{
    if (left_money >= target) {
        cnt += left_money / target;
        left_money %= target;
    }
    
    return;
}

int main()
{
    cin >> N;
    left_money = 1000 - N;
    check_coin(500);
    check_coin(100);
    check_coin(50);
    check_coin(10);
    check_coin(5);
    check_coin(1);
    
    cout << cnt;

    return 0;
}
