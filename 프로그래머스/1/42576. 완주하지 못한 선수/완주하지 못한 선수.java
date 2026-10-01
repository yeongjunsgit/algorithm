import java.util.*;

class Solution {
    public String solution(String[] participant, String[] completion) {
        String answer = "";
        HashMap<String, Integer> goalIn = new HashMap<>();
        
        for (String s : completion) {
            goalIn.put(s, goalIn.getOrDefault(s, 0) + 1);
        }
        
        for (String s : participant) {
            if (goalIn.getOrDefault(s, -1) == -1 || goalIn.get(s) == 0) {
                answer = s;
                break;
            }
            else if (goalIn.getOrDefault(s, -1) > 0) {
                goalIn.put(s, goalIn.get(s) - 1);
            }
        }
        
        return answer;
    }
}