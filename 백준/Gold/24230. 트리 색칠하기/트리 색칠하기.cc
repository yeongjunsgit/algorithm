#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

struct tree_node {
  int parent;
  int color;
  int child;
};

void explore_tree(int& result, int now, int parents, vector<int>* colors, vector<vector<int>>* graph, vector<int>* now_color);

void explore_tree(int& result, int now, int parents, vector<int>* colors, vector<vector<int>>* graph, vector<int>* now_color) {
    if ((*now_color)[parents] != (*colors)[now]) {
        result += 1;
    }
    (*now_color)[now] = (*colors)[now];
    
    if ((*graph)[now].size() != 0) {
        for (int i=0; i<(*graph)[now].size(); ++i) {
            if ((*graph)[now][i] != parents) {
                explore_tree(result, (*graph)[now][i], now, colors, graph, now_color);
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N;
    cin >> N;
    
    cin.ignore();
    
    string data;
    getline(cin, data);
    int num;
    
    vector<int> colors;
    colors.push_back(0);
    istringstream iss(data);
    
    while (iss >> num) {
        colors.push_back(num);
    }
    
    vector<vector<int>> graph(N+1);
    
    for (int i=0; i<N-1; ++i) {
        int s, e;
        cin >> s >> e;
        
        graph[s].push_back(e);
        graph[e].push_back(s);
    }
    
    vector<int> now_color(N+1, 0);
    int result = 0;
    
    explore_tree(result, 1, 0, &colors, &graph, &now_color);
    
    cout << result;
    

    return 0;
}