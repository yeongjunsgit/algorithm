#include <iostream>
#include <vector>

using namespace std;

int N;
vector<int> last_number(80001, -1), idx_loca(80001, 0);

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;

    char command; int num;
    for (int i=1; i<=N; ++i) {
        cin >> command;
        if (command == 'a') {
            cin >> num;
            last_number[i] = num;
            idx_loca[i] = i;
        }
        
        else if (command == 't') {
            cin >> num;
            last_number[i] = last_number[idx_loca[max(0, num - 1)]];
            idx_loca[i] = max(0, idx_loca[max(0, num - 1)]);
        }
        
        else {
            last_number[i] = last_number[max(0, idx_loca[max(0, i - 1)] - 1)];
            idx_loca[i] = idx_loca[max(0, idx_loca[max(0, i - 1)] - 1)];
        }
        
        // cout << "현재 " << i << "턴으로 현재 마지막에 기록된 값은 " << last_number[i] << "이고, 현재 기록된 인덱스 값은 " << idx_loca[i] << "이다 \n"; 
        cout << last_number[idx_loca[i]] << "\n";
    }
    

    return 0;
}