#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N, num;
    cin >> N;
    
    string command;
    unordered_set<int> my_set;
    
    for (int i=0; i<N; ++i) {
        cin >> command;
        
        if (command == "add") {
            cin >> num;
            my_set.insert(num);
        }
        else if (command == "remove") {
            cin >> num;
            my_set.erase(num);
        }
        else if (command == "check") {
            cin >> num;
            if (my_set.find(num) == my_set.end()) {
                cout << 0 << "\n";
            }
            else {
                cout << 1 << "\n";
            }
        }
        else if (command == "toggle") {
            cin >> num;
            if (my_set.find(num) == my_set.end()) {
                my_set.insert(num);
            }
            else {
                my_set.erase(num);
            }
        }
        else if (command == "all") {
            for (int i=1; i<=20; ++i) {
                my_set.insert(i);
            }
        }
        else if (command == "empty") {
            my_set.clear();
        }
    }

    return 0;
}