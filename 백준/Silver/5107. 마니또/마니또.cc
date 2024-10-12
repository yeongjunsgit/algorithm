#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int result;

void dfs(unordered_map<string, string>& graph, unordered_map<string, bool>& visited, unordered_map<string, bool> passed, string now)
{
    if (passed.find(graph[now]) == passed.end()) {
        if (visited[graph[now]] == false) {
            visited[graph[now]] = true;
            passed[graph[now]] = true;
            dfs(graph, visited, passed, graph[now]);
        }
        return;
    }
    else {
        result++;
        return;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N;
    int T = 0;
    
    while (true) {
        T++;
        result = 0;
        cin >> N;
        if (N == 0) {
            break;
        }
        
        unordered_map<string, string> graph;
        unordered_map<string, bool> visited;
        vector<string> people;
        string s, e;
        
        for (int i=0; i<N; ++i) {
            cin >> s >> e;
            graph[s] = e;
            visited[s] = false;
            visited[e] = false;
            people.push_back(s);
            people.push_back(e);
        }
        
        for (string a : people) {
            if (visited[a] == false) {
                unordered_map<string, bool> passed;
                passed[a] = true;
                visited[a] = true;
                dfs(graph, visited, passed, a);
            }
        }
        
        cout << T << " " << result << "\n";
        
    }

    return 0;
}
