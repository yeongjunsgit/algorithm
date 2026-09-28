/*
deque를 이용해서 S를 넣는다. 단 넣는 순간은 T에 따라서 넣는다.
이를 위해서, 주어지는 String 값을 이용해 ms 단위의 int 값으로 만들어 저장한다.
우선순위 큐를 이용해서 시작 값이 가장 낮은 값을 기준으로 우선순위를 주고 우선순위 큐가 빌때까지 반복한다.
deque에 있는 값의 맨 앞의 값을 계속 보면서 현재 넣으려는 시작값보다 작으면 빼는 방식으로 deque를 갱신한다.
진행 중 deque의 사이즈가 가장 큰 경우가 답이 된다.
~~ 한 지점에서 1초 간의 구간안에 드는 경우를 구하는 것이다 접근 방식을 조금만 더 바꿔보자!
일단 가능한 시간으로 치면 0 ~ 86,400,000 까지이다 이걸 배열로 전부 만들어서 관리 -> 매 위치마다 1000만큼 진행해야하므로 연산수가 너무 많아진다
배열로 하는건 말이 안되는듯하다 그렇다면 어차피 end에서부터 1초 까지는 다 유효한거니까... 걍 end에서 1000을 늘려주는건 어떨까?
*/


import java.util.*;

class LogTime {
    int s;
    int e;
    
    LogTime(int s, int e) {
        this.s = s;
        this.e = e;
    }
}


class Solution {
    public int solution(String[] lines) {
        int answer = 0;
        // Log의 시작 값과 끝 값을 정제해서 저장할 우선순위 큐
        PriorityQueue<LogTime> myLog = new PriorityQueue<>(
            (a, b) -> {
                if (a.s == b.s) {
                    return Integer.compare(a.e, b.e);
                }
                return Integer.compare(a.s, b.s);
            } 
        );
        changeS(lines, myLog);
        answer = solveLog(myLog);
        
        return answer;
    }
    
    
    public static void changeS(String[] lines, PriorityQueue<LogTime> myLog) {
        for (String S : lines) {
            int start = 0, end = 0;
            String[] dTS = S.split(" ");
            String[] Times = dTS[1].split(":");
            String[] pT = dTS[2].split("\\.");
            String[] nowS = Times[2].split("\\.");
            end += Integer.parseInt(Times[0]) * 3600000;
            end += Integer.parseInt(Times[1]) * 60000;
            end += Integer.parseInt(nowS[0]) * 1000;
            end += Integer.parseInt(nowS[1]);
            
            start = end;
            start -= Integer.parseInt(pT[0].replace("s", "")) * 1000 - 1;
            if (pT.length > 1) {
                start -= Integer.parseInt(pT[1].replace("s", ""));
            }
            end += 999;
            
            myLog.offer(new LogTime(start, end));
            // System.out.println(start + " " + end);
        }
        
        return;
    }
    
    
    public static int solveLog(PriorityQueue<LogTime> myLog) {
        PriorityQueue<LogTime> que = new PriorityQueue<>(
            (a, b) -> {
                if (a.e == b.e) {
                    return Integer.compare(a.s, b.s);
                }
                return Integer.compare(a.e, b.e);
            }
        );
        
        int result = 0;
        
        while (!myLog.isEmpty()) {
            System.out.println(myLog.peek().s + " " + myLog.peek().e);
            // 먼저 que에 있는 값들 중 현재 시작하려는 log의 시작값보다 마침 값들이 작은 log들을 que에서 뺀다.
            while (!que.isEmpty() && myLog.peek().s > que.peek().e) {
                que.poll();
            }
            // 현재 log를 que에 넣는다.
            que.offer(myLog.poll());
            // 현재 que의 사이즈를 기록한다.
            // System.out.println(que.size());
            result = Math.max(result, que.size());
        }
        
        return result;
    }
    
}