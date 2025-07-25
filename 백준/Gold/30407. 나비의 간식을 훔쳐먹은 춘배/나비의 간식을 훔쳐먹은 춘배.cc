#include <iostream>
#include <vector>

#define pll pair<int, int>

using namespace std;

int N, H, D, K;
vector<int> punch_punch(18, 0);
int min_damage = 999999999;

void avoid_punch(int depth, int now_damage, int now_dist, int is_used)
{
    if (depth == 18) {
        if (min_damage > now_damage) {
            min_damage = now_damage;
        }
        return;
    }
    
    if (now_damage >= min_damage) return;
    
    int now_punch = punch_punch[depth];
    if (is_used == 1) {
        now_punch = 0;
        is_used = 2;
    }
    
    for (int i=0; i<3; ++i) {
        if (i == 0) {
            int guard = now_damage + max(0, now_punch - now_dist) / 2;
            if (guard < min_damage) avoid_punch(depth + 1, guard, now_dist, is_used);
        }
        if (i == 1) {
            int guard = now_damage + max(0, now_punch - (now_dist + K));
            if (guard < min_damage) avoid_punch(depth + 1, guard, now_dist + K, is_used);
        }
        else {
            if (is_used == 0) {
                int guard = now_damage + max(0, now_punch - now_dist);
                if (guard < min_damage) avoid_punch(depth + 1, guard, now_dist, 1);
            }
        }
    }
    
    return;
}


int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> H >> D >> K;
    for (int i=0; i<N; ++i) {
        cin >> punch_punch[i];
    }
    
    avoid_punch(0, 0, D, 0);
    
    if (min_damage >= H) cout << -1;
    else cout << H - min_damage;

    return 0;
}
