#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int N, M;
    cin >> N;
    
    string data;
    
    cin.ignore();
    
    getline(cin, data);
    vector<int> numbers;
    istringstream iss(data);
    int num;
    
    while (iss >> num) {
        numbers.push_back(num);
    }
    
    sort(numbers.begin(), numbers.end());
    
    cin >> M;
    cin.ignore();
    
    getline(cin, data);
    vector<int> research;
    int target;
    
    istringstream isss(data);
    while (isss >> target) {
        int start = 0;
        int end = N-1;
        bool is_ok = false;
        
        while (start <= end) {
            int mid = (start + end) / 2;
            if (numbers[mid] == target) {
                is_ok = true;
                break;
            }
            
            else if (numbers[mid] > target) {
                end = mid - 1;
            }
            
            else if (numbers[mid] < target) {
                start = mid + 1;
            }
            
        }
        
        if (is_ok == true) {
            cout << "1" << "\n";
        }
        
        else {
            cout << "0" << "\n";
        }
        
    }

    return 0;
}
