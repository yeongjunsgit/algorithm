class Solution {
    public int[] solution(String[] wallpaper) {
        int[] answer = new int[4];
        int N = wallpaper.length, M = wallpaper[0].length(), minX = N, minY = M, maxX = 0, maxY = 0;
        
        for (int i=0; i<N; ++i) {
            for (int j=0; j<M; ++j) {
                if (wallpaper[i].charAt(j) == '#') {
                    minX = Math.min(minX, i);
                    minY = Math.min(minY, j);
                    maxX = Math.max(maxX, i + 1);
                    maxY = Math.max(maxY, j + 1);
                }
            }
        }
        
        answer[0] = minX; answer[1] = minY; answer[2] = maxX; answer[3] = maxY;
        
        
        return answer;
    }
}