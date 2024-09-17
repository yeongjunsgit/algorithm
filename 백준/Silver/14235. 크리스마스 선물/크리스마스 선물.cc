#include <iostream>
#include <sstream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N;
    cin >> N;
    cin.ignore();
    
    string data;
    int num;
    priority_queue<int, vector<int>, less<int> > que;
    
    
    for (int i=0; i<N; ++i) {
        int idx = 0;
        getline(cin, data);
        istringstream iss(data);
        
        while (iss >> num) {
            if (idx == 0 && num == 0) {
                if (que.empty()) {
                    cout << -1 << "\n";
                }
                else {
                    cout << que.top() << "\n";
                    que.pop();
                }
            }
            else {
                if (idx == 0) {
                    idx++;
                }
                else {
                    que.push(num);
                }
                
            }
        }
    }

    return 0;
}
