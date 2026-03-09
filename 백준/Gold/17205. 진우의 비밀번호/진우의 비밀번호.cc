// 아무리 봐도 이해가 완벽하게 되는 문제가 아니었다... 허허... 매우 어렵다...!
// 방식은 이해가 대충 갔다. 현재위치까지 도달하기 위해서는 이전에 발생할 수 있는 모든 경우의 수를 지나쳐와야하기 때문에
// b 한글자라면 10의 길이에서 a ~ azzzzzzzzz의 모든 경우를 거쳐야 b가 될 수 있다.
// 만약 c라면? a ~ azzzzzzzzz의 모든 경우를 2번 거쳐야한다.
// 이런식으로 cb라면 a ~ azzzzzzzzz의 모든 경우를 2번 거쳐야하고 a ~ azzzzzzz까지의 경우를 모두 거쳐야한다.
// 이걸 단순히 보면 해당 자리에서 (26^해당 자리값)을 해야 그 다음 비밀번호를 만들 수 있기 때문에 이렇게 진행한다.
// aaa -> aba가 되려면 aaa~ aaz 전부다 해야하니 26번, aaa -> baa가 되려면 aa ~ zz까지 + a ~ z까지가 필요하니 26^2 + 26번 과 같은 식
// 뭔가 이해는 갔는데 다시 풀라고하면... 떠오를지 모르겠다...

#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int N;
string target;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> target;
    
    long long result = 0;
    int L = target.size();
    
    for (int i=0; i<L; ++i) {
        int passed_alpha = target[i] - 'a';
        long long tmp = 0;
        // a 이후라면 알파벳의 순서만큼 모든 자리에서 26^j가 발생한다.
        if (passed_alpha > 0) {
            for (int j=0; j<=N-(i+1); ++j) {
                tmp += pow(26, j);
            }
            // 현재 자리까지 발생하는 모든 경우에서 a 이후의 알파벳 순서만큼 곱한다.
            result += tmp * passed_alpha;
        }
        // 본인 더하기
        result += 1;
    }
    
    cout << result;

    return 0;
}