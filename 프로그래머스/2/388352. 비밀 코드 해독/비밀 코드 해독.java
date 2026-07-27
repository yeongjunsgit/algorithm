class Solution {
    
    public boolean checkCombi(int[][] q, int[] ans, int[] now, int idx) {
        int count = 0;
        for (int i=0; i<5; ++i) {
            for (int j=0; j<5; ++j) {
                if (q[idx][i] == now[j]) {
                    count++;
                    break;
                }
            }
        }
        
        if (count != ans[idx]) return false;
        else return true;
    }
    
    
    public int solution(int n, int[][] q, int[] ans) {
        int answer = 0, Q = q.length;
        for (int a=1; a<=n; ++a) {
            for (int b=a+1; b<=n; ++b) {
                for (int c=b+1; c<=n; ++c) {
                    for (int d=c+1; d<=n; ++d) {
                        for (int e=d+1; e<=n; ++e) {
                            int[] now = {a, b, c, d ,e};
                            boolean isOk = true;
                            for (int i=0; i<Q; ++i) {
                                if (!checkCombi(q, ans, now, i)) {
                                    isOk = false;
                                    break;
                                }
                            }
                            if (isOk) answer++;
                        }
                    }
                }
            }
        }
        
        
        
        return answer;
    }
}