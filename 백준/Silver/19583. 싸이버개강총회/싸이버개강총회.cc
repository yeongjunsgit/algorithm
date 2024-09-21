#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

int cnt = 0;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    string S, E, Q;
    cin >> S >> E >> Q;
    
    string T, name;
    map<string, int> checked;
    
    while (cin >> T >> name) {
        int hour = stoi(T.substr(0, 2));
        int minute = stoi(T.substr(3, 5));
        
        if (hour < stoi(S.substr(0, 2))) {
            checked[name] = 1;
        }
        else if (hour == stoi(S.substr(0, 2))) {
            if (minute <= stoi(S.substr(3, 5))) {
                checked[name] = 1;
            }
        }
        else if (hour > stoi(E.substr(0, 2)) && checked[name] == 1) {
            if (hour < stoi(Q.substr(0, 2))) {
                cnt++;
                checked[name] = 2;
            }
            else if (hour == stoi(Q.substr(0, 2))) {
                if (minute <= stoi(Q.substr(3, 5))) {
                    cnt++;
                    checked[name] = 2;
                }
            }
        }
        else if (hour == stoi(E.substr(0, 2)) && checked[name] == 1) {
            if (minute >= stoi(E.substr(3, 5))) {
                if (hour < stoi(Q.substr(0, 2))) {
                    cnt++;
                    checked[name] = 2;
                }
                else if (hour == stoi(Q.substr(0, 2))) {
                    if (minute <= stoi(Q.substr(3, 5))) {
                        cnt++;
                        checked[name] = 2;
                    }
                }
            }
        }
    }
    
    cout << cnt;

    return 0;
}
