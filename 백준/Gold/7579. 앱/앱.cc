#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
vector<int> use_memory, time_cost;
vector<vector<int> > best_time(101, vector<int>(10001, 0));
int result = 10001;

void check_best()
{
    for (int i=0; i<N; ++i) {
        for (int j=0; j<10001; ++j) {
            if (j < time_cost[i]) {
                best_time[i+1][j] = best_time[i][j];
            }
            else {
                best_time[i+1][j] = max(best_time[i][j], best_time[i][j - time_cost[i]] + use_memory[i]);
            }
        }
    }
    
    for (int i=0; i<10001; ++i) {
        if (best_time[N][i] >= M) {
            result = i;
            break;
        }
    }
    
    cout << result;
    
    return;
}

int main()
{
    cin >> N >> M;
    cin.ignore();
    
    string data;
    int num;
    getline(cin, data);
    istringstream iss(data);
    while (iss >> num) {
        use_memory.push_back(num);
    }
    getline(cin, data);
    istringstream isss(data);
    
    while (isss >> num) {
        time_cost.push_back(num);
    }
    
    check_best();

    return 0;
}
