#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M, cnt = 0;

vector<int> water_flow(100001), rain_drop(100001), parents(100001), water_overflow(100001, -1);


int find_root(int x)
{
    if (parents[x] == x) {
        return x;
    }
    return parents[x] = find_root(parents[x]);
}


void union_root(int x, int y)
{
    int r_x = find_root(x);
    int r_y = find_root(y);
    
    if (r_x == r_y) return;
    
    if (r_x > r_y) swap(r_x, r_y);
    
    parents[r_y] = r_x;
    water_flow[r_x] += water_flow[r_y];
    rain_drop[r_x] += rain_drop[r_y];

    if (water_flow[r_x] >= rain_drop[r_x]) {
        if (water_overflow[r_x] > 0) {
            cnt -= water_overflow[r_x];
            water_overflow[r_x] *= -1;
        }
        if (water_overflow[r_y] > 0) {
            cnt -= water_overflow[r_y];
            water_overflow[r_y] *= -1;
        }
    }
    else {
        if (water_overflow[r_x] < 0) {
            water_overflow[r_x] *= -1;
            cnt += water_overflow[r_x];
        }
        if (water_overflow[r_y] < 0) {
            water_overflow[r_y] *= -1;
            cnt += water_overflow[r_y];
        }
    }
    water_overflow[r_x] += water_overflow[r_y];
    
    // cout << "진행결과 현재 홍수가 난 마을은 " << cnt << "개이고, 현재 배수로의 크기는 " << water_flow[r_x] << "이고, 현재 강수량은 " << rain_drop[r_x] << "이라서 " << water_overflow[r_x] << "의 연합의 현황이 된다. \n";
    
    return;
}


int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;
    
    for (int i=1; i<=N; ++i) {
        cin >> water_flow[i];
    }
    for (int i=1; i<=N; ++i) {
        cin >> rain_drop[i];
        if (rain_drop[i] > water_flow[i]) {
            cnt++;
            water_overflow[i] *= -1;
        }
    }
    for (int i=1; i<=N; ++i) {
        parents[i] = i;
    }
    
    int command, s, e;
    
    for (int i=0; i<M; ++i) {
        cin >> command;
        if (command == 1) {
            cin >> s >> e;
            union_root(s, e);
        }
        else {
            cout << cnt << "\n";
        }
    }
    
    return 0;
}
