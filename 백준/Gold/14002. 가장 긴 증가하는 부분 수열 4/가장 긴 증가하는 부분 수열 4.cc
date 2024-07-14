#include <iostream>
#include <sstream>
#include <vector>
#include <map>

using namespace std;

int binary_search(vector<int>& check, int start, int end, int target) {
    while (start < end) {
        int mid = (start + end) / 2;
        
        if (check[mid] < target) {
            start = mid + 1;
        }
        else {
            end = mid;
        }
    }
    
    return start;
}

int main()
{
    int N;
    cin >> N;
    cin.ignore();
    
    string data;
    int num;
    getline(cin, data);
    istringstream iss(data);
    vector<int> numbers;
    
    while (iss >> num) {
        numbers.push_back(num);
    }
    
    vector<int> check;
    int result = 0;
    check.push_back(numbers[0]);
    map<int, vector<pair<int, int>>> tracking;
    tracking[0] = {{0, numbers[0]}};
    
    for (int i=1; i<N; ++i) {
        int tmp_result = result;
        if (check.back() < numbers[i]) {
            check.push_back(numbers[i]);
            result = check.size() - 1;
        }
        int location = binary_search(check, 0, result, numbers[i]);
        check[location] = numbers[i];

        if (tracking.find(location) == tracking.end()) {
            tracking[location] = {{i, numbers[i]}};
        }
        else {
            tracking[location].push_back({i, numbers[i]});
        }
    }
    
    cout << result + 1 << "\n";
    
    vector<int> result_arr(result + 1, -1);
    result_arr[result] = check[result];
    
    int check_idx = result - 1;
    int now_idx = tracking[result][tracking[result].size() - 1].first;
    int now = tracking[result][tracking[result].size() - 1].second;
    
    while (check_idx != -1) {
        vector<pair<int, int>> check_arr = tracking[check_idx];
        for (int i=check_arr.size() - 1; i >= 0; --i) {
            pair<int, int> tmp = check_arr[i];
            if (now_idx > tmp.first && now > tmp.second) {
                result_arr[check_idx] = tmp.second;
                now_idx = tmp.first;
                now = tmp.second;
                check_idx -= 1;
                break;
            }
        }
    }
    
    for (int i=0; i <= result; ++i) {
        cout << result_arr[i] << " ";
    }

    return 0;
}
