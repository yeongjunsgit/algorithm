#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    string data;
    cin >> data;
    
    vector<char> nums;
    
    for (char a : data) {
        nums.push_back(a);
    }
    
    sort(nums.begin(), nums.end(), greater<int>());
    
    for (char a : nums) {
        cout << a;
    }

    return 0;
}