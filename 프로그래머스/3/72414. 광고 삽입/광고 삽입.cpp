#include <iostream>
#include <string>
#include <vector>
using namespace std;

int s_to_time(const string& s) {
    return stoi(s.substr(0,2)) * 3600 +
           stoi(s.substr(3,2)) * 60 +
           stoi(s.substr(6,2));
}

string time_to_s(int t) {
    int h = t / 3600; t %= 3600;
    int m = t / 60;   t %= 60;
    int s = t;
    auto two = [](int x){ return (x<10?"0":"") + to_string(x); };
    return two(h) + ":" + two(m) + ":" + two(s);
}

string solution(string play_time, string adv_time, vector<string> logs) {
    int total_time = s_to_time(play_time);
    int ad_T = s_to_time(adv_time);

    vector<long long> check_point(total_time + 2, 0);

    for (auto &log : logs) {
        int start = s_to_time(log.substr(0, 8));
        int end = s_to_time(log.substr(9, 8));
        check_point[start] += 1;
        check_point[end] -= 1; 
    }

    vector<long long> stack_viewership(total_time + 2, 0);
    stack_viewership[0] = check_point[0];
    for (int i = 1; i <= total_time; ++i) {
        stack_viewership[i] = stack_viewership[i-1] + check_point[i];
    }

    long long tmp = 0;
    for (int i = 0; i < ad_T; ++i) {
        tmp += stack_viewership[i];
    }

    long long result = tmp;
    int result_time = 0;

    for (int start = 1; start + ad_T <= total_time; ++start) {
        tmp -= stack_viewership[start - 1];
        tmp += stack_viewership[start + ad_T - 1];
        if (tmp > result) {
            result = tmp;
            result_time = start;
        }
    }

    return time_to_s(result_time);
}
