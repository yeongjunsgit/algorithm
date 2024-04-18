#include <iostream>

#include <vector>

#include <queue>

using namespace std;

int main()

{

    

    ios_base::sync_with_stdio(false);

    cin.tie(NULL);

    

    int N;

    cin >> N;

    

    int visited[N+1]{0};

    vector<vector<int>> graph(N+1);

    

    for (int i=0; i<N-2; ++i) {

        int s, e;

        cin >> s >> e;

        

        graph[s].push_back(e);

        graph[e].push_back(s);

        

    }

    int now_tree = 1;

    for (int i=1; i<N+1; ++i) {

        if (visited[i] == 0) {

            

            if (now_tree != 1) {

                cout << "1 " << i << "\n";

            }

            

            visited[i] = now_tree;

            queue<int> que;

            que.push(i);

            

            while (!que.empty()) {

                int now = que.front();

                que.pop();

                

                if (graph[now].size() != 0) {

                    for (int j=0; j<graph[now].size(); ++j) {

                        int next = graph[now][j];

                        if (visited[next] == 0) {

                            visited[next] = now_tree;

                            que.push(next);

                        }

                    }

                }

            }

            

            now_tree += 1;

        }

    }

    return 0;

}