#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int N;
int result = 200000001;

void binary_check(vector<int>& numbers, int base, int idx)
{
    int start = 0;
    int end = N-1;
    int now = 2000000001;
    
    while (start <= end) {
        int mid = (start + end) / 2;
        int tmp = base + numbers[mid];
        
        if (tmp == 0 && idx != mid) {
            result = 0;
            return;
        } 
        else {
            if (abs(tmp) < abs(now) && idx != mid) {
                now = tmp;
            }
            
            if (tmp > 0) {
                end = mid - 1;
            }
            else {
                start = mid + 1;
            }
        }
    }
    
    if (abs(result) > abs(now)) {
        result = now;
    }
    
    return;
    
}

int main()
{
    cin >> N;
    cin.ignore();
    
    string data;
    int num;
    getline(cin, data);
    vector<int> numbers;
    istringstream iss(data);
    while (iss >> num) {
        numbers.push_back(num);
    }
    
    for (int i=0; i<N; ++i) {
        if (result != 0) {
            binary_check(numbers, numbers[i], i);
        }
    }

    cout << result;

    return 0;
}
