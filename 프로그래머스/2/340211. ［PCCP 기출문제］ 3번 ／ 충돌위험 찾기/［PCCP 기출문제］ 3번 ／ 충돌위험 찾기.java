class Solution {
    class MyLoca {
        int x;
        int y;
        int idx;
        
        MyLoca(int x, int y, int idx) {
            this.x = x;
            this.y = y;
            this.idx = idx;
        }
    }
    
    
    public void moveRobot(int[][] points, int[][] routes, int[][] visited, MyLoca[] nowLoca, int now)
    {
        int targetNum = routes[now][nowLoca[now].idx];
        int xDest = points[targetNum - 1][0], yDest = points[targetNum - 1][1];
        // 1칸 이동 (단,세로 방향을 우선적으로 이동한다.)
        if (nowLoca[now].x != xDest) {
            visited[nowLoca[now].x][nowLoca[now].y]--;
            if (nowLoca[now].x > xDest) {
                nowLoca[now].x--;
            }
            else {
                nowLoca[now].x++;
            }
            visited[nowLoca[now].x][nowLoca[now].y]++;
            
        }
        
        else if (nowLoca[now].y != yDest) {
            visited[nowLoca[now].x][nowLoca[now].y]--;
            if (nowLoca[now].y > yDest) {
                nowLoca[now].y--;
            }
            else {
                nowLoca[now].y++;
            }
            visited[nowLoca[now].x][nowLoca[now].y]++;
        }
        
        // 이동한 위치가 다음 포인트라면, 타겟 인덱스를 바꿔준다.
        if (nowLoca[now].x == xDest && nowLoca[now].y == yDest) {
            nowLoca[now].idx++;
        }
        
        return;
    }
    
    
    public int solution(int[][] points, int[][] routes) {
        int answer = 0, N = routes.length, completed = 0;
        int[][] visited = new int[101][101];
        int[] doneRobot = new int[N];
        MyLoca[] nowLoca = new MyLoca[N];
        for (int i=0; i<N; ++i) {
            int tmpTarget = routes[i][0] - 1;
            nowLoca[i] = new MyLoca(points[tmpTarget][0], points[tmpTarget][1], 1);
            visited[points[tmpTarget][0]][points[tmpTarget][1]]++;
        }
        
        // 모든 로봇이 목표지점에 도달할 때까지 반복
        while (completed < N) {
            // 먼저 현재 로봇들이 충돌되어있는 상황이 있는지 확인
            for (int i=1; i<=100; ++i) {
                for (int j=1; j<=100; ++j) {
                    if (visited[i][j] >= 2) {
                        // System.out.println(i +", " + j + " = " + visited[i][j]);
                        answer++;
                    }
                }
            }
            // 로봇들을 순서대로 이동해서, visited를 갱신하고, idx 값을 조절하여 다음 목표를 바라보게 함
            for (int i=0; i<N; ++i) {
                if (nowLoca[i].idx >= routes[i].length) {
                    if (doneRobot[i] == 0) {
                        completed++;
                        visited[nowLoca[i].x][nowLoca[i].y]--;
                        doneRobot[i] = 1;
                    }
                }
                else {
                    moveRobot(points, routes, visited, nowLoca, i);
                    // System.out.println("현재 " + i + "번째 값이 이동 중으로 이동한 위치는 " +  nowLoca[i].x + ", " + nowLoca[i].y + "이다.");
                }
            }
        }
        
        return answer;
    }
}