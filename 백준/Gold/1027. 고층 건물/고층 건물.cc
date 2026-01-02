#include <iostream>
#include <vector>

using namespace std;

int N;
vector<double> building_height(51);


int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    for (int i=1; i<=N; ++i) {
        cin >> building_height[i];
    }
    
    int best_cnt = 0;
    // 각 위치에서 양 방향으로 봤을 때, 몇개의 빌딩을 볼 수 있는지 확인
    for (int i=1; i<=N; ++i) {
        int now_cnt = 0;
        double best_right = -2000000001, best_left = -2000000001;
        // 현재 빌딩에서 왼쪽을 확인
        for (int j=i-1; j>0; --j) {
            // 초기 생각했던 로직은 기울기가 현재 최고 기울기보다 높아야 보이는 것으로 생각하고 문제를 풀었으나,
            // 제 2사분면, 제 3사분면은 기울기를 연산할때, 제 1사분면과 제 4분면과는 다르게 기울기가 음수 양수가 반대였고
            // 단순히 기울기가 높은것으로 계산하면 왼쪽 부분은 반대로 계산이 되었다. 따라서 기울기에 -1을 곱해 로직을 통일하였다.
            double now_slope = (building_height[i] - building_height[j]) / (i - j) * -1;
            // 현재 가장 높은 기울기를 가진 빌딩 보다 기울기가 높지 않으면 보이지 않는다.
            if (best_left < now_slope) {
                now_cnt++;
                best_left = now_slope;
            }
        }
        // 현재 빌딩에서 오른쪽을 확인
        for (int k=i+1; k<=N; ++k) {
            double now_slope = (building_height[k] - building_height[i]) / (k - i);
            // 현재 가장 높은 기울기를 가진 빌딩보다 기울기가 높지 않으면 보이지 않는다.
            if (best_right < now_slope) {
                now_cnt++;
                best_right = now_slope;
            }
        }
        
        best_cnt = max(best_cnt, now_cnt);
    }
    
    cout << best_cnt;

    return 0;
}
