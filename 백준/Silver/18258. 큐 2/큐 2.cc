#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N;
    
    string command;
    int num;
    queue<int> que;
    
    for (int i=0; i<N; ++i) {
        cin >> command;
        
        if (command == "push") {
            cin >> num;
            que.push(num);
        }
        else if (command == "pop") {
            if (!que.empty()) {
                cout << que.front() << "\n";
                que.pop();
            }
            else {
                cout << -1 << "\n";
            }
        }
        else if (command == "size") {
            cout << que.size() << "\n";
        }
        
        else if (command == "empty") {
            cout << que.empty() << "\n";
        }
        
        else if (command == "front") {
            if (!que.empty()) {
                cout << que.front() << "\n";
            }
            else {
                cout << -1 << "\n";
            }
        }
        else if (command == "back") {
            if (!que.empty()) {
                cout << que.back() << "\n";
            }
            else {
                cout << -1 << "\n";
            }
        }
    }

    return 0;
}
