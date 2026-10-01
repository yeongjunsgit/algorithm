import java.util.*;

class Solution {
    public int solution(String[][] clothes) {
        int answer = 0;
        HashMap<String, Integer> cTypes = new HashMap<>();
        
        for (String[] t : clothes) {
            cTypes.put(t[1], cTypes.getOrDefault(t[1], 0) + 1);
        }
        int[] values = cTypes.values().stream().mapToInt(Integer::intValue).toArray();
        int multi = 1;
        
        for (int i : values) {
            multi *= i + 1;
        }
        
        answer = multi - 1;
        
        return answer;
    }
}