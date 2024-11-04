#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    string data;
    while (true) {
        getline(cin, data);
        if (data == ".") {
            break;
        }
        vector<char> matching;
        
        string result = "yes";
        
        for (char a : data) {
            if (a == '(' || a == '[') {
                matching.push_back(a);
            }
            else if (a == ')') {
                if (matching.size() > 0 && matching.back() == '(') {
                    matching.pop_back();
                }
                else {
                    result = "no";
                    break;
                }
            }
            else if (a == ']') {
                if (matching.size() > 0 && matching.back() == '[') {
                    matching.pop_back();
                }
                else {
                    result = "no";
                    break;
                }
            }
        }
        
        if (matching.size() > 0) {
            result = "no";
        }
        
        cout << result << "\n";
        
    }

    return 0;
}
