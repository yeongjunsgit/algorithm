/*
물품의 개수가 40개 = 2^40 가능
브루트포스로는 안된다. 흠.. 그리디..? 우선순위를 주는게 어렵다 둘 중 가장 작은애가 가져가! 하기에는 각각 가진 한도가 있기때문...
무조건 다 훔쳐야 함 << 
하지만 중요한 것! A가 최소여야한다는 거다 (B는 엄청나게 많이 가져가도 문제가 없음)
그렇다고 한다면, A가 가장 무겁게 받는 값들을 최대한 B가 다 가져가고, 나머지를 A가 가져가는 방식이면 되지않을까?
안됌. {1, 2}, {2, 3}, {2, 1} 일때, 2, 3과 2, 1을 가져가려고 해서 문제가 발생함 최적은 1, 2와 2, 1을 가져가야함
아무리 생각해도 딱히 우선순위를 주고 그럴 수는 없을 것 같다.
dp는 어떨까?
40개의 사이즈의 dp를 만들어서 각 인덱스 번호별로 1개의 최적값을 정하는 것이다. A가 가장 낮고 B도 가장 낮아지는 값을 저장한다. 그리고 그 값은 제외하면서 계속해서 추가하는건..?
결국 검색했다... 배낭문제였다.. 그것도 B를 기준점으로 잡아서...
*/

import java.util.*;

class Solution {
    public int solution(int[][] info, int n, int m) {
        int answer = 121, N = info.length;
        int[][] dp = new int[40][121];
        for (int j=0; j<40; ++j) {            
            for (int i=0; i<121; ++i) {
                dp[j][i] = 999;
            }
        }
        if (info[0][0] < n) {            
            dp[0][0] = info[0][0];
        }
        if (info[0][1] < m) {
            dp[0][info[0][1]] = 0;
        }
        
        for (int t=1; t<N; ++t) {
            for (int i=m-1; i>=0; --i) {
                if (dp[t - 1][i] != 999) {
                    if (i + info[t][1] < m) {
                        dp[t][i + info[t][1]] = Math.min(dp[t - 1][i], dp[t][i + info[t][1]]);
                    }
                    if (dp[t - 1][i] + info[t][0] < n) {                        
                        dp[t][i] = Math.min(dp[t][i], dp[t - 1][i] + info[t][0]);
                    }
                }
            }
        }

        for (int i=0; i<m; ++i) {
            answer = Math.min(answer, dp[N-1][i]);
        }
        
        if (answer == 121) answer = -1;
        return answer;
    }
}
