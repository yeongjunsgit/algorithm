import java.util.HashMap;
import java.util.ArrayList;

class Solution {
    
    public boolean compare(int[] intToday, int[] intDate) {
        // 연도 비교
        if (intToday[0] < intDate[0]) {
            return false;
        }
        else {
            // 월 비교
            if (intToday[0] == intDate[0]) {
                if (intToday[1] < intDate[1]) {
                    return false;
                }
                else {
                    // 일 비교
                    if (intToday[1] == intDate[1]) {
                        // System.out.println("현재 분은 각각 " + intToday[2] + "와 " + intToday[2] + "입니다.");
                        if (intToday[2] < intDate[2]) {
                            return false;
                        }
                        else return true;
                    }
                    else {
                        return true;
                    }
                }
            }
            else {
                return true;
            }
        }
    }
    
    
    public int[] solution(String today, String[] terms, String[] privacies) {
        int[] answer = {};
        ArrayList<Integer> result = new ArrayList<>();
        int N = privacies.length;
        // 오늘 날짜를 숫자로 치환
        String[] todayDate = today.split("\\.");
        int[] intToday = new int[3];
        

        for (int i=0; i<3; ++i) {
            intToday[i] = Integer.parseInt(todayDate[i]);
        }
        
        HashMap<String, Integer> licenseTerm = new HashMap<>();
        // 주어진 약관들의 기간들을 licenseTerm에 기록
        for (String term : terms) {
            String[] CategoryTerm = term.split(" ");
            licenseTerm.put(CategoryTerm[0], Integer.parseInt(CategoryTerm[1]));
        }
        
        // 모든 계약건을 순회하면서 각 계약이 파기해야하는지 아닌지를 판별
        for (int i=0; i<N; ++i) {
            // 현재 계약건을 날짜와 종류로 나눔
            String[] nowPrivacie = privacies[i].split(" ");
            // 현재 계약건의 날짜를 int로 변환
            String[] nowDate = nowPrivacie[0].split("\\.");
            int[] intDate = new int[3];
            for (int j=0; j<3; ++j) {
                intDate[j] = Integer.parseInt(nowDate[j]);
            }
            intDate[1] += licenseTerm.get(nowPrivacie[1]);
            if (intDate[1] > 12) {
                intDate[0] += intDate[1] / 12;
                intDate[1] %= 12;
                if (intDate[1] == 0) {
                    intDate[1] = 12;
                    intDate[0]--;
                }
            }
            if (compare(intToday, intDate)) {
                result.add(i + 1);
            }

        }
        int M = result.size();
        answer = new int[M];
        for (int i=0; i<M; ++i) {
            answer[i] = result.get(i);
        }
        
        return answer;
    }
}