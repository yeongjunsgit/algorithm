/*
파이프를 k번 연다. k는 최대 10번 파이프의 type도 3개뿐이다.
흠... 여는 순서에 따라서 얻는 결과가 다르다. 선택할 수 있는 경우의 수를 생각해보자. 각각의 선택에서 3개의 경우의 수가 있다.
이를 총 10번 선택 3^10 = 생각보다 얼마 안함
이러면, 브루트포스로 각각의 경우를 전부 생각해보고, 이를 재귀를 통해서 진행하면 될 듯하다.
*/

import java.util.ArrayList;
import java.util.Queue;


class Solution {
    int result = 0;
    
    public void goDeep(int now, int i, ArrayList<ArrayList<int[]> > graph, ArrayList<Integer> passed, int[] visited, ArrayList<Integer> goTo) {
        for (int[] dir : graph.get(now)) {
            // 현재 위치의 인접한 노드에 파이프의 종류가 선택된 것과 같다면
            if (dir[1] == i && visited[dir[0]] == 0) {
                visited[dir[0]] = 1;
                passed.add(dir[0]);
                goTo.add(dir[0]);
                goDeep(dir[0], i, graph, passed, visited, goTo);
            }
        }
        return;
    }

    
    // 재귀 함수 작성
    public void openPipe(ArrayList<ArrayList<int[]> > graph, ArrayList<Integer> passed, int[] visited, int k, int depth)
    {
        // k번 파이프를 열었으면, 그 결과값 중 최대 값을 저장
        if (depth == k) {
            int tmp = 0;
            for (int a : visited) {
                tmp += a;
            }
            // System.out.println();
            // System.out.println(tmp);
            result = Math.max(result, tmp);
            return;
        }
        
        // 파이프 3종을 순회해서 열고 그 값을 반영하여 재귀
        int M = passed.size();
        for (int i=1; i<=3; ++i) {
            // System.out.print(i + " ");
            // 해당 파이프를 열었을때 전염되는 것을 반영
            ArrayList<Integer> goTo = new ArrayList<>();
            for (int j=0; j<M; ++j) {
                goDeep(passed.get(j), i, graph, passed, visited, goTo);
            }
            // 재귀
            openPipe(graph, passed, visited, k, depth + 1);
            // 원복
            for (int g : goTo) {
                visited[g] = 0;
                passed.remove(passed.size() - 1);
            }
        }
        
        return;
        
    }
    
    
    public int solution(int n, int infection, int[][] edges, int k) {
        int answer = 0;
        int[] visited = new int[n+1];
        visited[infection] = 1;
        ArrayList<ArrayList<int[]> > graph = new ArrayList<>();
        for (int i=0; i<=n; ++i) {
            graph.add(new ArrayList<>());
        }
        for (int[] loca : edges) {
            graph.get(loca[0]).add(new int[]{loca[1], loca[2]});
            graph.get(loca[1]).add(new int[]{loca[0], loca[2]});
        }
        ArrayList<Integer> passed = new ArrayList<>();
        passed.add(infection);
        
        openPipe(graph, passed, visited, k, 0);
        
        answer = result;
        
        return answer;
    }
}