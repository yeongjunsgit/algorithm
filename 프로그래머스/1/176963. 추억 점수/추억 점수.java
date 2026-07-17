import java.util.HashMap;

class Solution {
    public int[] solution(String[] name, int[] yearning, String[][] photo) {
        int N = name.length, M = photo.length;
        int[] answer = new int[M];
        HashMap<String, Integer> sScore = new HashMap<>();
        
        for (int i=0; i<N; ++i) {
            sScore.put(name[i], yearning[i]);
        }
        
        for (int i=0; i<M; ++i) {
            int now_score = 0;
            for (String s : photo[i]) {
                now_score += sScore.getOrDefault(s, 0);
            }
            answer[i] = now_score;
        } 
        
        return answer;
    }
}