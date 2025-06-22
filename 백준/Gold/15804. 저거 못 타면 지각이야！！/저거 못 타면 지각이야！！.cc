#include <iostream>
#include <vector>
#include <deque>
#include <queue>

#define pll pair<int, int>

using namespace std;

int N, M;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;
    
    int arrive, stay;
    deque<pair<int, pll> > bus_station; 
    queue<pair<int, pll> > waiting;
    int now_time = 0;

    for (int i=1; i<=M; ++i) {
        cin >> arrive >> stay;
        waiting.push({i, {arrive, stay}});
    }
    
    while (!waiting.empty()) {
        now_time++;
        while (!bus_station.empty() && bus_station.front().first <= now_time) {
            bus_station.pop_front();
        }
        while (!waiting.empty() && waiting.front().second.first <= now_time) {
            if (bus_station.empty()) {
                bus_station.push_back({max(waiting.front().second.first, now_time) + waiting.front().second.second, {1, waiting.front().first}});
                waiting.pop();
            }
            else {
                if (bus_station.back().second.first < N) {
                    bus_station.push_back({max(waiting.front().second.first, now_time) + waiting.front().second.second, {bus_station.back().second.first + 1, waiting.front().first}});
                    waiting.pop();
                }
                else break;
            }
        }
    }
    
    while (!bus_station.empty()) {
        pair<int, pll> now = bus_station.front();
        bus_station.pop_front();
        if (now.second.second == M) {
            cout << now.second.first;
            break;
        }
    }

    return 0;
}