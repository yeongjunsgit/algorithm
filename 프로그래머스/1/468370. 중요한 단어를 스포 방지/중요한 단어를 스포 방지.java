import java.util.ArrayList;
import java.util.HashMap;

class Solution {
    public int solution(String message, int[][] spoiler_ranges) {
        int answer = 0;
        int n = message.length();

        HashMap<String, Integer> totalCount = new HashMap<>();
        HashMap<String, Integer> spoilerCount = new HashMap<>();

        ArrayList<String> words = new ArrayList<>();
        ArrayList<Integer> wordStarts = new ArrayList<>();

        /*
         * StringTokenizer 대신 message를 직접 탐색하여
         * 단어와 실제 시작 인덱스를 저장합니다.
         */
        int index = 0;

        while (index < n) {
            if (message.charAt(index) == ' ') {
                index++;
                continue;
            }

            int start = index;

            while (index < n && message.charAt(index) != ' ') {
                index++;
            }

            String word = message.substring(start, index);

            words.add(word);
            wordStarts.add(start);

            totalCount.put(
                word,
                totalCount.getOrDefault(word, 0) + 1
            );
        }

        int wordCount = words.size();
        boolean[] visited = new boolean[wordCount];

        for (int[] range : spoiler_ranges) {
            int spoilerStart = range[0];
            int spoilerEnd = range[1];

            for (int j = 0; j < wordCount; j++) {
                if (visited[j]) {
                    continue;
                }

                int wordStart = wordStarts.get(j);
                int wordEnd = wordStart + words.get(j).length() - 1;

                /*
                 * 이후의 단어는 현재 스포일러 구간과 겹칠 수 없습니다.
                 */
                if (wordStart > spoilerEnd) {
                    break;
                }

                /*
                 * [wordStart, wordEnd]와
                 * [spoilerStart, spoilerEnd]가 겹치는 조건
                 */
                if (wordStart <= spoilerEnd &&
                    spoilerStart <= wordEnd) {

                    String word = words.get(j);

                    spoilerCount.put(
                        word,
                        spoilerCount.getOrDefault(word, 0) + 1
                    );

                    visited[j] = true;
                }
            }
        }

        /*
         * 중복된 단어를 여러 번 순회하지 않도록
         * spoilerCount에 들어 있는 단어 종류만 확인합니다.
         */
        for (String word : spoilerCount.keySet()) {
            int total = totalCount.getOrDefault(word, 0);
            int spoiler = spoilerCount.getOrDefault(word, 0);

            if (total == spoiler) {
                answer++;
            }
        }

        return answer;
    }
}