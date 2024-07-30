#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    string data;
    cin >> data;
    
    int N = data.size();
    int now_P = 0;
    
    
    string result = "PPAP";
    int idx = 0;
    
    vector<char> stacker;
    int stacker_idx = 0;
    
    while (idx != N) {
        if (stacker.size() == 0) {
            if (data[idx] == 'P') {
                stacker.push_back(data[idx]);
                now_P += 1;
                idx += 1;
            }
            else {
                stacker_idx = -1;
                break;
            }
        }
        else {
            if (data[idx] == 'P') {
                if (stacker[stacker_idx] == 'A') {
                    if (stacker_idx > 1 && stacker[stacker_idx - 1] == 'P' && stacker[stacker_idx - 2] == 'P') {
                        stacker_idx -= 2;
                    }
                    else {
                        break;
                    }
                }
                else {
                    stacker_idx += 1;
                    if (stacker_idx < stacker.size()) {
                        stacker[stacker_idx] = data[idx];
                    }
                    else {
                        stacker.push_back(data[idx]);
                    }
                }
                idx += 1;
            }
            else {
                stacker_idx += 1;
                if (stacker_idx < stacker.size()) {
                        stacker[stacker_idx] = data[idx];
                    }
                else {
                    stacker.push_back(data[idx]);
                }
                idx += 1;
            }
        }
    }
    
    if (stacker_idx != 0) {
        result = "NP";
    }
    
    cout << result;

    return 0;
}
