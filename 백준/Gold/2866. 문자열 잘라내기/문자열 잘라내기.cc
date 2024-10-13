#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

int R, C;
int cnt = 0;
vector<string> password;

void check_depth()
{
    int check_line = 1;
    bool is_ok = true;
    while (is_ok == true && check_line < C) {
        unordered_map<string, bool> check_multi;
        for (string s : password) {
            string tmp = s.substr(check_line, C);
            if (check_multi.find(tmp) == check_multi.end()) {
                check_multi[tmp] = true;
            }
            else {
                is_ok = false;
                break;
            }
        }
        if (is_ok == true) {
            check_line++;
            cnt++;
        }
    }
    
    return;
}

int main()
{
    cin >> R >> C;
    
    password.resize(C);
    string data;
    
    for (int i=0; i<R; ++i) {
        cin >> data;
        for (int j=0; j<C; ++j) {
            password[j] += data[j];
        }
    }
    
    check_depth();
    
    cout << cnt;

    return 0;
}
