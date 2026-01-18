// 해당 문제는 처음에는 이분탐색을 하려했으나, 기준값이 애매하여 포기하였고, 단순히 브루트포스, 배낭문제로는 시간초과나, 논리적으로 오류가 생겼다.
// 계속해서 머리를 싸매도 답이 안나와 알고리즘 분류를 보니 새롭게 보는 알고리즘이 있어서 해당 알고리즘을 공부하였다.
// 해당 알고리즘은 차분 배열 트릭으로 쉽게 말하면 누적합이다! 단, 해당 구간들을 먼저 더하는 것이 아니라 시작점에만 값을 더해두고, 끝나는지점 +1의 위치에 -1을 해두어 해당 구간을 지나가는 동안 +1을 하라는 것을 표시해두는것이다.
// 이렇게 하면 마지막에 한번에 연산할 때만 O(N)이 걸리고 기록에는 O(1)이 걸려 상당히 편리한 것이다!
// 이 개념은 누적합으로 알고있었는데 따로 부르는 알고리즘 용어가 있었나보다!

#include <iostream>
#include <vector>

using namespace std;

int N, M, best_eating = 0;
vector<int> taste_sections(1000002, 0);


int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;
    int s, e;
    // s(맛)을 예외로 두고 영양소를 기준으로 생각해보자. 예시로 {3, 7}로 이루어진 학생이 있다면, 
    // 이 학생은 영양소가 7이상, M-3이하 라면 무조건 먹게된다. [그 이유는, M-7-3안에는 무조건 나머지가 맛으로 가기 때문]
    // 그렇다면 이 구간에 전부 +1을 체크해두고 모든 구간을 순회하여 그 중 가장 큰값이 가장 많은 학생이 먹는 경우가 되는 것이다.
    // 예시) M = 20일때, {3, 7}로 이루어져 있다면 영양소가 7이상이고, 17이하라면 해당 음식은 먹는것이다.
    for (int i=0; i<N; ++i) {
        cin >> s >> e;
        // s와 e의 구간이 M의 구간과 같으므로 둘의 합이 M보다 큰 경우가 발생할 수 있기 때문에 걸러낸다.
        if (e > M - s) continue;
        taste_sections[e]++;
        taste_sections[M- s + 1]--;
    }
    
    int now = 0;
    for (int i=0; i<=M; ++i) {
        if (taste_sections[i] != 0) now += taste_sections[i];
        best_eating = max(best_eating, now);
    }
    
    cout << best_eating;

    return 0;
}
