import java.util.*;
import java.io.*;

class Solution {
    public String solution(int[] numbers) {
        String answer = "";
        ArrayList<String> list = new ArrayList<>();
        
        for (int i : numbers) {
            list.add(String.valueOf(i));
        }
        
        list.sort((a, b) -> (b + a).compareTo(a + b));
        StringBuilder sb = new StringBuilder();
        
        for (String c : list) {
            sb.append(c);
        }
        
        answer = sb.toString();
        if (answer.charAt(0) == '0') return "0";
        
        return answer;
    }
}