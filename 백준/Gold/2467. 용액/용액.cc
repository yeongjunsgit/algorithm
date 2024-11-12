#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int N;
vector<int> numbers;
int real_result = 2000000001;
pair<int, int> result_pair;


void binary_check()
{
    int start = 0;
    int end = N-1;
    
    while (start != end) {
        int tmp = numbers[start] + numbers[end];
        if (real_result > abs(tmp)) {
            real_result = abs(tmp);
            result_pair = {min(numbers[start], numbers[end]), max(numbers[start], numbers[end])};
        }
        
        
        if (tmp > 0) {
            end--;
        }
        else {
            start++;
        }
    }
    
    return;
}


int main()
{
    cin >> N;
    cin.ignore();
    
    int num;
    for (int i=0; i<N; ++i) {
        cin >> num;
        numbers.push_back(num);
    }
    
    binary_check();
    
    cout << result_pair.first << " " << result_pair.second;
    
    return 0;
}
