// 최소의 로봇 파워를 알아내고자 한다. 처음 문제를 봤을 때 그리디를 떠올렸다. 최대 2000 * 2000개의 보드에서
// 가장 낮은 값을 가지는 행 or 열을 찾아 해당 열을 우선적으로 지운다. 이렇게 되면 나머지 행과 열이 가지고 있는 눈의 양도
// 줄어들게 되고 이렇게 되면 매우 커서 선택되지 않은 행이나 열도 조금식 눈이 줄어 최적화가 될 수 있기 때문이다. 그리고 이중 가장 크게 소모한 에너지 값을
// 출력하면 된다고 생각했다!
// all_snow를 int로 선언해서 오버플로우가 난거 같다... 이런.. 이런 실수는 좀 줄여야하니 문제를 잘 읽고 자료형을 잘 선택하자..!

#include <iostream>
#include <vector>

using namespace std;

int N, M;
long long all_snow = 0;
// col_row_sum의 0이 col 1이 row
vector<vector<int> > snow_land(2000, vector<int>(2000)), col_row_sum(2, vector<int>(2000, 0));


int clean_low_snow_first()
{
    int best_power = 0;
    
    while (all_snow > 0) {
        int now_power = 1000000001, is_col_row = -1, now_idx = -1;
        for (int i=0; i<M; ++i) {
            if (col_row_sum[0][i] != 0 && now_power > col_row_sum[0][i]) {
                now_power = col_row_sum[0][i];
                is_col_row = 0;
                now_idx = i;
            }
        }
        
        for (int i=0; i<N; ++i) {
            if (col_row_sum[1][i] != 0 && now_power > col_row_sum[1][i]) {
                now_power = col_row_sum[1][i];
                is_col_row = 1;
                now_idx = i;
            }
        }
        best_power = max(best_power, now_power);
        all_snow -= now_power;
        col_row_sum[is_col_row][now_idx] = 0;
        if (is_col_row == 0) {
            for (int i=0; i<N; ++i) {
                if (col_row_sum[1][i] != 0) col_row_sum[1][i] -= snow_land[i][now_idx];
            }
        }
        else {
            for (int i=0; i<M; ++i) {
                if (col_row_sum[0][i] != 0) col_row_sum[0][i] -= snow_land[now_idx][i];
            }
        }
    }
    
    return best_power;
}



int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;
    for (int i=0; i<N; ++i) {
        for (int j=0; j<M; ++j) {
            cin >> snow_land[i][j];
            col_row_sum[0][j] += snow_land[i][j];
            col_row_sum[1][i] += snow_land[i][j];
            all_snow += snow_land[i][j];
        }
    }
    
    cout << clean_low_snow_first();
    
    return 0;
}
