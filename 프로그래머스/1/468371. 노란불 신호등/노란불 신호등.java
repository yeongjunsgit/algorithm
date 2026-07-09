class Solution {
    public int solution(int[][] signals) {
        int answer = 0;
        int n = signals.length;
        // 각각 인덱스 순서대로 신호등의 노란불 시작시간, 노란불이 다시 돌아오는 시간, 노란불 유지 시간을 기록한다.
        int[][] start_and_gap = new int[n][3];
        // System.out.println(n);
        for (int i=0; i<n; ++i) {
            start_and_gap[i][0] = signals[i][0] + 1;
            start_and_gap[i][1] = signals[i][0] + signals[i][2];
            start_and_gap[i][2] = signals[i][1];
            // System.out.print(start_and_gap[i][0]);
            // System.out.print(start_and_gap[i][1]);
            // System.out.print(start_and_gap[i][2]);
            // System.out.println();
            
        }
    
        int[] check_arr = new int[100000000];
        
        for (int i=0; i<n; ++i) {
            int tmp = start_and_gap[i][0];
            while (tmp < 100000000) {
                // System.out.println(tmp);
                for (int j=0; j<start_and_gap[i][2]; ++j) {
                    if (tmp >= 100000000) break;
                    check_arr[tmp] += 1;
                    tmp++;
                    // System.out.println(tmp);
                }
                tmp += start_and_gap[i][1];
                // System.out.println(tmp);
            }
            // System.out.println();
        }
        
        // System.out.println(check_arr[13]);
        
        for (int i=1; i<100000000; ++i) {
            if (check_arr[i] == n) {
                answer = i;
                break;
            }
        }
        
        if (answer == 0) answer = -1;
        return answer;
    }
}