#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N;
    cin >> N;
    
    cin.ignore();
    
    vector<string> inner;
    vector<string> outer;
    map<string, bool> checking;
    
    int result = 0;
    
    string data;
    for (int i=0; i<N; ++i) {
        getline(cin, data);
        inner.push_back(data);
        checking.insert({data, false});
    }
    
    int check_idx = 0;
    
    for (int i=0; i<N; ++i) {
        getline(cin, data);
        if (checking[inner[check_idx]] == true) {
            while (true) {
                check_idx += 1;
                if (checking[inner[check_idx]] == false) {
                    break;
                }
            }
        }
        if (data == inner[check_idx]) {
            check_idx += 1;
            checking[data] = true;
        }
        else {
            result += 1;
            checking[data] = true;
        }
    }
    
    cout << result;

    return 0;
}
