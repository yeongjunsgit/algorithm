import java.util.*;

class Solution {
    public int solution(int[] scoville, int K) {
        int answer = 0;
        PriorityQueue<Integer> que = new PriorityQueue<>((a, b) -> {
            return Integer.compare(a, b);
        });
        
        for (int s : scoville) {
            que.offer(s);
        }
        
        while (que.size() >= 2 && que.peek() < K) {
            answer++;
            int worst = que.poll();
            int nextWorst = que.poll();
            int mix = worst + (nextWorst * 2);
            
            que.offer(mix);
        }
        
        if (que.peek() < K) {
            answer = -1;
        }
        
        return answer;
    }
}