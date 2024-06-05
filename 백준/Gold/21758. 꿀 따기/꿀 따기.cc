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
    getline(cin, data);
    
    istringstream iss(data);
    vector<int> honey_way;
    int num;
    
    int total = 0;
    
    while (iss >> num) {
        honey_way.push_back(num);
        total += num;
    }
    
    // 왼쪽 끝에 벌통이 있을 때
    int right_bee = total - honey_way[N-1];
    int right_result = 0;
    int right_passed = 0;

    for (int i=N-2; i>0; --i) {
        right_passed += honey_way[i];
        int tmp_right_result = (right_bee - honey_way[i]) + (right_bee - right_passed);
        
        if (right_result < tmp_right_result) {
            right_result = tmp_right_result;
        }
    }
    
    // 오른쪽 끝에 벌통이 있을 때
    int left_bee = total - honey_way[0];
    int left_result = 0;
    int left_passed = 0;
    
    for (int i=1; i<N; ++i) {
        left_passed += honey_way[i];
        int tmp_left_result = (left_bee - honey_way[i]) + (left_bee - left_passed);
        
        if (left_result < tmp_left_result) {
            left_result = tmp_left_result;
        }
    }
    
    // 중간 어느 곳에 벌통이 있을 때
    int mid_result = 0;
    int mid_passed = 0;
    for (int i=1; i<N-1; ++i) {
        int tmp_mid_result = (mid_passed + honey_way[i]) + (total - honey_way[N-1] - mid_passed - honey_way[0]);
        
        if (mid_result < tmp_mid_result) {
            mid_result = tmp_mid_result;
        }
        
        mid_passed += honey_way[i];
    }
    
    
    int result = max({right_result, left_result, mid_result});
    
    cout << result;
    

    return 0;
}
