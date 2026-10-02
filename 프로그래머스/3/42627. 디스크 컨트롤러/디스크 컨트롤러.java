/*
우선순위를 가지는 순서대로 작업을 실행하되, 모든 작업이 요청부터 완료까지 걸리는 시간을 다 더하고 그값을 평균을 내야한다.
구현해야할 것은 다음과 같다.
1. 필요한 정보를 저장할 수 있는 class를 선언한다
 1) 작업이 요청된 시간
 2) 작업에 걸리는 시간
 3) 작업의 번호
2. class를 담고 정해진 우선순위로 정렬하는 우선순위 큐를 선언한다.
3. 현재 시간을 추적하는 int가 필요하다.

시간을 1초씩 흐르게하는건 딱히 좋아보이지 않는다. 우선순위가 높은 작업을 수행하면서, 해당 작업의 시작시간, 종료시간을 기준으로 시간을 넘기고 이에 맞게 연산하면 될 것 같다.

진행하다보니 대기큐와 프로세스를 담는 큐가 따로 존재해야한다는 것을 깨달았다.
그래서 추가로 프로세스를 담는 큐를 선언한다. 이는 작업 입장 순서가 가장 빠른것으로 우선순위를 둔다.

*/
import java.util.*;

class Process {
    int id, inT, pT;
    
    Process(int id, int inT, int pT) {
        this.id = id;
        this.inT = inT;
        this.pT = pT;
    }
}


class Solution {
    public int solution(int[][] jobs) {
        int answer = 0;
        int N = jobs.length, nowT = 0;
        // 대기큐인 que를 선언한다.
        PriorityQueue<Process> que = new PriorityQueue<>((a, b) -> {
                if (a.pT == b.pT) {
                    if (a.inT == b.inT) {
                        return Integer.compare(a.id, b.id);
                    }
                    return Integer.compare(a.inT, b.inT);
                }
                return Integer.compare(a.pT, b.pT);
            }
        );
        
        // 프로세스를 담는 pQue를 선언한다.
        PriorityQueue<Process> pQue = new PriorityQueue<>((a, b) -> {
            return Integer.compare(a.inT, b.inT);
        });
        
        for (int i=0; i<N; ++i) {
            pQue.offer(new Process(i, jobs[i][0], jobs[i][1]));
        }
        
        while (!pQue.isEmpty() || !que.isEmpty()) {
            if (!pQue.isEmpty()) {
                nowT = insertQue(nowT, pQue, que);
            }
            int[] tmp = RunP(nowT, que);
            nowT = tmp[0];
            answer += tmp[1];
        }
        
        return answer / N;
    }
    
    // 현재 시간에 따라 작업을 대기큐로 옮긴다. 만약, 현재 시간에 넣을 수 있는 작업이 없다면 시간을 흐르게 한다.
    public static int insertQue(int nowT, PriorityQueue<Process> pQue, PriorityQueue<Process> que) {
        // 만약 현재 que가 비어있고 시간이 프로세스 큐의 가장 빠른 process 요청 시간 미만이라면, 해당 시간으로 nowT를 올리고 넣는다.
        if (que.isEmpty() && nowT < pQue.peek().inT) {
            nowT = pQue.peek().inT;
        }
        // 현재 시간이 프로세스큐의 가장 빠른 process의 요청 시간 이상이라면, 가능한 만큼 대기큐로 process들을 옮긴다.
        while (!pQue.isEmpty() && nowT >= pQue.peek().inT) {
            que.offer(pQue.poll());
        }
        
        return nowT;
    }
    
    
    public static int[] RunP(int nowT, PriorityQueue<Process> que) {
        Process now = que.poll();
        nowT += now.pT;
        
        int inToOver = nowT - now.inT;
        
        return new int[]{nowT, inToOver};
    }
}