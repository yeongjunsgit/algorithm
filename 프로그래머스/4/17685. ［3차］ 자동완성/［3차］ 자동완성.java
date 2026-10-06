/*
Trie를 사용해서 문제를 푼다.
0. Node를 만든다. 만들것은 아래와 같다.
  1) children 배열
  2) 단어의 끝을 알리는 isOver
  3) 현재 위치에 해당 알파벳의 개수를 나타내는 cnt
1. 먼저 Trie에 모든 단어를 넣는다. (그래야 다른 단어와의 연관관계를 알 수 있다.)
2. 다시 모든 단어를 대상으로 검증을 시도한다. 끝까지 가면서 최종위치에 도달할때까지 cnt를 본다. 만약 1이 나타나는 순간 해당 글자가 자동완성을 할때까지 필요한 글자이다.

*/
import java.util.*;

class Trie {
    class Node {
        Node[] children = new Node[26];
        boolean isOver = false;
        int cnt = 0;
    }
    
    private final Node root;
    
    // 생성자 사용 시 root에 Node 할당
    Trie() {
        root = new Node();
    }
    
    // 인자로 넣은 문자열을 넣는 메서드 insert
    public void insert(String s) {
        Node curr = root;
        int N = s.length();
        for (int i=0; i<N; ++i) {
            int nowIdx = s.charAt(i) - 'a';
            if (curr.children[nowIdx] == null) {
                curr.children[nowIdx] = new Node();
            }
            curr.children[nowIdx].cnt += 1;
            curr = curr.children[nowIdx];
        }
        
        curr.isOver = true;
    }
    
    public int search(String s) {
        Node curr = root;
        int N = s.length(), nowCnt = 0;
        for (int i=0; i<N; ++i) {
            int nowIdx = s.charAt(i) - 'a';
            if (curr.cnt == 1) {
                return nowCnt;
            }
            curr = curr.children[nowIdx];
            nowCnt++;
        }
        
        return nowCnt;
        
    }
    
}


class Solution {
    public int solution(String[] words) {
        int answer = 0;
        Trie trie = new Trie();
        
        for (String s : words) {
            trie.insert(s);
        }
        for (String s : words) {
            answer += trie.search(s);
        }
        
        return answer;
    }
}