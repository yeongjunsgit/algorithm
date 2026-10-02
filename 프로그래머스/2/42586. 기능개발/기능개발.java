import java.util.*;

class Solution {
    public int[] solution(int[] progresses, int[] speeds) {
        int[] answer = {};
        ArrayDeque<Integer> que = new ArrayDeque<>();
        ArrayList<Integer> list = new ArrayList<>();
        int N = progresses.length;
        
        for (int i=0; i<N; ++i) {
            int completeTime = (100 - progresses[i]) / speeds[i];
            if ((100 - progresses[i]) % speeds[i] != 0){
                completeTime++;
            }
            que.offer(completeTime);
        }
        
        while (!que.isEmpty()) {
            int nowDay = que.pollFirst(), cnt = 1;
            while (!que.isEmpty() && que.peekFirst() <= nowDay) {
                que.pollFirst();
                cnt++;
            }
            
            list.add(cnt);
        }
        
        answer = list.stream().mapToInt(Integer::intValue).toArray();
        
        return answer;
    }
}