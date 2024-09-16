#include <iostream>
#include <sstream>
#include <queue>
#include <vector>

using namespace std;

int main()
{
    int N;
    cin >> N;
    cin.ignore();
    
    priority_queue<int, vector<int>, greater<int> > que;
    string data;
    int num;
    int idx = 0;
    
    for (int i=0; i<N; ++i) {
        getline(cin, data);
        istringstream iss(data);
        while (iss >> num) {
            idx++;
            que.push(num);
            
            if (idx > N) {
                idx = N+1;
                que.pop();
            }
        }
    }
    
    cout << que.top();

    return 0;
}
