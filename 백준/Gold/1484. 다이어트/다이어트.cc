#include <iostream>
#include <vector>
#include <cmath>
#include <queue>

using namespace std;

struct Compare {
    bool operator()(const int& a, const int& b) {
        return a > b;
    }
};

int main()
{
    int N;
    cin >> N;
    
    int i = 2;
    
    priority_queue<int, vector<int>, Compare> que;
    
    while (true) {
        int base = pow(i, 2) - 1;
        int check = 2 * (i-1);
        
        if (base > N) {
            break;
        }
        
        if ((N-base) % check == 0) {
            que.push(i + (N-base) / check);
        }
        
        i += 1;
    }
    
    if (!que.empty()) {
        while (!que.empty()) {
            int now = que.top();
            que.pop();
            
            cout << now << "\n";
        }
    }
    else {
        cout << "-1";
    }

    return 0;
}
