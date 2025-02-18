#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

int N;
vector<int> numbers, LIS;

int binary_check(int now)
{
    int start = 0;
    int end = LIS.size() - 1;

    while (start <= end) {
        int mid = (start + end) / 2;
        if (now <= LIS[mid]) {
            end = mid - 1;
        }
        else {
            start = mid + 1;
        }
    }
    
    return start;
    
}

void make_LIS()
{
    int LIS_size = 0;
    for (int i=0; i<N; ++i) {
        if (i == 0) {
            LIS.push_back(numbers[i]);
            LIS_size++;
        }
        else {
            int idx = binary_check(numbers[i]);
            if (idx == LIS_size) {
                LIS.push_back(numbers[i]);
                LIS_size++;
            }
            else {
                LIS[idx] = numbers[i];
            }
        }
    }
    
    cout << LIS_size;
    
    return;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    cin >> N;
    cin.ignore();
    string data;
    int num;
    getline(cin, data);
    istringstream iss(data);
    while (iss >> num) {
        numbers.push_back(num);
    }
    
    make_LIS();

    return 0;
}
