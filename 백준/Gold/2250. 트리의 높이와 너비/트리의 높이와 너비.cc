#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

vector<pair<int, int> > graph;
int best_level = 1, best_length = 1;
vector<int> node_loca;
vector<int> node_level;
vector<vector<int> > level_edge;
unordered_map<int, int> loca_node;
queue<int> checking;
int tree_root = 0;

void set_child(int now)
{
    pair<int, int> now_child = graph[now];
    
    if (now == tree_root) {
        if (now_child.second != -1) {
            node_loca[now_child.second] = 1;
            loca_node[1] = now_child.second;
            node_level[now_child.second] = 2;
        }
        if (now_child.first != -1) {
            node_loca[now_child.first] = -1;
            loca_node[-1] = now_child.first;
            node_level[now_child.first] = 2;
        }
    }
    
    else {
        if (node_loca[now] < 0) {
            if (now_child.second != -1) {
                node_level[now_child.second] = node_level[now] + 1;
                int tmp = now_child.second;
                int tmp_loca = node_loca[now];
                
                while (true) {
                    if (loca_node.find(tmp_loca) == loca_node.end()) {
                        node_loca[tmp] = tmp_loca;
                        loca_node[tmp_loca] = tmp;
                        break;
                    }
                    else {
                        int already_num = loca_node[tmp_loca];
                        loca_node[tmp_loca] = tmp;
                        node_loca[tmp] = tmp_loca;
                        tmp = already_num;
                        tmp_loca -= 1;
                    }
                }
            }
            
            if (now_child.first != -1) {
                node_level[now_child.first] = node_level[now] + 1;
                int tmp = now_child.first;
                int tmp_loca = node_loca[now] - 1;
                while (true) {
                    if (loca_node.find(tmp_loca) == loca_node.end()) {
                        node_loca[tmp] = tmp_loca;
                        loca_node[tmp_loca] = tmp;
                        break;
                    }
                    else {
                        int already_num = loca_node[tmp_loca];
                        loca_node[tmp_loca] = tmp;
                        node_loca[tmp] = tmp_loca;
                        tmp = already_num;
                        tmp_loca -= 1;
                    }
                }
            }
        }
        
        else if (node_loca[now] > 0){
            if (now_child.first != -1) {
                node_level[now_child.first] = node_level[now] + 1;
                int tmp = now_child.first;
                int tmp_loca = node_loca[now];
                
                while (true) {
                    if (loca_node.find(tmp_loca) == loca_node.end()) {
                        node_loca[tmp] = tmp_loca;
                        loca_node[tmp_loca] = tmp;
                        break;
                    }
                    else {
                        int already_num = loca_node[tmp_loca];
                        loca_node[tmp_loca] = tmp;
                        node_loca[tmp] = tmp_loca;
                        tmp = already_num;
                        tmp_loca += 1;
                    }
                }
            }
            
            if (now_child.second != -1) {
                node_level[now_child.second] = node_level[now] + 1;
                int tmp = now_child.second;
                int tmp_loca = node_loca[now] + 1;
                
                while (true) {
                    if (loca_node.find(tmp_loca) == loca_node.end()) {
                        node_loca[tmp] = tmp_loca;
                        loca_node[tmp_loca] = tmp;
                        break;
                    }
                    else {
                        int already_num = loca_node[tmp_loca];
                        loca_node[tmp_loca] = tmp;
                        node_loca[tmp] = tmp_loca;
                        tmp = already_num;
                        tmp_loca += 1;
                    }
                }
            }
            
        }
        else {
            return;
        }
    }
    
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N;
    cin >> N;
    
    graph.resize(N+1);
    node_loca.resize(N+1, 0);
    node_level.resize(N+1, 0);
    level_edge.resize(N+1);
    vector<bool> check_root(N+1, false);
    int node, left, right;
    
    for (int i=0; i<N; ++i) {
        cin >> node >> left >> right;
        if (left != -1) {
            check_root[left] = true;
        }
        if (right != -1) {
            check_root[right] = true;
        }
        graph[node] = {left, right};
        
    }
    
    for (int i=1; i<=N; ++i) {
        if (check_root[i] == false) {
            tree_root = i;
            node_level[i] = 1;
            checking.push(i);
            break;
        }
    }
    
    while(!checking.empty()) {
        int now_node = checking.front();
        checking.pop();
        level_edge[node_level[now_node]].push_back(now_node);
        
        if (graph[now_node].first != -1) {
            checking.push(graph[now_node].first);
        }
        if (graph[now_node].second != -1) {
            checking.push(graph[now_node].second);
        }
        set_child(now_node);
    }
    
    for (int i=2; i<=N; ++i) {
        if (level_edge[i].size() == 0) {
            break;
        }

        
        // cout << level_edge[i][0] << " " << level_edge[i][level_edge[i].size() - 1] << "\n";
        // cout << node_loca[level_edge[i][0]] << " " << node_loca[level_edge[i].size() - 1] << "\n";
        // cout << "\n";
        int tmp_length = node_loca[level_edge[i][level_edge[i].size() - 1]] - node_loca[level_edge[i][0]] + 1;
        
        if (best_length < tmp_length) {
            best_length = tmp_length;
            best_level = i;
        }
    }
    
    cout << best_level << " " << best_length;

    return 0;
}
