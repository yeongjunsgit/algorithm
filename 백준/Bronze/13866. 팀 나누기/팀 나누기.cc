#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    vector<int> numbers(4);
    for (int i=0; i<4; ++i) {
        cin >> numbers[i];
    }
    sort(numbers.begin(), numbers.end(), less<int>());
    
    cout << abs( (numbers[0] + numbers[3]) - (numbers[1] + numbers[2]) );
    

    return 0;
}