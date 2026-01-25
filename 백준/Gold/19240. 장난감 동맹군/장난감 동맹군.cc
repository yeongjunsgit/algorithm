// 처음 문제를 봤을땐 유니온 파인드인가 했지만.. 음.. 연결관계를 나타내는건 아닌거같아서 트리나 그래프 순회 같은 류는 배제하기로 했다.
// 계속 생각해봤는데 그리디?같은 느낌이었다. 예시로 {1, 2}가 들어오면 둘을 다른 그룹에 넣어야한다. 이는 분명하다! 같은데 있기 싫으니까
// 이후에 {1, 3}이 들어왔다 치자 그러면 1은 이전에 있었으므로 반드시 3이 1이 아닌 반대 그룹에 가야한다.
// 이후에 {2, 3}이 들어온다면 {1}, {2, 3}인 그룹에서 2와 3은 이미 1과 싫기 떄문에 이 순간 그룹이 1개가 더 필요해지면서 실패한다.
// 즉, 초기에 들어오면서 정한 그룹의 위치를 절대로 바꾸면 안된다 이 점을 이용해서 들어올때마다 처음 들어온 숫자는 그룹을 배치하고,
// 이후 둘 다 들어온 적이 있는 숫자들이라면 서로의 그룹이 다른지 확인하고 같다면 실패하게 만들어보았다!
// 반례를 찾았다 {1, 2}, {3, 4}가 들어오면 임의로 {1, 3}, {2, 4}같이 그룹이 생성된다 그 후에 {1, 3}이들어오면 사실 1과 3은 반대방향으로 가도 문제가 없으나
// 임의로 설정한 값떄문에 틀렸다는 결과를 만들 것이다..
// dfs를 이용해서 현재 위치에 그룹 하기 싫은 사람을 체크하고 이후에 그룹하기 싫은 사람을 제외한 모든 노드를 돌아다니면서 반복한다.
// 이제 체크된 그룹 하기 싫은 사람들을 한번 더 순회하여 현재 위치에서 그룹하기 싫은 사람이 체크되어있는지 확인한다.
// 체크되어 있다면 실패
// 이 방법 조차도 틀려서 블로그 글을 참조했다. 주어진 값들을 간선으로 보고 순회하면서 0,1 을 번갈아가면서 체크하고 만약 이미 체크 된 경우에는
// 반대 값이 아니면 실패한 것으로 본다.
// 이전 코드를 바꿀땐 꼼꼼하게 보자... dfs에 계속 시작점을 1로줘서 틀리고 있었다...
// 그리고 제출하기전에 디버깅용 출력 코드 좀 잘 지우자.

#include <iostream>
#include <vector>

using namespace std;

int T, N, M;


void dfs(int now, vector<int>& visited, vector<vector<int> >& graph)
{
    for (int a : graph[now]) {
        if (visited[a] == -1) {
            visited[a] = (visited[now] + 1) % 2;
            dfs(a, visited, graph);
        }
    }
    
    return;
}


int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> T;
    for (int t=0; t<T; ++t) {
        cin >> N >> M;
        int s, e;
        string result = "YES";
        vector<vector<int> > graph(300001);
        vector<int> visited(300001, -1);
        for (int i=0; i<M; ++i) {
            cin >> s >> e;
            graph[s].push_back(e);
            graph[e].push_back(s);
        }
        for (int i=1; i<=N; ++i) {
            if (visited[i] == -1) {
                visited[i] = 0;
                dfs(i, visited, graph);
            }
        }
        
        for (int i=1; i<=N; ++i) {
            if (result == "NO") break;
            for (int a : graph[i]) {
                if (visited[a] == visited[i]) {
                    result = "NO";
                    break;
                }
            }
        }
        cout << result << "\n";
    }

    return 0;
}
