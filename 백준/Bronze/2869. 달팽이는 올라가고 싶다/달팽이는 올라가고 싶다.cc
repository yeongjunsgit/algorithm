#include <iostream>

using namespace std;

int A, B, V;

int main()
{
    cin >> A >> B >> V;
    
    int day_power = A - B;
    int goal = V - A;
    int result = 1;
    
    if (goal > 0) {
        int tmp = goal / day_power;
        if (goal % day_power != 0) {
            tmp++;
        }
        result += tmp;
    }
    
    cout << result;

    return 0;
}