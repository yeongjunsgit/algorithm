class Solution {
    int N;
    public int binaryCheck(int[] diffs, int[] times, long limit)
    {
        int start = 1;
        int end = 100000;
        
        while (start <= end) {
            int mid = (start + end) / 2;
            
            if (!solvePuzzle(diffs, times, limit, mid)) {
                start = mid + 1;
            }
            else {
                end = mid - 1;
            }
        }
        
        return start;
        
    }
    
    public boolean solvePuzzle(int[] diffs, int[] times, long limit, int level)
    {
        long nowTime = 0;
        for (int i=0; i<N; ++i) {
            // System.out.println(diffs[i] + " + " + times[i] + " = " + nowTime);
            if (diffs[i] > level) {
                long tmp = (diffs[i] - level) * (times[i] + times[i - 1]) + times[i];
                nowTime += tmp;
            }
            else {
                nowTime += times[i];
            }
            
            if (nowTime > limit) return false;
        }
        return true;
    }
    
    
    
    public int solution(int[] diffs, int[] times, long limit) {
        int answer = 0;
        N = diffs.length;
        
        answer = binaryCheck(diffs, times, limit);
        
        
        return answer;
    }
}