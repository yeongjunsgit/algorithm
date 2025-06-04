#include <iostream>

using namespace std;

int main()
{
    int one, two, three;
    cin >> one >> two >> three;
    
    int front_dist = two - one - 1;
    int back_dist = three - two - 1;
    
    cout << max(front_dist, back_dist);

    return 0;
}