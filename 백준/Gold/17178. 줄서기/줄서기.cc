#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct Compare {
    bool operator()(const string& a, const string& b) {
        if (a[0] != b[0]) {
            return a[0] < b[0];
        }
        return stoi(a.substr(2)) < stoi(b.substr(2));
    }
};

int main()
{
    int N;
    cin >> N;
    cin.ignore();
    
    vector<vector<string> > waiting;
    vector<string> idel_entrance;
    
    string data;
    string ticket;
    
    for (int i=0; i<N; ++i) {
        getline(cin, data);
        istringstream iss(data);
        vector<string> one_line;
        
        while (iss >> ticket) {
            one_line.push_back(ticket);
            idel_entrance.push_back(ticket);
        }
        
        waiting.push_back(one_line);
    }
    
    sort(idel_entrance.begin(), idel_entrance.end(), Compare());
    
    vector<string> waitng_line;
    int idx = 0;
    
    string result = "GOOD";
    
    for (int i=0; i<N; ++i) {
        if (result == "GOOD") {
            for (string a : waiting[i]) {
                if (a != idel_entrance[idx]) {
                    waitng_line.push_back(a);
                }
                
                else {
                    idx++;
                    
                    while (true) {
                        if (waitng_line.size() > 0 && waitng_line.back() == idel_entrance[idx]) {
                            idx++;
                            waitng_line.pop_back();

                        }
                        else {
                            break;
                        }
                    }
                }
            }
        }
        else {
            break;
        }
    }
    
    if (idx < idel_entrance.size()) {
        result = "BAD";
    }
    
    cout << result;

    return 0;
}
