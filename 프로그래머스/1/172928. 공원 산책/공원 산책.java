import java.util.HashMap;

class Solution {
    HashMap<String, int[]> directions = new HashMap<>();
    
    int[] play_command(int[] now_loca, int[] now_dir, String[] park, String[] commands, int N, int M)
    {
        int nx = now_loca[0], ny = now_loca[1], repeatTime = Integer.parseInt(commands[1]);
        for (int i=0; i<repeatTime; ++i) {
            nx += now_dir[0];
            ny += now_dir[1];
            // 먼저 이동을 마친 곳이 격자안에 들어오는지 확인
            if (0 <= nx && nx < N && 0 <= ny && ny < M) {
                // 격자 안에 들어온다면 진행하는 도중에 장애물이 있는지 확인
                if (park[nx].charAt(ny) == 'X') {
                    return now_loca;
                }
            }
            else return now_loca;
        }
        
        return new int[]{nx, ny};
        
    }
    
    
    public int[] solution(String[] park, String[] routes) {
        int[] answer = {};
        int N = park.length, M = park[0].length();
        int[] now_loca = new int[2];
        directions.put("N", new int[]{-1, 0});
        directions.put("S", new int[]{1, 0});
        directions.put("W", new int[]{0, -1});
        directions.put("E", new int[]{0, 1});
        
        // 시작 지점 저장
        for (int i=0; i<N; ++i) {
            for (int j=0; j<M; ++j) {
                if (park[i].charAt(j) == 'S') {
                    now_loca[0] = i;
                    now_loca[1] = j;
                }
            }
        }
        
        // 현재 위치에서 모든 이동 커맨드를 반영
        for (String command : routes) {
            String[] commands = command.split(" ");
            int[] now_dir = directions.get(commands[0]);
            int nx = now_loca[0], ny = now_loca[1], repeatTime = Integer.parseInt(commands[1]);
            now_loca = play_command(now_loca, now_dir, park, commands, N, M);
            
        }
        
        answer = now_loca;
        
        return answer;
    }
}