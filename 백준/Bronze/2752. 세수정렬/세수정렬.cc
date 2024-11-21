#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int num;
    vector<int> numbers;
    for (int i=0; i<3; ++i) {
        cin >> num;
        numbers.push_back(num);
    }
    
    sort(numbers.begin(), numbers.end());
    
    for (int a : numbers) {
        cout << a << " ";
    }

    return 0;
}
