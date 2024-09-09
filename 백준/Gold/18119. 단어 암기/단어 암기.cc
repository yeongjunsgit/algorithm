#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N, M, command;
    cin >> N >> M;
    
    string data;
    char sentence;
    
    vector<int> check_data(N);
    vector<int> forgot_thing(N, 0);
    
    for (int i = 0; i < N; ++i) {
        cin >> data;
        int bitmask = 0;
        for (char a : data) {
            // 각 문자를 비트마스크로 변환하여 OR 연산을 이용해 저장
            bitmask |= (1 << (a - 'a'));
        }
        check_data[i] = bitmask;
    }
    
    int remember_me = N;
    
    for (int i = 0; i < M; ++i) {
        cin >> command >> sentence;
        int bit = (1 << (sentence - 'a'));  // 받은 문자를 비트마스크로 변환
        
        for (int j = 0; j < N; ++j) {
            if (check_data[j] & bit) {  // 비트마스크 AND연산으로 특정 문자가 포함되어 있는지 확인
                if (command == 1) {  // forget command
                    if (forgot_thing[j] == 0) {
                        remember_me -= 1;
                    }
                    forgot_thing[j] += 1;
                }
                else {  // remember command
                    forgot_thing[j] -= 1;
                    if (forgot_thing[j] == 0) {
                        remember_me += 1;
                    }
                }
            }
        }
        
        cout << remember_me << "\n";
    }

    return 0;
}
