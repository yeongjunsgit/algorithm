import java.util.*;

class Solution {
    public int[] solution(int[] array, int[][] commands) {
        int N = commands.length;
        int[] answer = new int[N];
        for (int i=0; i<N; ++i) {
            int[] cuting = Arrays.copyOfRange(array, commands[i][0] - 1, commands[i][1]);
            Arrays.sort(cuting);
            answer[i] = cuting[commands[i][2] - 1];
        }
        
        
        return answer;
    }
}