// 이번 문제는 블로그를 보고 힌트를 얻어서 풀었다.
// 문제를 보면 N이 10000이고, 마을 3개를 골라서 연산하면 N^3이라 분명히 터질것 같았다
// 그러나, 아무리 생각해도 어떻게 알고리즘을 사용해야 복잡도를 줄일 수 있을까 고민했으나, 마땅한 알고리즘이 생각이안났고,
// 유형을 봤더니... 브루트포스?? 였다
// 그냥 헤딩해보려고했는데 아무리 생각해도 10000^3은 절대 불가능이라 블로그를 보고 힌트를 얻었다.
// 마을 3개 중 가운데 1개는 반드시 고정되기 때문에 해당 마을에서부터 가장 가까운마을과 두 번째로 가까운 마을을 찾아서
// 연산하면 N^2로 연산이 가능한 것이었다!
// 절대 생각 못했을 것 같은 아이디어다..! 꼭 외워두자!!


#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

struct viliage
{
    int x;
    int y;
    int z;
};

int N, result = 99999999;
vector<viliage> the_world(10000);

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    viliage tmp;
    for (int i=0; i<N; ++i) {
        cin >> tmp.x >> tmp.y >> tmp.z;
        the_world[i] = tmp;
    }
    
    for (int i=0; i<N; ++i) {
        int first_dist = 6001, second_dist = 6001;
        
        for (int j=0; j<N; ++j) {
            if (i == j) continue;
            int check = abs(the_world[i].x - the_world[j].x) + abs(the_world[i].y - the_world[j].y) + abs(the_world[i].z - the_world[j].z);
            if (check < second_dist) {
                second_dist = check;
                if (second_dist < first_dist) {
                    swap(first_dist, second_dist);
                }
            }
        }
        
        result = min(result, first_dist + second_dist);
    }
    
    cout << result;

    return 0;
}

