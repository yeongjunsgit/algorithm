/*
트럭이 모두 지나갈때까지 걸리는 시간을 따져야한다. 트럭은 반드시 정해진 순서대로만 간다.
보아하니 다리를 1칸 지나는데 1초가 걸린다. bridge_length가 10이라면 다 지나가는데 10초가 걸리는것이다.
진입했을때 부터 바로 1칸을 이동한 것으로 친다. bridge_length가 넘어가면 바로 다리를 건넌 것으로 친다.
흠... 순서가 정해져있으니 괜찮지만 시간을 1초씩 다루는건 좋아보이지 않는다.
모든 트럭이 나가는 시간은 정해져있다. 그렇다면 순서대로 트럭을 넣되, 가능한 만큼 집어넣고 다리에 더 이상 넣을 수 없으면 맨 앞의 트럭이 지나갈때 까지 시간을 넘기고, 바로 해당 트럭을 빼버린다.
이후에 다음 트럭이 바로 들어갈 수 있는지 확인하고 이런 식으로 시간을 보내면 될 것 같다. 다리를 건너는데 걸리는 시간은 "길이 + 1"초 임을 기억하자.

- 구현해야 하는 것-
1. 현재 다리위에 있는 트럭을 나타내는 deque (트럭의 idx 값을 저장)
이외는 단순 연산으로 해결할 수 있어보인다.

*/
import java.util.*;

class TInfo {
    int w, iT;
    
    TInfo(int w, int iT) {
        this.w = w;
        this.iT = iT;
    }
}


class Solution {
    public int solution(int bridge_length, int weight, int[] truck_weights) {
        int answer = 0;
        ArrayDeque<TInfo> que = new ArrayDeque<>();
        int N = truck_weights.length, nowW = 0, nowT = 1;
        
        for (int i=0; i<N; ++i) {
            int[] tmp = goTruck(i, que, nowW, nowT, bridge_length, weight, truck_weights);
            nowW = tmp[0];
            nowT = tmp[1];
        }
        
        while (!que.isEmpty()) {
            TInfo truck = que.pollFirst();
            nowT = truck.iT;
        }
        
        answer = nowT;
        
        return answer;
    }
    
    public static int[] goTruck(int idx, ArrayDeque<TInfo> que, int nowW, int nowT, int bridge_length, int weight, int[] truck_weights) {
        // 현재 시간을 보고 도착한 트럭은 뺀다.
        while (!que.isEmpty() && que.peekFirst().iT <= nowT) {
            TInfo T = que.pollFirst();
            nowW -= T.w;
        }
        
        if (nowW + truck_weights[idx] <= weight) {
            nowW += truck_weights[idx];
            que.offer(new TInfo(truck_weights[idx], nowT + bridge_length));
            // 1초 경과
            nowT++;
        }
        // 현재 트럭이 무게 초과로 들어갈 수 없을때, 들어갈 수 있을때까지 트럭들을 뺀다. 그 후 현재 트럭을 넣는다.
        else {
            while (nowW + truck_weights[idx] > weight) {
                TInfo fTruck = que.pollFirst();
                nowW -= fTruck.w;
                nowT = fTruck.iT;
            }
            nowW += truck_weights[idx];
            que.offer(new TInfo(truck_weights[idx], nowT + bridge_length));
            // 1초 경과
            nowT++;
        }
        
        // System.out.println("현재 트럭 idx = " + idx + " 현재 nowW = " + nowW + " 현재 nowT = " + nowT);
        
        return new int[] {nowW, nowT};
    }
    
}

