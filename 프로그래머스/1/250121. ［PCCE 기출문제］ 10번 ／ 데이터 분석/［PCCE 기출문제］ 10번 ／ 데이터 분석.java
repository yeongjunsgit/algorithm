import java.util.*;

class Solution {
    HashMap<String, Integer> commands = new HashMap<> (
        Map.of(
            "code", 0,
            "date", 1,
            "maximum", 2,
            "remain", 3
        )
    );
    
    public int[][] solution(int[][] data, String ext, int val_ext, String sort_by) {
        int[][] answer = {};
        int sort_idx = commands.get(sort_by), target_idx = commands.get(ext);
        Arrays.sort(data, (a, b) -> a[sort_idx] - b[sort_idx]);
        ArrayList<int[]> result = new ArrayList<>();
        
        for (int[] tmp : data) {
            if (tmp[target_idx] < val_ext) {
                result.add(tmp);
            }
        }
        
        answer = result.toArray(new int[result.size()][]);
        
        return answer;
    }
}