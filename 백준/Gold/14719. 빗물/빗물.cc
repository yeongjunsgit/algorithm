#include <iostream>
#include <vector>

using namespace std;
int H, W;
vector<int> walls(500, 0), visited(500, 0);

int get_water(int start)
{
    if (W - 1 == start) return 0;
    
    int base = walls[start], mirror_base = 0, mirror_loca = -1, cnt = 0;
    for (int i=start + 1; i<W; ++i) {
        if (walls[i] < base) {
            visited[i] = 1;
            if (walls[i] < mirror_base) {
                cnt += walls[i];
            }
            else if (walls[i] == mirror_base) {
                mirror_loca = i;
                cnt += walls[i];
            }
            else {
                cnt += mirror_base;
                mirror_base = walls[i];
                mirror_loca = i;
            }
        }
        else {
            cnt += mirror_base;
            int waters = (i - start - 1) * base - cnt;
            return waters;
        }
    }
    visited[mirror_loca] = 0;
    for (int i=mirror_loca + 1; i<W; ++i) {
        cnt -= walls[i];
        visited[i] = 0;
    }
    
    int waters = (mirror_loca - start - 1) * mirror_base - cnt;
    return waters;
    
}

int water_proof()
{
    int result = 0;
    
    for (int i=0; i<W; ++i) {
        if (visited[i] == 0) {
            visited[i] = 1;
            result += get_water(i);
        }
    }
    
    return result;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> H >> W;
    
    for (int i=0; i<W; ++i) {
        cin >> walls[i];
    }
    
    cout << water_proof();
    
    return 0;
}
