#include <iostream>
#include <vector>

using namespace std;

int N, M, K;

int lets_play()
{
    int play_time = 1;
    int target = M;
    int cnt = N;
    while (true) {
        int go_power;
        if (K <= cnt) {
            go_power = K;
        }
        else {
            go_power = K % cnt;
            if (go_power == 0) {
                go_power = cnt;
            }
        }
        if (go_power == target) {
            return play_time;
        }
        else if (go_power > target) {
            target += (cnt - go_power);
        }
        else {
            target -= go_power;
        }
        cnt--;
        play_time++;
    }
    
    return -1;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> K >> M;
    
    cout << lets_play();

    return 0;
}
