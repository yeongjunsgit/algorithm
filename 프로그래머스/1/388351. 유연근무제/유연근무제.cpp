#include <iostream>
#include <string>
#include <vector>

using namespace std;

int time_to_int(int t)
{
    int my_i = 0;
    my_i += t / 100 * 3600;
    my_i += t % 100 * 60;
    
    return my_i;
}


int solution(vector<int> schedules, vector<vector<int>> timelogs, int startday) {
    int answer = 0;
    vector<int> my_challenge(1000);
    int N = schedules.size();
    for (int i=0; i<N; ++i) {
       my_challenge[i] = time_to_int(schedules[i]);
    }
    
    for (int i=0; i<N; ++i) {
        int check_arrive = 0;
        int days = startday - 1;
        for (int j=0; j<7; ++j) {
            int day_arrive = time_to_int(timelogs[i][j]);
            // cout << "현재 나는 " << i << "번 직원으로 오늘은 " << days << "이며, 현재 챌린지는 " << my_challenge[i] + 600 << "까지 이고, 나는 오늘 " << day_arrive << "에 도착했다. \n";
            if (my_challenge[i] + 600 >= day_arrive && days != 5 && days != 6) {
                check_arrive++;
                // cout << i << "번 직원 " << days << "일 성공! \n";  
            }
            days++;
            if (days == 7) days = 0;
        }
        if (check_arrive == 5) {
            answer++;
            // cout << i << "번 직원은 선물을 받아요!\n";
        }
        // cout << "\n";
    }
    
    return answer;
}
