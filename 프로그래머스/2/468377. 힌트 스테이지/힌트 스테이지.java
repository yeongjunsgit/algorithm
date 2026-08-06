/*
각각의 문제를 풀때 힌트를 쓸것인가 안 쓸것인가를 묻는 문제 결국 최소 비용을 구하는 문제다.
힌트를 구매하는 조합들 중 가장 좋은 것으로 해볼까?
조합의 개수가 너무 많은 것 같다... 어떻게 접근 해야할까?? 배낭문제...?
배낭문제로 하면 문제가 생기는게 이전에 힌트를 몇개 샀는지에 대한 추적이 어렵다
dfs가 의외로 정답일지도 모르겠다. 백트래킹을 하는 것이다. 현재 구한 값을 기준으로 값이 넘어가면 바로 돌아가는 것?
-> 이거 문제가 있는게 힌트의 효율이 문제다. 처음에는 손해더라도 몇개 더 사면 갑자기 이득일 수도 있기 때문인데... 이러면 백트래킹을 하는데 문제가 좀 생길거 같다.
결국에 최후까지 이동하게 된다면 효율관리가 가능하지만 이러면 백트래킹이 안되기 때문인데... 이를 먼저 체크하는 방식으로 봐야할까?
여기서 반드시 힌트는 현재 이후의 값에 대해서만 나타난다고 했다. 즉 내가 여기까지 왔으면, 현재 위치는 이보다 더 이득일 수는 없다는 것이다.
각각의 문제별로 최고의 이득을 기록해두고, 이를 백트래킹한다? 하지만... 초반 문제를 포기하고 이후 힌트를 사는게 유리할 수도 있다 보장이 되는 느낌은 아님
각각의 힌트를 구매했을때 효율을 기록한다? -> 이것도 어려운게 효율은 절대적이지 않다. 이전에 산 힌트가 현재 힌트와 동일한 문제를 커버해주면? 이는 문제가 된다 즉, 상황에 따라 달라짐으로 연산을 하는 것과 다를바가 없다.

이걸 어떻게 접근해야할까 ㅠㅠ?? 진짜 어렵다 
아? 힌트를 최대 1개까지 밖에 구매를 못한다고한다... 이러면 얘기가 달라지는데?
그러면 그냥 dfs로 충분히 가능하겠다!!

*/

import java.util.*;

class Solution {
    int result = 20000000;
    
    public int getCost(int[][] cost, int[][] hint, int[] buyHint, int N) {
        // 현재 힌트를 구매한 것을 통해 가격을 계산
        int tmp = 0;
        int[] hintCnt = new int[N+1];
        
        // 힌트 구매 가격을 tmp에 더하고 각 문제에 힌트의 개수를 정산
        for (int i=1; i<N; ++i) {
            if (buyHint[i] != 0) {
                tmp += hint[i-1][0];
                int hSize = hint[i-1].length;
                for (int j=1; j<hSize; ++j) {
                    hintCnt[hint[i-1][j]]++;
                }
            }
        }
        // 정산된 힌트의 개수를 토대로 스테이지 해결 소모값을 tmp에 저장
        // 힌트의 개수가 한도를 넘어가는 경우에는 최대 힌트로만 적용
        for (int i=1; i<=N; ++i) {
            tmp += cost[i-1][Math.min(N-1, hintCnt[i])];
        }
        
        return tmp;
        
    }
    
    
    public void dfs(int[][] cost, int[][] hint, int[] buyHint, int stage, int N) {
        // 마지막 스테이지 이후에 현재 발생하는 비용을 기록
        if (stage > N) {
            int nowCost = getCost(cost, hint, buyHint, N);
            result = Math.min(result, nowCost);
            return;
        }
        
        // 힌트를 사지 않고 다음 문제로
        dfs(cost, hint, buyHint, stage + 1, N);
        
        // 힌트를 사고 다음 문제로(단, 마지막 문제에서는 살 수 없음)
        if (stage != N) {
            buyHint[stage] = 1;
            dfs(cost, hint, buyHint, stage + 1, N);
            buyHint[stage] = 0;
        }
        
        return;
    }
    
    
    public int solution(int[][] cost, int[][] hint) {
        int answer = 0, N = cost.length;
        int[] buyHint = new int[N+1];
        
        dfs(cost, hint, buyHint, 1, N);
        
        answer = result;
        
        
        return answer;
    }
}