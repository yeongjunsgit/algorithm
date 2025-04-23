#include <iostream>
#include <vector>
#include <cmath>
#include <unordered_map>
#include <algorithm>

using namespace std;

struct my_command
{
    int type;
    int cost;
    int days;
};
vector<int> jong_end(3, 0), yeong_end(3, 0);
vector<my_command> commands;
int T, N;
unordered_map<int, int> month_day = {{1, 31}, {2, 28}, {3, 31}, {4, 30}, {5, 31}, {6, 30}, {7, 31}, {8, 31}, {9, 30}, {10, 31}, {11, 30}, {12, 31}};

int get_days(vector<int> start, vector<int> end) {
    auto is_leap = [](int y) {
        return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
    };

    int month_day[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };

    auto date_to_days = [&](vector<int> date) {
        int y = date[0], m = date[1], d = date[2];
        int days = d;

        // 연도 누적
        for (int i = 1; i < y; ++i)
            days += is_leap(i) ? 366 : 365;

        // 월 누적
        for (int i = 1; i < m; ++i) {
            if (i == 2 && is_leap(y))
                days += 29;
            else
                days += month_day[i];
        }

        return days;
    };

    return date_to_days(end) - date_to_days(start);
}

void operation_start()
{
    int result = 0;
    vector<vector<int> > DP(100, vector<int>(10001, -1));
    if (N != 0) {
        DP[0][0] = 0;
        for (int i=0; i<N; ++i) {
            my_command now = commands[i];
            if (now.type == 3) now.days *= 30;
            if (i == 0) {
                if (now.cost <= T) {
                    DP[i][now.cost] = now.days;
                }
            }
            else {
                for (int j=0; j<=T; ++j) {
                    if (DP[i-1][j] != -1) {
                        DP[i][j] = max(DP[i-1][j], DP[i][j]);
                    }
                    if (j - now.cost >=0 && DP[i-1][j-now.cost] != -1) {
                        DP[i][j] = max({DP[i][j], DP[i-1][j-now.cost] + now.days, DP[i-1][j]});
                    }
                }
            }
        }
        for (int i=0; i<=T; ++i) {
            result = max(result, DP[N-1][i]);
        }
    }
    
    int date_gap = get_days(jong_end, yeong_end);
    // cout << result << " " <<  date_gap << "\n";
    cout << abs(result - date_gap);
    
    return;
    
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    for (int i=0; i<3; ++i) {
        cin >> jong_end[i];
    }
    for (int i=0; i<3; ++i) {
        cin >> yeong_end[i];
    }
    cin >> T >> N;
    int c, cost, day;
    for (int i=0; i<N; ++i) {
        cin >> c >> cost >> day;
        commands.push_back({c, cost, day});
    }
    
    operation_start();

    return 0;
}
