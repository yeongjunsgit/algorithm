import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.Collections;


class Solution {
    HashMap<String, Integer> memberToIdx = new HashMap<>();
    
    public String[] solution(String[] players, String[] callings) {
        String[] answer = {};
        ArrayList<String> members = new ArrayList<>(Arrays.asList(players));
        int N = players.length;
        for (int i=0; i<N; ++i) {
            memberToIdx.put(players[i], i);
        }
        for (String tmp : callings) {
            int idx = memberToIdx.get(tmp);
            // System.out.println("현재 호명자는 " + tmp + "이며, 바뀌는 대상자는 " + members.get(idx - 1) + "입니다");
            memberToIdx.put(members.get(idx - 1), idx);
            memberToIdx.put(tmp, idx - 1);
            Collections.swap(members, idx - 1, idx);
        }
        
        answer = members.toArray(new String[0]);
        
        return answer;
    }
}