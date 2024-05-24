/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    // N = 동굴의 길이(석순의 개수), M = 동굴의 높이
    int N, M;
    cin >> N >> M;
    
    // 석순과 종유석을 각각 나누어 받음
    int top[M+1]{0};
    int bottom[M+1]{0};
    int mixed[M+1]{0};
    
    int num;
    
    int same_line = 0;
    int min_break = 200001;
    
    for (int i=0; i<N; ++i) {
        cin >> num;
        
        if (i % 2 == 0) {
            bottom[num] += 1;
        }
        else if (i % 2 == 1) {
            top[M + 1 - num] += 1;
        }
    }
    
    // 아래 석순은 각 석순의 최대 높이 이하로는 모든 석순이 존재하는 것으로
    // 위에서 부터 내려오면서 값을 누적 해줌
    for (int i = M-1; i>=1; --i) {
        bottom[i] += bottom[i+1];
    }

    // 종유석은 시작점으로 부터 위로 모든 종유석이 존재하므로
    // 아래에서부터 위로 가며 값을 누적해줌
    for (int i=1; i <= M; ++i) {
        top[i] += top[i-1];
        mixed[i] += top[i] + bottom[i];
        if (mixed[i] < min_break) {
            min_break = mixed[i];
            same_line = 1;
        }
        else if (mixed[i] == min_break) {
            same_line += 1;
        }
    }

    cout << min_break << " " << same_line;

    return 0;
}
