// 최대한 큰 수가 앞으로 와야한다. 그리고, 그 다음 수가 2번째 앞으로 와야한다.
// 이런 식으로 접근해야할거같다.
// 앞으로 올 수 있는 가장 큰 값을 구한다. 민약 가장 큰 수가 맨 앞으로 온다면 이를 행한다.
// 가장 큰 수가 맨 앞으로 왔을때, 이동 횟수가 남아 있다면 그 다음 큰 수를 2번째 위치로 옮긴다.
// 만약, 2번째 큰 수가 2번째 위치로 올 수 없다면, 2번째 위치로 올 수 있는 값중에 가장 큰 값을 옮긴다.
// 이를 가능 한 횟수만 큼 반복한다.


#include <iostream>
#include <vector>
#include <algorithm>

#define pll pair<int, int>

using namespace std;

int N, S, numbers[51];

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    for (int i=0; i<N; ++i) {
        cin >> numbers[i];
    }
    cin >> S;
    int start = 0;
    while (start != N-1 && S > 0) {
        int now_best = start, tmp;
        for (int i=start + 1; i<N; ++i) {
            if (numbers[i] > numbers[now_best] && i - start <= S) {
                now_best = i;
            }
        }
        
        tmp = numbers[now_best];
        for (int i=now_best; i>start; --i) {
            numbers[i] = numbers[i-1];
        }
        numbers[start] = tmp;
        S -= now_best - start;
        start++;
    }
    
    for (int i=0; i<N; ++i) {
        cout << numbers[i] << " ";
    }
    
    return 0;
}
