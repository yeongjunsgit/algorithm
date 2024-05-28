#include <iostream>
#include <sstream>
#include <vector>
#include <map>
#include <queue>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    
    cin.ignore();
    
    // 각 작업들이 끝나는 시간을 기록
    vector<int> passed_times(N+1, 0);
    // 각 작업들이 소모되는시간을 기록
    vector<int> cost_times(N+1, 0);
    // 각 작업의 선행작업을 기록
    map<int, vector<int>> before_process;
    // 각 작업의 완료를 기록
    vector<bool> complete(N+1, false);
    int ok = 0;
    
    int result = 0;
    
    string data;
    int num;
    for (int i=1; i<N+1; ++i) {
        getline(cin, data);
        istringstream iss(data);
        vector<int> previous;
        while(iss >> num) {
            previous.push_back(num);
        }
        
        cost_times[i] = previous[0];
        
        if (previous[1] != 0) {
            vector<int> pre(previous.begin()+2, previous.end());
            before_process.insert({i, pre});
        }
        else {
            passed_times[i] = previous[0];
            complete[i] = true;
            ok += 1;
            if (result < passed_times[i]) {
                result = passed_times[i];
            }
        }
    }
    
    
    while (ok != N) {
        for (int i=1; i<N+1; ++i) {
            if (complete[i] != true) {
                int start_time = 0;
                bool can_go = true;
                for (int j=0; j<before_process[i].size(); ++j) {
                    if (passed_times[before_process[i][j]] != 0) {
                        start_time = max(start_time, passed_times[before_process[i][j]]);
                    }
                    else {
                        can_go = false;
                        break;
                    }
                }
                if (can_go == true) {
                    passed_times[i] = start_time + cost_times[i];
                    complete[i] = true;
                    ok += 1;
                    if (result < passed_times[i]) {
                        result = passed_times[i];
                    }
                }
            }
        }
    }
    
    cout << result;

    return 0;
}
