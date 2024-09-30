/*
플루이드 워샬로 했다
당연히 해당 도시로 가는 모든 친구들의 거리를 합한 최댓값 중 최소값을 찾으라는줄 알았는데
X라는 도시로 모든 친구들이 가는 거리 들 중 가장 큰 값을 찾고, 그 중에서 가장 작은 값을 가지는 도시를 찾으라는
문제였다 독해력 문제
*/
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M, K;

void lets_check(vector<vector<int> >& graph, vector<int>& friends_loca)
{
    for (int i=1; i<=N; ++i) {
        for (int j=1; j<=N; ++j) {
            for (int k=1; k<=N; ++k) {
                graph[j][k] = min(graph[j][k], graph[j][i] + graph[i][k]);
            }
        }
    }
    
    int result = 2147483647;
    vector<int> result_loca;
    
    for (int i=1; i<=N; ++i) {
        int tmp = 0;
        for (int j=0; j<K; ++j) {
            tmp = max(tmp, graph[friends_loca[j]][i] + graph[i][friends_loca[j]]);
        }
        
        if (tmp < result) {
            result = tmp;
            result_loca = {i};
        }
        else if (tmp == result) {
            result_loca.push_back(i);
        }
    }
    
    for (int a : result_loca) {
        cout << a << " ";
    }
    
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> N >> M;
    
    int s, e, dist;
    
    vector<vector<int> > graph(N+1, vector<int>(N+1, 400001));
    vector<int> friends_loca;
    
    for (int i=1; i<=N; ++i) {
        graph[i][i] = 0;
    }
    
    for (int i=0; i<M; ++i) {
        cin >> s >> e >> dist;
        
        graph[s][e] = dist;
        
    }
    
    cin >> K;
    int num;
    for (int i=0; i<K; ++i) {
        cin >> num;
        friends_loca.push_back(num);
    }
    
    
    lets_check(graph, friends_loca);


    return 0;
}
