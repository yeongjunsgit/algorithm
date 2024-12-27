#include <iostream>
#include <vector>

using namespace std;

int main()
{
    // N = 목표 운동 시간, m = 최소 맥박, M = 최대 맥박, T = 휴식 시 맥박 증가량, R = 휴식 시 맥박 감소량
    int N, m, M, T, R;
    cin >> N >> m >> M >> T >> R;
    
    int ex_minute = 0;
    int now_minute = 0;
    int HP = m;
    
    if (m + T > M) {
        cout << -1;
    }
    else {
        while (ex_minute != N) {
            if (HP + T <= M) {
                ex_minute++;
                now_minute++;
                HP += T;
            }
            else {
                HP -= R;
                now_minute++;
                if (HP < m) {
                    HP = m;
                }
            }
        }
        
        cout << now_minute;
    }

    return 0;
}
