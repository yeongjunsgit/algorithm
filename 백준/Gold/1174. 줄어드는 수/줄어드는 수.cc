#include <iostream>
#include <vector>
#include <string>
#include <numeric>

using namespace std;

int main()
{
    int N;
    
    cin >> N;
    
    int sequence = 1;
    int num = 0;
    
    vector<char> cheeze_box = {'1', '0'};
    bool is_ok = true;
    
    while (N != sequence) {
        sequence += 1;
        if (num < 10) {
            num += 1;
        }

        else {
            cheeze_box[cheeze_box.size() - 1] += 1;
            int M = cheeze_box.size();
            for (int i=M-1; i>0; --i) {
                // 만약 현재자리의 값이 다음 자리값과 같아졌다면
                if (cheeze_box[i] == cheeze_box[i-1]) {
                    // 현재 자리값 바꾸기
                    if (i == M-1) {
                        cheeze_box[i] = '0';
                    }
                    else {
                        cheeze_box[i] = cheeze_box[i+1] + 1;
                    }
                    // 다음 자리 값 올리기
                    // 만약 가장 앞자리가 9일때 자리값을 올려야한다면 자리값을 추가하자
                    if (i-1 == 0 && cheeze_box[i-1] == '9') {
                        cheeze_box[i-1] = cheeze_box[i] + 1;
                        cheeze_box.insert(cheeze_box.begin(), cheeze_box[i-1] + 1);
                        // 만약 9876543210를 넘어가는 수라면 더이상 줄어드는 수를 만들 수 없으므로 반복중단
                        if (cheeze_box.size() > 10) {
                            is_ok = false;
                            break;
                        }
                    }
                    else {
                        cheeze_box[i-1] += 1;
                    }
                }
            }
        }
    }
    
    if (is_ok == false) {
        cout << "-1";
    }
    else {
        if (sequence < 12) {
            cout << num;
        }
        else {
            string numStr = accumulate(cheeze_box.begin(), cheeze_box.end(), string{});
            long long result = stoll(numStr);
            cout << result;
        }
    }
    
    return 0;
}
