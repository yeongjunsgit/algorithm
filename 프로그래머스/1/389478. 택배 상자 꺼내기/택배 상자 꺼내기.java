class Solution {
    public int solution(int n, int w, int num) {
        int answer = 0;
        int m = n / w;
        if (n % w != 0) m++;
        int[][] graph = new int[m][w];
        int cnt = 1;
        int[] num_loca = new int[2];
        for (int i=0; i<m; ++i) {
            if (i % 2 != 0) {
                for (int j=w-1; j>=0; --j) {
                    graph[i][j] = cnt;
                    if (cnt == num) {
                        num_loca[0] = i;
                        num_loca[1] = j;
                    }
                    cnt++;
                    if (cnt > n) break;
                }
            }
            else {
                for (int j=0; j<w; ++j) {
                    graph[i][j] = cnt;
                    if (cnt == num) {
                        num_loca[0] = i;
                        num_loca[1] = j;
                    }
                    cnt++;
                    if (cnt > n) break;
                    
                }
            }
        }
        // System.out.println(m);
        // System.out.print(num_loca[0]);
        // System.out.print(" ");
        // System.out.println(num_loca[1]);
        // System.out.println(graph[4][0]);
        
        while (num_loca[0] < m) {
            if (graph[num_loca[0]][num_loca[1]] != 0) {
                answer++;
                num_loca[0]++;
            }
            else break;
        }
        
        
        return answer;
    }
}