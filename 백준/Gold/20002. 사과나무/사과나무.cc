#include <iostream>
#include <vector>

using namespace std;

int N;
vector<vector<int> > apple_tree(300, vector<int>(300)), sumsum(300, vector<int>(300, 0));

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    // 값들을 받아 누적합으로 더한다.
    for (int i=0; i<N; ++i) {
        for (int j=0; j<N; ++j) {
            cin >> apple_tree[i][j];
            sumsum[i][j] = apple_tree[i][j];
            if (j != 0) {
                sumsum[i][j] += sumsum[i][j-1];
            }
        }
    }
    for (int i=1; i<N; ++i) {
        for (int j=0; j<N; ++j) {
            sumsum[i][j] += sumsum[i-1][j];
        }
    }
    
    // 현재 위치에서 만들 수 있는 모든 K * K의 정사각형에 대해서 누적합을 이용해 값을 계산한다.
    int result = -3000001;
    for (int i=0; i<N; ++i) {
        for (int j=0; j<N; ++j) {
            for (int k=0; k<N; ++k) {
                if (i+k < N && j+k < N) {
                    int tmp = sumsum[i+k][j+k];
                    // 위쪽 누적합을 제거
                    if (i != 0) tmp -= sumsum[i-1][j+k];
                    // 왼쪽 누적합을 제거
                    if (j != 0) tmp -= sumsum[i+k][j-1];
                    // 위쪽과 왼쪽을 전부 제거했다면, 중복 제거가 발생하므로 중복 부분을 원복
                    if (i != 0 && j != 0) tmp += sumsum[i-1][j-1];
                    
                    if (tmp > result) result = tmp;
                }
                else break;
            }
        }
    }
    
    cout << result;

    return 0;
}