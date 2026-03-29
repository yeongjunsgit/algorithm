#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int N;
unordered_map<char, int> used;
vector<string> my_options(30);
vector<char> each_match(30);

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    string data;
    cin >> N;
    cin.ignore();
    for (int i=0; i<N; ++i) {
        bool checked = false, second_checked = false;
        getline(cin, data);
        string check;
        istringstream iss(data);
        vector<string> passed;
        
        while (iss >> check) {
            passed.push_back(check);
            if (!checked) {
                char now_top = check[0];
                if (now_top < 'a') {
                    now_top += 32;
                }
                
                if (used.find(now_top) == used.end()) {
                    checked = true;
                    each_match[i] = check[0];
                    used[now_top] = 1;
                }
            }
            
        }
        if (checked) {
            for (string s : passed) {
                if (s[0] == each_match[i]) {
                    cout << "[" << s[0] << "]";
                    string tmp = s.substr(1);
                    cout << tmp;
                    each_match[i] = '-';
                }
                else {
                    cout << s;
                }
                cout << " ";
            }
        }
        
        else {
            for (char a : data) {
                if (second_checked || a == ' ') {
                    cout << a;
                }
                else {
                    char tmp = a;
                    if (tmp < 'a') {
                        tmp += 32;
                    }
                    if (used.find(tmp) == used.end()) {
                        cout << "[" << a << "]";
                        second_checked = true;
                        used[tmp] = 1;
                    }
                    else cout << a;
                }
            }
        }
        cout << "\n";
        
    }
    
    

    return 0;
}
