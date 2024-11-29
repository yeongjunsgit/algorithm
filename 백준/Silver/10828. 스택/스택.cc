#include <iostream>
#include <vector>

using namespace std;


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N;
    cin >> N;
    
    string command;
    int target;
    vector<int> stacker;
    
    for (int i=0; i<N; ++i) {
        cin >> command;
        if (command == "push") {
            cin >> target;
            stacker.push_back(target);
        }
        else if (command == "top") {
            if (stacker.size() > 0) {
                cout << stacker.back() << "\n";
            }
            else {
                cout << -1 << "\n";
            }
        }
        else if (command == "pop") {
            if (stacker.size() > 0) {
                cout << stacker.back() << "\n";
                stacker.pop_back();
            }
            else {
                cout << -1 << "\n";
            }
        }
        else if (command == "size") {
            cout << stacker.size() << "\n";
        }
        else {
            if (stacker.size() == 0) {
                cout << 1 << "\n";
            }
            else {
                cout << 0 << "\n";
            }
        }
    }

    return 0;
}
