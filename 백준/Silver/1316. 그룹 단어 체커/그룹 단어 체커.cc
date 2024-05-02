#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int N;
    cin >> N;
    
    int result = 0;
    
    for (int i=0; i<N; ++i) {
        char now = '+';
        
        vector<char> passed;
        bool isOK = true;
        
        string data;
        cin >> data;
        
        for (int j=0; j<data.size(); ++j) {
            if (now == '+') {
                now = data[j];
            }
            else {
                if (now != data[j]) {
                    if (find(passed.begin(), passed.end(), data[j]) == passed.end()) {
                        passed.push_back(now);
                        now = data[j];
                    }
                    else {
                        isOK = false;
                    }
                }
            }
        }
        
        if (isOK == true) {
            result += 1;
        }
    }

    cout << result;
    
    return 0;
}
