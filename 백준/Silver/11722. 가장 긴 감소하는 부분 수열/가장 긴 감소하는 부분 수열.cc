#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

// 이분 탐색을 실행하는 함수
int binary_search(vector<int>& check, int start, int end, int target) {
    // target이 가질 위치를 담을 loca 선언
    int loca = -1;
    while (start < end) {
        int mid = (start + end) / 2;
        // 현재위치의 값이 목표보다 크다면 오른쪽 구간을 찾는다
        if (check[mid] > target) {
            start = mid + 1;
        }
        // 현재위치의 값이 목표보다 작다면 왼쪽 구간을 찾는다.
        else if (check[mid] < target){
            end = mid;
        }
        // 목표와 같은 값을 찾았다면 현재 mid값을 저장하고 탐색중지
        else {
            loca = mid;
            break;
        }
    }
    // 이분 탐색이 끝나고 똑같은 값을 찾지 못했다면 start 값이 target의 위치가 된다.
    if (loca == -1) {
        loca = start;
    }
    
    return loca;
}

int main()
{
    int N;
    cin >> N;
    cin.ignore();
    
    vector<int> numbers;
    
    string data;
    int num;
    
    getline(cin, data);
    istringstream iss(data);
    while (iss >> num) {
        numbers.push_back(num);
    }
    
    // 현재 연속하는 수열의 크기를 담을 result
    int result = 0;
    vector<int> check;
    // check에 제일 처음 값을 넣는다.
    check.push_back(numbers[0]);
    
    for (int i=1; i<N; ++i) {
        // 현재 값이 check 안의 가장 뒤의 값(가장 작은 값)보다 값이 작다면 check의 바로 뒤에 넣는다.
        if (numbers[i] < check.back()) {
            check.push_back(numbers[i]);
            // result는 이분탐색을 위해 check의 인덱스 값을 다루기 위하여 현재 크기의 -1을해서 저장해둔다.
            result = check.size() - 1;
        }
        // 처음부터 check의 크기까지 이분탐색을 시작해 현재 값의 위치를 찾는다.
        int location = binary_search(check, 0, result, numbers[i]);
        // 찾은 위치에 현재 값을 저장
        check[location] = numbers[i];
    }
    // 전부다 진행하고 result에는 index값이 들어가 있으므로 +1하여 출력
    cout << result + 1;

    return 0;
}
