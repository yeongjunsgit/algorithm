import java.util.*;

class Solution {
    public int solution(int[] nums) {
        int answer = 0;
        HashSet<Integer> realCategory = new HashSet<>();
        int canPick = nums.length / 2;
        for (int i : nums) {
            realCategory.add(i);
        }
        
        answer = Math.min(canPick, realCategory.size());
        
        
        return answer;
    }
}