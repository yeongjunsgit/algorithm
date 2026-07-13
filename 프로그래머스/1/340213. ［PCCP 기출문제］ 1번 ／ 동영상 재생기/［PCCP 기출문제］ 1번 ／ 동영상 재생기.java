/*
pos = 시작 시간

*/




class Solution {
    static int checkOp(int nowT, int opS, int opE)
    {
        if (nowT >= opS && nowT <= opE) return opE;
        return nowT;
    }
    
    
    public String solution(String video_len, String pos, String op_start, String op_end, String[] commands) {
        String answer = "";
        // 현재 시간을 int형으로 변환하여 저장
        int[] nowTime = new int[2];
        String[] hM = pos.split(":");
        nowTime[0] = Integer.parseInt(hM[0]);
        nowTime[1] = Integer.parseInt(hM[1]);
        // 오프닝 시간을 int형으로 변환하여 저장
        int[] opStartTime = new int[2];
        int[] opEndTime = new int[2];
        String[] sT = op_start.split(":");
        String[] eT = op_end.split(":");
        opStartTime[0] = Integer.parseInt(sT[0]);
        opStartTime[1] = Integer.parseInt(sT[1]);
        opEndTime[0] = Integer.parseInt(eT[0]);
        opEndTime[1] = Integer.parseInt(eT[1]);
        // 비디오 끝 시간을 int형으로 변환하여 저장
        int[] endTime = new int[2];
        String[] vET = video_len.split(":");
        endTime[0] = Integer.parseInt(vET[0]);
        endTime[1] = Integer.parseInt(vET[1]);
        
        int nowT = nowTime[0] * 60 + nowTime[1], opS = opStartTime[0] * 60 + opStartTime[1], opE = opEndTime[0] * 60 + opEndTime[1], vL = endTime[0] * 60 + endTime[1];
        
        // 현재 시간이 오프닝 시간 안이라면, 스킵하고 반영
        nowT = checkOp(nowT, opS, opE);
        
        // commands를 순회하면서, 해당 커멘드에 적혀있는 방식을 적용
        for (String s : commands) {
            // 1. prev 명령일 경우 시간을 10초 뒤로 이동 (단, 0보다 낮아질순 없다.)
            if (s.equals("prev")) {
                nowT = Math.max(0, nowT - 10);
            }
            // 2. next 명령일 경우 시간을 10초 앞으로 이동 (단, 비디오의 최대 길이보다 높아질 순 없다.)
            else if (s.equals("next")) {
                nowT = Math.min(vL, nowT + 10);
            }
            // 현재 시간이 어떤 경우에던, 오프닝 시간안에 포함되어 있다면, 즉시 오프닝 건너뛰기가 적용되어야 한다.
            nowT = checkOp(nowT, opS, opE);
        }
        
        // 모든 커멘드가 반영된 int[]를 Stirng으로 "xx:xx" 형식으로 변환
        int hour = nowT / 60, minute = nowT % 60;
        String sHour = String.valueOf(hour);
        if (sHour.length() < 2) sHour = "0" + sHour;
        String sMinute = String.valueOf(minute);
        if (sMinute.length() < 2) sMinute = "0" + sMinute;
        
        answer = sHour + ":" + sMinute;
        
        
        return answer;
    }
}