#include <iostream>
#include <sstream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

long long result = 0;

void buy_info(unordered_map<string, priority_queue<int, vector<int>, less<int> > >& match_info, string merchent, int repeat_time)
{
    if (match_info.find(merchent) != match_info.end()) {
        for (int i=0; i<repeat_time; ++i) {
            if (match_info[merchent].empty()) {
                break;
            }
            result += match_info[merchent].top();
            match_info[merchent].pop();
        }
    }
    
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N;
    cin >> N;
    
    unordered_map<string, priority_queue<int, vector<int>, less<int> > > match_info;
    
    string data;
    int num;
    
    for (int i=0; i<N; ++i) {
        int command, M;
        string merchent_name;
        cin >> command >> merchent_name >> M;
        
        if (command == 1) {
            cin.ignore();
            getline(cin, data);
            istringstream iss(data);
            while (iss >> num) {
                match_info[merchent_name].push(num);
            }
        }
        
        if (command == 2) {
            buy_info(match_info, merchent_name, M);
        }
    }
    
    cout << result;

    return 0;
}
