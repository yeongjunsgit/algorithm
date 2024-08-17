#include <iostream>
#include <sstream>
#include <queue>

using namespace std;

int N, K;

int result = 1000001;

void open_door() {
    cin >> N >> K;
    cin.ignore();
    
    string data;
    getline(cin, data);
    
    int num;
    istringstream iss(data);
    
    int one = 0;
    queue<int> que;
    
    while (iss >> num) {
        if (que.front() == 1) {
            que.push(num);
        }
        else {
            if (num == 1) {
                que.push(num);
            }
        }
        
        if (num == 1) {
            one++;
            if (one == K) {
                if (result > que.size()) {
                    result = que.size();
                }
            }
            else if (one > K) {
                while (one > K) {
                    if (que.front() == 1) {
                        one--;
                    }
                    que.pop();
                }
                
                while (que.front() == 2) {
                    que.pop();
                }
                
                if (result > que.size()) {
                    result = que.size();
                }
                
            }
        }
    }
    
    if (result == 1000001) {
        cout << -1;
    }
    
    else {
        cout << result;
    }
}

int main()
{
    open_door();

    return 0;
}
