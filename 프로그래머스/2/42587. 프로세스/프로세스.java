
/*
구현해야 할것
1. class를 이용해 타겟인지 아닌지를 판단할 수 있어야함
2. 우선순위의 개수를 파악
3. 우선순위의 최고 값을 파악
*/

import java.util.*;

class Target {
    int p;
    boolean isTarget;
    
    Target(int p, boolean isTarget) {
        this.p = p;
        this.isTarget = isTarget;
    }
}


class Solution {
    public int solution(int[] priorities, int location) {
        int answer = 0;
        int N = priorities.length, maxP = 0;
        int[] map = new int[10];
        ArrayDeque<Target> que = new ArrayDeque<>();
        
        for (int i=0; i<N; ++i) {
            boolean isT = i == location ? true : false;
            que.offer(new Target(priorities[i], isT));
            maxP = Math.max(maxP, priorities[i]);
            map[priorities[i]]++;
        }
        answer = processing(maxP, map, que);
        
        
        return answer;
    }
    
    public static int processing(int maxP, int[] map, ArrayDeque<Target> que) {
        int nowP = maxP, cnt = 1;
        while (!que.isEmpty()) {
            Target now = que.pollFirst();
            if (now.p == nowP) {
                // 현재 프로세스가 타겟이라면 현재 턴을 반환
                if (now.isTarget) {
                    return cnt;
                }
                // 해당 프로세스가 타겟이 아니라면
                else {
                    map[now.p]--;
                    // 만약 현재 최고 우선순위의 개수가 0이 된다면 다음 우선순위로 간다.
                    if (map[now.p] == 0) {
                        while (map[nowP] == 0) {
                            nowP--;
                        }
                    }
                }
                cnt++;
            }
            else {
                // 현재 프로세스가 현재 최고 우선순위보다 낮다면 다시 que의 맨 뒤로 이동
                que.offer(now);
            }
        }
        
        return -1;
    }
    
    
}
