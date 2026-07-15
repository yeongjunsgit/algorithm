/*
매초 마다 검색할 필요없이 매 공격 순간을 토대로 현재 시간을 가져가면서 갱신하는게 빨라 보인다.

*/

class Solution {
    public int solution(int[] bandage, int health, int[][] attacks) {
        int answer = 0;
        // 현재 시간과 현재 체력
        int nowTime = 0, nowHp = health;
        // 몬스터들을 순회하여 만나기전에 붕대로 회복한 후 데미지 계산
        for (int[] arr : attacks) {
            int gap = arr[0] - nowTime - 1;
            nowTime = arr[0];
            nowHp = Math.min(health, nowHp + (gap * bandage[1]));
            nowHp = Math.min(health, nowHp + ((gap / bandage[0]) * bandage[2]));
            nowHp -= arr[1];
            
            // 플레이어 리타이어시 순회 종료
            if (nowHp <= 0) {
                answer = -1;
                break;
            }
        }
        
        if (answer != -1) answer = nowHp;
        
        return answer;
    }
}