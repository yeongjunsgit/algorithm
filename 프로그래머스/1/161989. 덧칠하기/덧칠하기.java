/*
처음에는 가장 많이 겹치는 부분을 먼저 칠할까 생각했다
그러나, m = 4일때, 1 3 4 5 6 7 8의 경우나 1 2 3 4 5 6 8의 경우를 생각해보자. 가장 많이 겹치는 것은 
1 3 4 5 6 7 8의 경우 3 4 5 6 / 4 5 6 7 / 5 6 7 8 이다. 그러나, 5678을 선택하지 않으면 최소 횟수인 2회를 만족할 수 없다.
1 2 3 4 5 6 8의 경우 1 2 3 4 / 2 3 4 5 / 3 4 5 6 이다. 그러나, 1234를 선택하지 않으면 최소 횟수인 2회를 만족할 수 없다.
구간에서 가운데를 칠해버리면, 구간이 2개가 나뉘어져, 칠해야하는 횟수가 늘어난다. 즉, 시작점부터 그냥 쭉 칠하고 가는게 맞지않을까?
어차피 어떤 부분이던 색칠은 해야만 한다. 그렇다면, 그냥 순서대로 칠하면 되지 않을까..?
위 경우의 반례를 생각해보자
당장 딱히 생각나는게없다 무조건 모두 칠해져야하기 때문에 어차피 손해라도 칠해야한다.
*/

class Solution {
    public int solution(int n, int m, int[] section) {
        int answer = 0;
        int nowIdx = 0, N = section.length;
        while (nowIdx < N) {
            answer++;
            int nowRange = section[nowIdx] + m - 1;
            while (nowIdx < N && section[nowIdx] <= nowRange) {
                nowIdx++;
            }
        }

        return answer;
    }
}