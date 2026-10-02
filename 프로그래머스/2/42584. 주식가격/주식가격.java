/*
순서대로 값들을 deque에 넣는다.
값들을 넣을때는 아래의 정보를 모두 가진 class 로 만들어 넣는다.
1. 해당 주식의 가격
2. 해당 주식의 idx

그리고 계속해서 stack 형식으로 후입을 진행한다. 그러다가 가장 뒤에 있는 값보다 낮은 값이 들어오게 된다면, 동일한 값이 나오거나 stack이 빌때까지 전부 뺀다.
그리고 빼진 값들은 "현재 보고 있는 idx 값 - 해당 주식의 idx"를 해당 주식의 idx에 기록한다.

이와 같이 진행하면 편할 듯 하다!

*/
import java.util.*;

class Stock {
    int p, idx;
    
    Stock(int p, int idx) {
        this.p = p;
        this.idx = idx;
    }
}


class Solution {
    public int[] solution(int[] prices) {
        int N = prices.length;
        int[] answer = new int[N];
        ArrayDeque<Stock> que = new ArrayDeque<>();
        for (int i=0; i<N; ++i) {
            while (!que.isEmpty() && que.peekLast().p > prices[i]) {
                Stock tmp = que.pollLast();
                answer[tmp.idx] = i - tmp.idx;
            }
            que.offer(new Stock(prices[i], i));
        }
        
        while (!que.isEmpty()) {
            Stock now = que.pollLast();
            answer[now.idx] = N - 1 - now.idx; 
        }
        
        return answer;
    }
}