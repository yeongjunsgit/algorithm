import java.util.HashSet;

class Solution {
    public String solution(String s, String skip, int index) {
        String answer = "";
        HashSet<Character> passed = new HashSet<>();
        int N = s.length(), M = skip.length();
        for (int i=0; i<M; ++i) {
            passed.add(skip.charAt(i));
        }
        
        for (int i=0; i<N; ++i) {
            char now = s.charAt(i);
            for (int j=0; j<index; ++j) {
                now++;
                if (now == '{') {
                    now = 'a';
                }
                while (passed.contains(now)) {
                    now++;
                    if (now == '{') {
                        now = 'a';
                    }
                }
            }
            
            answer += now;
            
        }
        
        return answer;
    }
}