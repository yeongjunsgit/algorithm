#include <iostream>
#include <sstream>
#include <queue>

using namespace std;

int main()
{   
    int N, S, num;
    cin >> N >> S;
    
    cin.ignore();
    string data;
    getline(cin, data);
    istringstream iss(data);
    
    int result = 100001;
    int sumsum = 0;
    queue<int> que;
    
    while (iss >> num) {
        que.push(num);
        sumsum += num;
        if (sumsum >= S) {
            int ok_size = que.size();
            while (sumsum > S) {
                sumsum -= que.front();
                if (sumsum >= S) {
                    ok_size -= 1;
                    que.pop();
                }
                else {
                    sumsum += que.front();
                    break;
                }
                
            }
            if (result > ok_size) {
                result = ok_size;
            }
        }
    }
    
    if (result == 100001) {
        cout << 0;
    }
    else {
        cout << result;
    }
    

    return 0;
}
