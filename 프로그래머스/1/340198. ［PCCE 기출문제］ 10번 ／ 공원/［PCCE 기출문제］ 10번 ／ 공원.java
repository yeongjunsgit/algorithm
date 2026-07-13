/*
주어지는 원소는 10개
모든 위치에서 최악의 경우의 조합은 11~20 총 10개
50 * 50에 대해서 가장 유리한 위치를 찾아야 함
모든 위치에서 20*20 400 * 2500 = 1000000 = 100만 정도 이게 10번이면 1000만
일단 브루트포스로도 가능해보이는데... 이게 최선?
돗자리의 작은 수부터 시도 만약에 한곳이라도 돗자리 완성이 가능하다면? 더 이상 다른 위치에서 해당 돗자리를 사용이 가능한지 볼 필요 없음
진행하다가 단 1곳이라도 둘 수가 없는 돗자리가 발생하면 그 이후의 돗자리는 전부 사용 불가능
정렬을 이용한 백트래킹? 으로 어느정도 최적화가 가능해보임
*/

import java.util.Arrays;

class Solution {
    // 현재 위치(x, y)에서 s*s의 돗자리를 깔 수 있는지를 판단화는 함수
    boolean checkLoca(int N, int M, int x, int y, int s, String[][] park)
    {
        if (s == 4) {
            System.out.println("in");
        }
        
        for (int i=0; i<s; ++i) {
            for (int j=0; j<s; ++j) {
                if (x + i < N && y + j < M && !park[x + i][y + j].equals("-1")) return false;
            }
        }

        return true;
    }
    
    
    public int solution(int[] mats, String[][] park) {
        int answer = -1;
        Arrays.sort(mats);
        int N = park.length, M = park[0].length, K = mats.length;
        // System.out.println(K);
        // 모든 위치를 순회해서, 해당 위치에서 오른쪽과 하단으로 정사각형 사이즈를 두어 둘 수 있는 곳이 있는지 확인하자
        for (int k=0; k<K; ++k) {
            // System.out.println(mats[k]);
            boolean is_ok = true;
            for (int i=0; i<= N - mats[k]; ++i) {
                int before = answer;
                for (int j=0; j<= M - mats[k]; ++j) {
                    boolean check = checkLoca(N, M, i, j, mats[k], park);
                    if (check) {
                        answer = mats[k];
                        break;
                    }
                }
                // if (before != answer) break;
                // else if (before == answer) is_ok = false;
            }
            // System.out.println(is_ok);
            // if (!is_ok) break;
        } 
        
        return answer;
    }
}