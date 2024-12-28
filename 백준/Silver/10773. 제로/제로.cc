#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int K;
    cin >> K;
    int now;
    int result = 0;
    vector<int> stacker;
    
    for (int i=0; i<K; ++i) {
        cin >> now;
        
        if (now != 0) {
            stacker.push_back(now);
            result += now;
        }
        else {
            if (stacker.size() > 0) {
                result -= stacker.back();
                stacker.pop_back();
            }
        }
    }

    cout << result;

    return 0;
}
