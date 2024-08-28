#include <iostream>
#include <vector>
#include <queue>
#include <map>

using namespace std;

int N;

long long dfs(vector<vector<int>>& graph, map<int, pair<char, pair<int, int>>>& island_info, int now)
{
    if (graph[now].size() > 0) {
        int M = graph[now].size();
        long long now_data = 0;
        for (int i=0; i<M; ++i) {
            now_data += dfs(graph, island_info, graph[now][i]);
        }
        
        if (island_info[now].first == 'W') {
            return max(0ll, now_data - island_info[now].second.first);
        }
        else {
            return now_data + island_info[now].second.first;
        }
    }
    
    else {
        if (island_info[now].first == 'W') {
            return 0;
        }
        else {
            return island_info[now].second.first;
        }
    }

	
}

int main()
{
	cin >> N;

	vector<vector<int>> graph(N);
	map<int, pair<char, pair<int, int>>> island_info;

	char island;
	int num, connect;

	for (int i=1; i<N; ++i) {
		cin >> island >> num >> connect;
		graph[connect - 1].push_back(i);
		island_info[i] = {island, {num, connect - 1}};
	}
	
	long long result = dfs(graph, island_info, 0);
	
	cout << result;

	return 0;
}
