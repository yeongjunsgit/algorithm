#include <iostream>
#include <vector>

using namespace std;

int N;

long long dudu = 0;
long long dunga = 0;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> N;
    
    vector<vector<int> > graph(N+1);
    vector<pair<int, int> > connected;
    
    int s, e;
    
    for (int i=0; i<N-1; ++i) {
        cin >> s >> e;
        graph[s].push_back(e);
        graph[e].push_back(s);
        
        connected.push_back({s, e});
    }
    
    for (int i=1; i<=N; ++i) {
        if (graph[i].size() >= 3) {
            // 조합 개수를 구하는 공식
            dunga += (graph[i].size() * (graph[i].size() - 1) * (graph[i].size() - 2)) / 6;
        }
    }
    
    // 주어지는 간선은 중복되지않게 1개의 간선이 주어지는 것이고 이미 연결된 두개의 노드에서 각각 다른 노드로 연결되어있는 개수를 곱한 값이
    // ㄷ 모양이 되므로, 아래와 같은 연산이 가능하다
    // 간선에서 p의 경를 빼기위해 -1를 각각 해준다
    for (auto p : connected) {
        dudu += (graph[p.first].size() - 1) * (graph[p.second].size() - 1);
    }

    if (dudu > dunga * 3) {
        cout << "D";
    }
    else if (dudu < dunga * 3) {
        cout << "G";
    }
    else {
        cout << "DUDUDUNGA";
    }

    return 0;
}
