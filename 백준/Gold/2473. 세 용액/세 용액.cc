#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int N;
vector<long long> numbers;
vector<long long> result;
long long mix_power = 3000000001;

long long binary_check(int left, int right)
{
    int start = left + 1;
    int end = right - 1;
    
    while (start <= end) {
        int mid = (start + end) / 2;
        
        long long tmp = numbers[left] + numbers[right] + numbers[mid];
        
        if (tmp > 0) {
            end = mid - 1;
        }
        else {
            start = mid + 1;
        }
    }
    
    long long end_result = 3000000001;
    long long start_result = 3000000001;
    
    if (left < end && end < right) {
        end_result = numbers[left] + numbers[right] + numbers[end];
    }
    if (left < start && start < right) {
        start_result = numbers[left] + numbers[right] + numbers[start];
    }
    
    int tmp_loca;
    long long tmp_result;
    
    if (abs(end_result) < abs(start_result)) {
        tmp_loca = end;
        tmp_result = end_result;
    }
    else {
        tmp_loca = start;
        tmp_result = start_result;
    }
    
    if (mix_power > abs(tmp_result)) {
        mix_power = abs(tmp_result);
        result = {numbers[left], numbers[tmp_loca], numbers[right]};
    }
    // cout << numbers[left] << " " <<  numbers[tmp_loca] << " " << numbers[right] << "\n";
    return tmp_result;
}

void make_area()
{
    // int left = 0;
    // int right = N-1;
    
    // while (left + 1 < right) {
    //     long long check = binary_check(left, right);
        
    //     if (check > 0) {
    //         right--;
    //     }
    //     else if (check < 0) {
    //         left++;
    //     }
    //     else {
    //         break;
    //     }
    // }
    
    for (int left = 0; left < N-2; ++left) {
        for (int right = N-1; right > left + 1; --right) {
            long long check = binary_check(left, right);
        }
    }
    
    sort(result.begin(), result.end());
    
    for (long long a : result) {
        cout << a << " ";
    }
    
    return;
}


int main()
{
    cin >> N;
    cin.ignore();
    
    string data;
    getline(cin, data);
    long long num;
    istringstream iss(data);
    
    while (iss >> num) {
        numbers.push_back(num);
    }
    
    sort(numbers.begin(), numbers.end());
    
    make_area();

    return 0;
}
