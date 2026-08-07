/*
비가 오는 곳을 표기해둔다 이때, 비가 떨어지는 순서의 값을 표기한다. 그리고 존재하는 좌표들을 모두 축약시켜서 시작점을 기준으로 가장 작은 값을 가진 곳을 찾는다.
*/

import java.util.*;

class Solution {
    public int[] solution(int m, int n, int h, int w, int[][] drops) {
        int K = drops.length;
        int[] answer = new int[2];
        int[][] dessertArea = new int[m][n], skipArea = new int[m][n], doubleSkipArea = new int[m][n];
        // 비가 내린곳을 순서대로 기록
        for (int i=0; i<K; ++i) {
            dessertArea[drops[i][0]][drops[i][1]] = i + 1;
        }
        // 가로 먼저 축약
        for (int t=0; t<m; ++t) {
            Deque<Integer> rowWindow = new ArrayDeque<>();
            
            for (int i=0; i<n; ++i) {
                // 큐가 비어있지 않다면, 현재 넣을 값보다 큰 값들은 전부 제외
                while (!rowWindow.isEmpty() && dessertArea[t][i] != 0 && dessertArea[t][i] < dessertArea[t][rowWindow.peekLast()]) {
                    // System.out.println("현재 열 " + t + ", 현재 행 " + i + "= " + rowWindow.peekLast() + "를 제거");
                    rowWindow.pollLast();
                }
                
                // 큐에 현재 idx를 추가
                if (dessertArea[t][i] != 0) {
                    rowWindow.addLast(i);
                    // System.out.println("현재 열 " + t + ", 현재 행 " + i + "= " + i + "추가됨");
                }
                
                // 현재 deque의 크기가 w를 넘은 경우, 빠져야하는 idx값을 제거
                while (!rowWindow.isEmpty() && rowWindow.peekFirst() <= i - w) {
                    // System.out.println("현재 열 " + t + ", 현재 행 " + i + "= " + rowWindow.peekFirst() + "인덱스 범위 밖으로 제거됨");
                    rowWindow.pollFirst();
                }
                
                // 현재 들어있는 값중 가장 큰 값을 기록
                // 가장 먼저 기록이되는 시점은 w = 2일때, idx= 1임
                // 현재 값으로는 1 - 2 = -1로 0번 인덱스에 기록안됨
                if (!rowWindow.isEmpty() && i - w + 1 >= 0) {
                    skipArea[t][i - w + 1] = dessertArea[t][rowWindow.peekFirst()];
                    int tt = i - w + 1;
                    // System.out.println("현재 열 " + t + ", 현재 행 " + tt + "에 " + skipArea[t][i - w + 1] + "가 최소값으로 기록");
                }
            }
        }
//         for (int i=0; i<m; ++i) {
//             for (int j=0; j<n; ++j) {
//                 System.out.print(skipArea[i][j] + " ");
                
//             }
//             System.out.println();
            
//         }
//         System.out.println();
        
        
        
        // 가로로 축약한 값을 세로로 축약
        for (int t=0; t<n; ++t) {
            Deque<Integer> colWindow = new ArrayDeque<>();
            
            for (int i=0; i<m; ++i) {
                // 큐가 비어있지 않다면, 현재 넣을 값보다 큰 값들은 전부 제외
                while (!colWindow.isEmpty() && skipArea[i][t] != 0 && skipArea[i][t] < skipArea[colWindow.peekLast()][t]) {
                    colWindow.pollLast();
                }
                
                // 큐에 현재 idx를 추가
                if (skipArea[i][t] != 0) {
                    colWindow.addLast(i);
                }
                
                // 현재 deque의 크기가 h를 넘은 경우, 빠져야하는 idx값을 제거
                while (!colWindow.isEmpty() && colWindow.peekFirst() <= i - h) {
                    colWindow.pollFirst();
                }
                // 현재 들어있는 값중 가장 큰 값을 기록
                if (!colWindow.isEmpty() && i - h + 1 >= 0) {
                    doubleSkipArea[i - h + 1][t] = skipArea[colWindow.peekFirst()][t];
                }
                
            }
        }
//         for (int i=0; i<=m-h; ++i) {
//             for (int j=0; j<=n-w; ++j) {
//                 System.out.print(doubleSkipArea[i][j] + " ");
                
//             }
//             System.out.println();
//         }
        
        getResult(doubleSkipArea, n, m, h, w, answer);
        
        
        return answer;
    }
    
    public void getResult(int[][] doubleSkipArea, int n, int m, int h, int w, int[] answer)
    {
        int bestTime = 0;
        for (int i=0; i<=m-h; ++i) {
            for (int j=0; j<=n-w; ++j) {
                if (doubleSkipArea[i][j] == 0) {
                    answer[0] = i;
                    answer[1] = j;
                    return;
                }
                
                if (doubleSkipArea[i][j] > bestTime) {
                    bestTime = doubleSkipArea[i][j];
                    answer[0] = i;
                    answer[1] = j;
                }
            }
        }
        return;
    }
    
}