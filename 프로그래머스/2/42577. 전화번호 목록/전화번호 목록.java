import java.util.*;

class Trie {
    
    static class Node {
        Node[] children = new Node[10];
        boolean isover = false;
    }
    
    private final Node root;
    // Trie 생성자
    public Trie() {
        root = new Node();
    }
    
    // Trie에 값을 넣는 연산
    public boolean insert(String pN) {
        Node curr = root;
        
        for (char n : pN.toCharArray()) {
            int now = n - '0';
            if (curr.children[now] == null) {
                curr.children[now] = new Node();
            }
            curr = curr.children[now];
        }
        
        curr.isover = true;
        for (int i=0; i<10; ++i) {
            if (curr.children[i] != null) {
                return false;
            }
        }
        
        return true;

    }
    
}


class Solution {
    public boolean solution(String[] phone_book) {
        boolean answer = true;
        Arrays.sort(phone_book, Collections.reverseOrder());
        
        Trie trie = new Trie();
        
        for (String s : phone_book) {
            boolean tmp = trie.insert(s);
            if (tmp == false) {
                answer = false;
                break;
            }
        }
        
        
        return answer;
    }
}