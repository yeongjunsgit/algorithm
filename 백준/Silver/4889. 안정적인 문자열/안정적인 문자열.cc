#include <iostream>
#include <vector>

using namespace std;

int change_shape(vector<char>& stacker) {
    int cnt = 0;
    char now = ' ';
    
    for (auto c : stacker) {
        if (now == ' ') {
            if (c == '}') {
                cnt += 1;
            }
            now = '{';
        }
        else if (now == '{') {
            if (c == '{') {
                cnt += 1;
            }
            now = ' ';
        }
    }
    
    return cnt;
}

int main()
{
    string data;
    int tc = 0;
    while (true) {
        tc += 1;
        getline(cin, data);
        if (data[0] == '-') {
            break;
        }
        
        int result = 0;
        vector<char> stacker;
        for (auto c : data) {
            if (c == '{') {
                stacker.push_back(c);
            }
            else {
                if (stacker.size() == 0) {
                    result += 1;
                    stacker.push_back('{');
                }
                else {
                    if (stacker.back() == '{') {
                        stacker.pop_back();
                    }
                    else {
                        stacker.push_back(c);
                    }
                }
            }
        }
        
        if (stacker.size() != 0) {
            result += change_shape(stacker);
        }
        
        cout << tc << '.' << " " << result << "\n";
    }

    return 0;
}
