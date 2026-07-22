class Solution {
    public String solution(String[] cards1, String[] cards2, String[] goal) {
        String answer = "";
        int N = cards1.length, M = cards2.length, K = goal.length, oneIdx = 0, twoIdx = 0, goalIdx = 0;
        
        while (goalIdx < K && (oneIdx < N || twoIdx < M)) {
            if (oneIdx < N && goal[goalIdx].equals(cards1[oneIdx])) {
                goalIdx++;
                oneIdx++;
            }
            else if (twoIdx < M && goal[goalIdx].equals(cards2[twoIdx])) {
                goalIdx++;
                twoIdx++;
            }
            else break;
        }
        
        if (goalIdx == K) answer = "Yes";
        else answer = "No";
        
        
        return answer;
    }
}