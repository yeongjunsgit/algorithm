// 맨 처음 문제를 보았을 때는 유니온 파인드를 떠올렸다. 주어진 구간의 부모를 첫번째 위치의 부모로 통일하고 나서 현재 번호와 부모가 같은 개수를 구하면 될것이라 생각했다.
// 그러나 만약 N = 1000000, M= 5000일때, 주어지는 M개의 값이 1, 1000000이라면 5000000000번 순회해야하기 때문에 불가능해보였다.
// 생각하던 중 스택을 생각해냈다. 시작 지점과 끝나는 지점을 따로 기록해두고, 2개의 스택을 선언해 두 개의 스택의 뒤가 일치하면, 두 개를 제거하고, 
// 두개의 스택이 비어있는 상황이라면 cnt를 1 늘리고자 하였다.
// 그러나 위의 방식은 치명적인 오류가 있었는데 바로 높은 값이 먼저나오면 문제가 발생하는 것이었다. 아래의 예제를 보자
// N = 100, M = 5 ({5, 100}, {4, 100}, {3, 100}, {2, 100}, {1, 100}) 순으로 예제가 주어지면 2개의 스택은 다음과 같이 된다.
// open_stack = {5, 4, 3, 2, 1}, close_stack = {1, 2, 3, 4, 5} 위와 같이 되면 분명 100의 위치에서 모든 스택이 비어야함에도 불구하고 맨 뒤만 보고 계산하니
// 문제가 발생한다.
// 이 이슈를 해결하기 위해 문제의 특징을 더 이용하기로 했다. 괄호가 열리면 반드시 뒤에는 닫힌 괄호가 오게 된다. 따라서 close_stack은 필요없고,
// open_stack만 기준으로 보며, 닫힌 괄호가 들어오면 open_stack에서 짝이 존재하면 해당 짝을 지우는 방식으로 스택을 비우기로 하였다.
// unordered_set를 이용하여 open_stack을 만들고 찾는 시간을 줄여 구현하였다!
// 알고리즘은 잘 떠올렸는데... 사용하는 방법이 미흡했다 ㅠㅠ 언제쯤 한번에 맞추는 일이 많아질지 걱정이다.


#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int N, M;
vector<vector<int> > open_loca(1000001), close_loca(1000001);


int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;
    
    int s, e, cnt = 0;
    for (int i=1; i<=M; ++i) {
        cin >> s >> e;
        open_loca[s].push_back(i);
        close_loca[e].push_back(i);
    }
    
    unordered_set<int> open_stack;
    
    for (int i=1; i<=N; ++i) {
        if (open_loca[i].size() > 0) {
            for (int a : open_loca[i]) {
                open_stack.insert(a);
            }
        }
        if (close_loca[i].size() > 0) {
            for (int a : close_loca[i]) {
                open_stack.erase(a);
            }
        }

        if (open_stack.empty()) cnt++;
    }
    
    cout << cnt;

    return 0;
}
