#include <iostream>
#include <vector>
#include <cstring>
#include <string>

using namespace std;

struct node {
    bool finish;
    node* next[26];
};


// 현재 단어와, 현 위치의 노드, 중복 개수를 세는 cnt를 인자로 받는다.
void insert_cnt(const char* key, node* next[], int& cnt, bool& isMulti) {
    
    // 현재 인덱스 값을 선택한 단어의 주소 값의 'a'의 아스키 코드값을 뺀 값으로 한다.
    int index = *key - 'a';
    
    // 만약 현재 노드에서 위에서 구한 index값에 node가 만들어져 있지 않다면 노드를 추가한다.
    if (!next[index]) {
        next[index] = new node();
    }
    // // 이미 index에 해당하는 노드가 존재한다면 현재 노드가 finish인지 확인하고 finish 라면
    // // cnt를 올리고 탈출
    // else if (next[index] -> finish) {
    //     cnt++;
    //     return;
    // }
    
    // 만약 다음 단어 값이 '\0' 이라면 현 위치가 마지막이라는 뜻 임으로 현재 노드에 finish 값을 true로
    // 체크하고 탈출
    // string을 char* 형식의 배열로 선언하면 모든 문자열의 마지막은 널 종료 문자 '\0' 으로 끝나기 때문에
    // 다음이 '\0'인지 확인하여 단어의 끝을 확인
    
    if (*(key + 1) == '\0') {
        if (next[index] -> finish) {
            cnt++;
            isMulti = true;
            return;
        }
        else {
            next[index] -> finish = true;
            return;
        }
    }
    
    // key값에 +1을 함으로써 다음 단어를 인자로 넣음
    // next[index]는 현재 문자를 나타내는 노드를 가리키는 포인터로, 현재 노드에서 ->next를 통해 
    // 해당 노드의 다음 문자에 대한 포인터 배열에 접근한다.
    // 그렇게 다음 노드로 재귀
    insert_cnt(key+1, next[index]->next, cnt, isMulti);
}

bool checkChildren(node* next[]) {
    for (int i = 0; i < 26; ++i) {
        if (next[i]) {
            return true; // 하나 이상의 자식 노드가 있는 경우 true 반환
        }
    }
    return false; // 자식 노드가 없는 경우 false 반환
}

void search(const char* key, node* next[], int& cnt) {
    // 현재 인덱스 값을 선택한 단어의 주소 값의 'a'의 아스키 코드값을 뺀 값으로 한다.
    int index = *key - 'a';
    
    if (*(key + 1) == '\0') {
        if (checkChildren(next[index]->next)) {
            cnt++;
        }
        return;
    }
    
    search(key+1, next[index]->next, cnt);
}

int main()
{
    int N;
    cin >> N;
    
    int cnt = 0;
    // root 노드를  선언
    node* root = new node();
    
    vector<string> strings;
    
    for (int i=0; i<N; ++i) {
        string data;
        cin >> data;
        // 받은 데이터를 포인터 변수로 선언
        const char* target = data.c_str();
        bool isMulti = false;
        insert_cnt(target, root->next, cnt, isMulti);
        
        if (isMulti == false) {
            strings.push_back(data);
        }
    }
    
    for (int i=0; i<strings.size(); ++i) {
        const char* check = strings[i].c_str();
        
        search(check, root->next, cnt);
    }
    
    cout << N - cnt;

    return 0;
}
