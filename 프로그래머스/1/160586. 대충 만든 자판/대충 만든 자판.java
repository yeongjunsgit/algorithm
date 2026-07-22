import java.util.HashMap;

class Solution {
    public int[] solution(String[] keymap, String[] targets) {
        int M = targets.length;
        int[] answer = new int[M];
        HashMap<Character, Integer> clickTime = new HashMap<>();
        
        // 키패드들을 순회하며 입력가능한 알파벳들을 가장 낮은 클릭 횟수로 저장
        for (String tmp : keymap) {
            int tmpSize = tmp.length();
            for (int i=0; i<tmpSize; ++i) {
                clickTime.put(tmp.charAt(i), Math.min(clickTime.getOrDefault(tmp.charAt(i), 101), i + 1));
            }
        }
        // target을 순회하면서 클릭 횟수를 계산. 단, 불가할때는 -1
        for (int i=0; i<M; ++i) {
            int nowClick = 0, nowSize = targets[i].length();
            for (int j=0; j<nowSize; ++j) {
                int click = clickTime.getOrDefault(targets[i].charAt(j), 101);
                if (click == 101) {
                    nowClick = -1;
                    break;
                }
                else nowClick += click;
            }
            answer[i] = nowClick;
        }
        
        return answer;
    }
}