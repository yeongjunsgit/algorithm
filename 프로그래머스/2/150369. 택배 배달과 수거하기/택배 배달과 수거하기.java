/*
물류창고에서 택배를 꺼내, 각 집마다 배송하고 택배상자도 수거해와야 한다.
한번에 차에 담을 수 있는 상자의 개수는 cap개 이며, 빈상자 또한 개수로 치는것으로 보인다.
거리는 인덱스의 값만큼이다.
최단거리로 왔다갔다 해야 한다면, 어떻게 해야 최적으로 수거가 가능할까?
최~~~ 대한 가장 먼곳은 적게 가야한다. 1의 위치의 집은 왕복이 2지만, 5의 위치의 집은 왕복이 10이다.
가능한 한, 뒤에 있는 집을 최대한 들려야한다.
후보 1. 그리디
- 그리디 하게 한다. 택배 상자를 현재 가장 뒤쪽에 있는 집으로 향할때 가장 많이 가져올 수 있는만큼 가져가자.
  - why? => 가는길에 무조건 다 줄 수 있는 만큼만 가져가면 문제가 없다!
  검토 시작
  1. 택배 4개를 싣는다.
  5까지 가는길에 집5에 2개, 집 4에 1개 집 3에 1개 주고간다.
  !!! 주의 사항!!! 집 5부터 주게되면 집 4에서 모든 빈 상자를 가져갈 수 없다. 그러니 반드시 가는길에 주어야한다.
  2. 5번에 택배를 모두 주었다면, 돌아가는 길에 현재위치에서 돌아가는길까지 최대한 많은 것들을 가져간다! = 그렇게 하면 가장 먼 거리로 다시 올일이 적어진다!
  3. 1~2를 계속해서 반복
  - 이론상 가능해보임 반례 생각해보기
    - 반례 1) 
  
  일단 구현 방법을 생각해보자.
  1. 누적합을 계산한다. 계산할 값들은 현재 위치에서 이전까지 필요한 수거 박스와 택배 박스를 각각 기록
  2. 택배를 진행하면서, 납품한 값또한 누적합으로 수거 박스와 택배 박스 각각 기록
  3. 현재 택배차의 택배 수 - 현재 위치를 제외한 이후의 택배 수 > 0 이라면 그 값만큼 현재 위치에 택배를 두고 간다.
  4. 최대한 끝까지 간 후에 돌아오는길에 존재하는 수거 박스를 가장 뒤에서부터 싹 쓸어담는다.
  현재 타겟을 정해두고 계속해서 간다..?
  이거 갱신하는게 쉽지않네 흠 아닌가 어차피 현재위치에서 순회니까 결국 10만 정도 ok
*/

class Solution {
    
    // 현재 가야하는 가장 먼 idx를 찾아주는 메서드
    int set_idx(int idx, int[] deliveries, int[] pickups)
    {
        while (true) {
            if (deliveries[idx] > 0 || pickups[idx] > 0 || idx == 0) return idx;
            idx--;
        }
    }
    
    
    public long solution(int cap, int n, int[] deliveries, int[] pickups) {
        long answer = 0;
        long deli_goals = 0, rec_goals = 0;
        for (int i=0; i<n; ++i) {
            deli_goals += deliveries[i];
            rec_goals += pickups[i];
        }
        int go_idx = set_idx(n-1, deliveries, pickups);
        // System.out.println("지금 택배 개수는 " + deli_goals + " 이고, 수거 박스 개수는 " + rec_goals + "이다.");
        // 택배 발송 및 수거 시작 매 반복마다 cap 만큼 채우거나, 현재 배달 할 만큼만 채워서 출발
        while (deli_goals != 0 || rec_goals != 0) {
            // System.out.println("지금 맨뒤 인덱스는 " + go_idx + " 이다.");
            int dBox = (int) Math.min(cap, deli_goals), rBox = 0;
            int deli_idx = go_idx, rec_idx = go_idx;
            // 가장 뒤부터 택배를 가능한 한 배송
            while (dBox > 0) {
                if (deliveries[deli_idx] == 0) {
                    if (deli_idx > 0) deli_idx--;
                    else break;
                }
                
                else {
                    int usedBox = Math.min(dBox, deliveries[deli_idx]);
                    deliveries[deli_idx] -= usedBox;
                    dBox -= usedBox;
                    deli_goals -= usedBox;
                }
            }
            // 가장 뒤에서 부터 박스를 가능한 한 수거
            while (rBox != cap) {
                if (pickups[rec_idx] == 0) {
                    if (rec_idx > 0) rec_idx--;
                    else break;
                }
                
                else {
                    int getBox = Math.min(pickups[rec_idx], cap - rBox);
                    pickups[rec_idx] -= getBox;
                    rBox += getBox;;
                    rec_goals -= getBox;
                }
            }
            // 가장 멀리 방문했던 위치 * 2 만큼 횟수 추가
            answer += (go_idx + 1) * 2;
            // 시작점 다시 설정
            go_idx = set_idx(go_idx, deliveries, pickups);
            
        }
        
        return answer;
    }
}