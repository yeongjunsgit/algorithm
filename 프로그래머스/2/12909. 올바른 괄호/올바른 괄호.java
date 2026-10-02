import java.util.*;

class Solution {
    boolean solution(String s) {
        boolean answer = true;
        int N = s.length();
        ArrayDeque<Character> que = new ArrayDeque<>();
        answer = stacker(s, N, que);

        return answer;
    }
    
    public static boolean stacker(String s, int N, ArrayDeque<Character> que) {
        for (int i=0; i<N; ++i) {
            if (s.charAt(i) == '(') {
                que.offer(s.charAt(i));
            }
            else {
                if (que.isEmpty()) {
                    return false;
                }
                que.pollLast();
            }
        }
        
        if (que.isEmpty()) {
            return true;
        }
        else {
            return false;
        }
        
    }
}