#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    string one, two;
    cin >> one >> two;
    reverse(one.begin(), one.end());
    reverse(two.begin(), two.end());
    
    int first_reverse = stoi(one) + stoi(two);
    string tmp_reverse = to_string(first_reverse);
    
    reverse(tmp_reverse.begin(), tmp_reverse.end());
    
    int result = stoi(tmp_reverse);
    
    cout << result;

    return 0;
}