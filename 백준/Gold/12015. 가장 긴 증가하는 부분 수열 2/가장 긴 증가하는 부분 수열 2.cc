#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

int N;
vector<int> numbers, my_num;

int binary_check(int left, int right, int target)
{
    int start = left;
    int end = right;
    
    while (start <= end) {
        int mid = (start + end) / 2;
        
        if (my_num[mid] < target) {
            start = mid + 1;
        }
        else {
            end = mid - 1;
        }
    }
    
    return start;
    
}

void LIS()
{
    int my_size = 1;
    my_num.push_back(numbers[0]);
    
    for (int i=1; i<N; ++i) {
        int idx = binary_check(0, my_size - 1, numbers[i]);
        if (idx == my_size) {
            my_size++;
            my_num.push_back(numbers[i]);
        }
        else {
            my_num[idx] = numbers[i];
        }
    }
    
    cout << my_size;
    
}

int main()
{
    cin >> N;
    cin.ignore();
    
    string data;
    int num;
    getline(cin, data);
    istringstream iss(data);
    while (iss >> num) {
        numbers.push_back(num);
    }
    
    LIS();
    
    return 0;
}
