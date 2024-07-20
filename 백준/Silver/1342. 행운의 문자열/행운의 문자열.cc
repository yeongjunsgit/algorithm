#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std;

string input_data;
int N;
// 현재 남은 문자들의 갯수 상황에 따른 값을 저장하기 위한 memo 선언
map<string, int> memo;

int checking(map<char, int>& saved, vector<char>& lis, int& result, int idx, char before) {
    // 현재 남은 상황을 담을 string key 선언
    string key;
    // saved에 저장된 현재 남은 char들을 key값으로 만들어 저장
    for (const auto& element : saved) {
        key += element.first + to_string(element.second);
    }
    // 이전 값에 따라 나오는 값이 다를 수 있으므로 이전값도 key값에 저장장
    key += before;
    
    // 현재 만든 키값이 이미 예전에 계산된적 있는 값이라면 해당 값을 반환환
    if (memo.find(key) != memo.end()) {
        return memo[key];
    }
    
    // 현재 상황에 저장될 값을 기록할 tmp_result를 선언
    int tmp_result = 0;
    // 현재 모든 값을 썼는지 판단할 all_used를 선언
    bool all_used = true;
    
    // 현재 남은 값들을 순회해서 아직 못쓴 값이 있다면 all_used를 false로 바꾸고 반복중지
    for (auto& element : saved) {
        if (element.second > 0) {
            all_used = false;
            break;
        }
    }
    
    // 모든 경우를 다썼다면 해당 값은 1개의 경우만 있을 것이므로 1을 반환환
    if (all_used == true) {
        return 1;
    }
    
    // 위의 모든 경우에서 아직 반환이 안됬다면 계산된적이 없는 경우이므로 idx를 증가시켜 이동동
    for (int i=0; i<N; ++i) {
        if (saved[lis[i]] > 0 && lis[i] != before) {
            saved[lis[i]] -= 1;
            tmp_result += checking(saved, lis, result, idx + 1, lis[i]);
            saved[lis[i]] += 1;
        }
    }
    
    // 모든 순회를 끝마치고 계산한 값을 memo에 현재 key값에 저장하고 계산된 값을 반환환
    memo[key] = tmp_result;
    return tmp_result;

}

int main()
{
    cin >> input_data;
    
    int result = 0;
    map<char, int> saved;
    vector<char> lis;
    
    for (char c : input_data) {
        if (saved.find(c) == saved.end()) {
            saved[c] = 1;
            lis.push_back(c);
            N += 1;
        }
        else {
            saved[c] += 1;
        }
    }
    
    result = checking(saved, lis, result, 0, ' ');
    
    cout << result;

    return 0;
}
