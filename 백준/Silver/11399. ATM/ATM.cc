#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int N;
    cin >> N;
    cin.ignore();
    
    string data;
    int num;
    vector<int> numbers;
    
    getline(cin, data);
    istringstream iss(data);
    
    while (iss >> num) {
        numbers.push_back(num);
    }
    
    sort(numbers.begin(), numbers.end());
    
    int result = 0;
    int now = 0;
    
    for (int a : numbers) {
        now += a;
        result += now;
    }

    cout << result;

    return 0;
}
