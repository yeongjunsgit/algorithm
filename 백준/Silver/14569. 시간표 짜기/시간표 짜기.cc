#include <iostream>
#include <sstream>
#include <vector>
#include <map>

using namespace std;

int N, M;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> N;
    cin.ignore();
    
    // 각 수업의 시간 개수
    vector<int> class_time;
    // 각 수업 시간에 가능한 사람의 번호
    vector<vector<int>> can_join(51);
    // 학생들이 들을 수 있는 수업의 개수
    vector<int> join_class(10001, 0);
    // 각 수업의 수업 시간
    vector<vector<int>> each_class_time;
    
    string data;
    int num;
    
    for (int i=0; i<N; ++i) {
        getline(cin, data);
        istringstream iss(data);
        vector<int> one_line;
        int idx = 0;
        while (iss >> num) {
            if (idx == 0) {
                class_time.push_back(num);
                idx++;
            }
            else {
                one_line.push_back(num);
            }
        }
        each_class_time.push_back(one_line);
    }
    
    cin >> M;
    cin.ignore();
    int people = 0;
    
    for (int i=0; i<M; ++i) {
        getline(cin, data);
        istringstream iss(data);
        vector<int> one_line;
        int idx = 0;
        while (iss >> num) {
            if (idx == 0) {
                idx++;
            }
            else {
                can_join[num].push_back(people);
            }
        }
        people += 1;
    }
    
    for (int i=0; i<N; ++i) {
        map<int, int> match_time;
        for (int t : each_class_time[i]) {
            for (int k : can_join[t]) {
                match_time[k] += 1;
                if (match_time[k] == class_time[i]) {
                    join_class[k] += 1;
                }
            }
        }
        
    }
    
    for (int i=0; i<M; ++i) {
        cout << join_class[i] << "\n";
    }

    return 0;
}
