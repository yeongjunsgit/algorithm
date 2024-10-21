#include <iostream>
#include <string>

using namespace std;

int main()
{
    int T;
    cin >> T;
    
    string data;
    for (int i=0; i<T; ++i) {
        cin >> data;
        string A, B;
        bool is_pass = false;
        for (auto a : data) {
            if (a == ',') {
                is_pass = true;
            }
            else {
                if (is_pass == false) {
                    A += a;
                }
                else {
                    B += a;
                }
            }
        }
        
        int result = stoi(A) + stoi(B);
        cout << result << "\n";
    }

    return 0;
}
