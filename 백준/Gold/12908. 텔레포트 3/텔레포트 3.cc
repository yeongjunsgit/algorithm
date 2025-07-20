#include <iostream>
#include <vector>
#include <algorithm>

#define pll pair<long long, long long>

using namespace std;

pll start_point, destination;

long long result = 3000000000;
vector<pair<pll, pll>> teleport(3);
vector<int> used(3, 0);

pll get_near(pll A, pll B, pll target)
{
    long long cnt = 0;
    bool what_best = true;
    long long to_A = abs(target.first - A.first) + abs(target.second - A.second);
    long long to_B = abs(target.first - B.first) + abs(target.second - B.second);
    if (to_A < to_B) what_best = true;
    else what_best = false;
    
    if (what_best) {
        cnt = to_A + 10;
        return {0, cnt};
    }
    else {
        cnt = to_B + 10;
        return {1, cnt};
    }
}


void lets_move_out(long long now, pll loca)
{
    // cout << "현재 나의 위치는 {" << loca.first << ", " << loca.second << "} 이고, 여기서 목적지까지 거리는 " << abs(loca.first - destination.first) + abs(loca.second - destination.second) << "이며 현재 누적 이동은 " << now << "이다. \n";
    result = min(result, now + abs(loca.first - destination.first) + abs(loca.second - destination.second) );
    for (int i=0; i<3; ++i) {
        if (used[i] == 0) {
            used[i] = 1;
            pll check = get_near(teleport[i].first, teleport[i].second, loca);
            if (check.first == 0) lets_move_out(now + check.second, teleport[i].second);
            else lets_move_out(now + check.second, teleport[i].first);
            used[i] = 0;
        }
    }
    return;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> start_point.first >> start_point.second >> destination.first >> destination.second;
    
    for (int i=0; i<3; ++i) {
        cin >> teleport[i].first.first >> teleport[i].first.second >> teleport[i].second.first >> teleport[i].second.second;
    }
    
    lets_move_out(0, start_point);
    
    cout << result;
    
    return 0;
}
