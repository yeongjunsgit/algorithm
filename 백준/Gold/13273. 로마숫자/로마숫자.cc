#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

int T;
unordered_map<char, int> roma_num {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000} };


int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> T;
    
    for (int t=0; t<T; ++t) {
        string data;
        int num = -1;
        cin >> data;
        if (isdigit(data[0])) {
            num = stoi(data);
        }
        
        if (num == -1) {
            int tmp = 0, s_size = data.size();
            for (int i=0; i<s_size; ++i) {
                if (data[i] == '-') continue;
                if (i+1 < s_size && roma_num[data[i]] < roma_num[data[i+1]]) {
                    tmp += roma_num[data[i+1]] - roma_num[data[i]];
                    data[i+1] = '-';
                }
                else {
                    tmp += roma_num[data[i]];
                }
            }
            cout << tmp << "\n";
        }
        else {
            string tmp = "";
            if (num >= 1000) {
                int M_check = num / 1000;
                num %= 1000;
                for (int i=0; i<M_check; ++i) {
                    tmp += 'M';
                }
            }
            if (num >= 900) {
                num %= 900;
                tmp += "CM";
            }
            if (num >= 500) {
                num %= 500;
                tmp += 'D';
            }
            if (num >= 400) {
                num %= 400;
                tmp += "CD";
            }
            if (num >= 100) {
                int C_check = num / 100;
                num %= 100;
                for (int i=0; i<C_check; ++i) {
                    tmp += 'C';
                }
            }

            if (num >= 90) {
                num %= 90;
                tmp += "XC";
            }
            if (num >= 50) {
                num %= 50;
                tmp += 'L';
            }
            if (num >= 40) {
                num %= 40;
                tmp += "XL";
            }
            if (num >= 10) {
                int X_check = num / 10;
                num %= 10;
                for (int i=0; i<X_check; ++i) {
                    tmp += 'X';
                }
            }
            if (num >= 9) {
                num %= 9;
                tmp += "IX";
            }
            if (num >= 5) {
                num %= 5;
                tmp += 'V';
            }
            if (num >= 4) {
                num %= 4;
                tmp += "IV";
            }
            if (num >= 1) {
                int I_check = num / 1;
                num %= 10;
                for (int i=0; i<I_check; ++i) {
                    tmp += 'I';
                }
            }
            
            cout << tmp << "\n";
        }
        
    }

    return 0;
}
