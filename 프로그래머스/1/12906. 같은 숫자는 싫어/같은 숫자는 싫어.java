import java.util.*;

public class Solution {
    public int[] solution(int []arr) {
        int[] answer = {};
        
        // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
        System.out.println("Hello Java");
        ArrayDeque<Integer> passed = new ArrayDeque<>();
        
        for (int i : arr) {
            if (passed.isEmpty()) {
                passed.offerLast(i);
            }
            else {
                if (passed.peekLast() != i) {
                    passed.offerLast(i);
                }
            }
        }
        
        answer = passed.stream().mapToInt(Integer::intValue).toArray();

        return answer;
    }
}