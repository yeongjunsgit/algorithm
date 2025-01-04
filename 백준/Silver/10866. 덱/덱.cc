#include <iostream>
#include <vector>
#include <deque>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N, num;
    cin >> N;
    string command;
    deque<int> que;
    
    for (int i=0; i<N; ++i) {
        cin >> command;
        
        if (command == "push_back") {
            cin >> num;
            que.push_back(num);
        }
        else if (command == "push_front") {
            cin >> num;
            que.push_front(num);
        }
        else if (command == "pop_front") {
            if (que.size() > 0) {
                cout << que.front() << "\n";
                que.pop_front();
            }
            else {
                cout << -1 << "\n";
            }
        }
        else if (command == "pop_back") {
            if (que.size() > 0) {
                cout << que.back() << "\n";
                que.pop_back();
            }
            else {
                cout << -1 << "\n";
            }
        }
        else if (command == "size") {
            cout << que.size() << "\n";
        }
        else if (command == "empty") {
            if (que.empty()) {
                cout << 1 << "\n";
            }
            else {
                cout << 0 << "\n";
            }
        }
        else if (command == "front") {
            if (que.size() > 0) {
                cout << que.front() << "\n";
            }
            else {
                cout << -1 << "\n";
            }
        }
        else if (command == "back") {
            if (que.size() > 0) {
                cout << que.back() << "\n";
            }
            else {
                cout << -1 << "\n";
            }
        }
    }

    return 0;
}
