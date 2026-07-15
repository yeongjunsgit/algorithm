class Solution {
    int[][] directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    
    public int solution(String[][] board, int h, int w) {
        int answer = 0;
        int N = board.length;
        for (int i=0; i<4; ++i) {
            int nx = h + directions[i][0], ny = w + directions[i][1];
            if (0 <= nx && nx < N && 0 <= ny && ny < N && board[h][w].equals(board[nx][ny])) {
                answer++;
            }
        }
        
        return answer;
    }
}