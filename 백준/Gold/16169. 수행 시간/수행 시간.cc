#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<int> cnt_grade(101, 0);
vector<int> loca_time;
vector<pair<int, int> > infos;
vector<vector<int> > grade_loca(101);

int lets_run()
{
    for (int i=1; i<=100; ++i) {
        if (cnt_grade[i + 1] == 0) {
            int result = 0;
            for (int a : grade_loca[i]) {
                result = max(result, loca_time[a] + infos[a].second);
            }
            return result;
        }
        
        for (int a : grade_loca[i]) {
            loca_time[a] += infos[a].second;
            for (int b : grade_loca[i+1]) {
                int arrive_time = a - b;
                arrive_time *= arrive_time;
                loca_time[b] = max(loca_time[b], loca_time[a] + arrive_time);
            }
        }
        
    }
    
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    cin >> N;
    loca_time.resize(N+1, 0);
    infos.resize(N+1);
    int grade, run_time;
    for (int i=1; i<=N; ++i) {
        cin >> grade >> run_time;
        infos[i] = {grade, run_time};
        cnt_grade[grade]++;
        grade_loca[grade].push_back(i);
    }
    
    cout << lets_run();

    return 0;
}
