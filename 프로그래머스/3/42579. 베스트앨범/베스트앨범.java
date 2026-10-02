/*
map과 set를 이용한다.
먼저 출력을 위해 필요한 정보들은 다음과 같다.
1. 장르의 종류
2. 장르 별 총합 재생 수
3. 장르 내 곡별 재생 수 (높은 순으로)

이를 구현하려면 어떻게 해야할지 생각해보자
1. set로 단순히 구현할 수 있다.
2. map을 이용해서 합산 해주면 구할 수 있다.
3. map을 이용해서 구할 수 있을 것 같다 map에 우선순위 큐를 넣어주는건 어떨까?

위의 정보들만 정리하면 출력하는 것은 어렵지 않다.
1. 각 장르의 총합을 가지고 우선순위를 두고
2. 우선순위 별로 최상위 곡 2개만 건져오면 된다

*/

import java.util.*;

class PlayTime {
    int p, id;
    
    PlayTime(int p, int id) {
        this.p = p;
        this.id = id;
    }
}

class TotalInfo {
    int t;
    String id;
    
    TotalInfo(int t, String id) {
        this.t = t;
        this.id = id;
    }
}


class Solution {
    public int[] solution(String[] genres, int[] plays) {
        HashSet<String> nowGenres = new HashSet<>();
        HashMap<String, Integer> genresTotal = new HashMap<>();
        HashMap<String, PriorityQueue<PlayTime> > genresEach = new HashMap<>();
        
        setSet(genres, plays, nowGenres, genresTotal, genresEach);
        
        int[] answer = getAnswer(nowGenres, genresTotal, genresEach);
        return answer;
    }
    
    public static void setSet(String[] genres, int[] plays, HashSet<String> nowGenres, HashMap<String, Integer> genresTotal, 
                              HashMap<String, PriorityQueue<PlayTime> > genresEach) {
        int N = genres.length;
        for (int i=0; i<N; ++i) {
            nowGenres.add(genres[i]);
            genresTotal.put(genres[i], genresTotal.getOrDefault(genres[i], 0) + plays[i]);
            genresEach.computeIfAbsent(genres[i], k -> new PriorityQueue<>((a, b) -> {
                                                                               if (a.p == b.p) {
                                                                                   return Integer.compare(a.id, b.id);
                                                                               }
                                                                               return Integer.compare(b.p, a.p);
                                                                            }
                                                                          )
                                      ).offer(new PlayTime(plays[i], i));
            
        }
    }
    
    public static int[] getAnswer(HashSet<String> nowGenres, HashMap<String, Integer> genresTotal, HashMap<String, PriorityQueue<PlayTime> > genresEach) {
        List<Integer> result = new ArrayList<>();
        PriorityQueue<TotalInfo> bestGenres = new PriorityQueue<>(
            (a, b) -> {
                return Integer.compare(b.t, a.t);
            }
        );
        
        for (String s : nowGenres) {
            bestGenres.offer(new TotalInfo(genresTotal.get(s), s) );
        }
        while (!bestGenres.isEmpty()) {
            TotalInfo now = bestGenres.poll();
            int cnt = 0;
            PriorityQueue<PlayTime> nowMusics = genresEach.get(now.id);
            while (!nowMusics.isEmpty() && cnt < 2) {
                result.add(nowMusics.poll().id);
                cnt++;
            }
        }
        
        return result.stream().mapToInt(Integer::intValue).toArray();
        
    }
    
}

