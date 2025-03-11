#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> command(10, 0); 
int result = 0;
int visited[33]{0};
unordered_map<int, int> graph, points, special_route;
vector<int> pawn(4, 0);

void dfs(int score, int depth)
{
    if (depth == 10) {
        if (result < score) {
            result = score;
        }
        return;
    }
    
    for (int i=0; i<4; ++i) {
        int now = pawn[i];
        if (now != 21) {
            int next = now;
            if (now == 5 || now == 10 || now == 15) {
                next = special_route[now];
                for (int j=1; j<command[depth]; ++j) {
                    if (next != 21) {
                        next = graph[next];
                    }
                    else break;
                }
            }
            else {
                for (int j=0; j<command[depth]; ++j) {
                    if (next != 21) {
                        next = graph[next];
                    }
                    else break;
                }
            }
            
            if (visited[next] == 0) {
                if (next != 21) {
                    visited[now] = 0;
                    visited[next] = 1;
                    pawn[i] = next;
                    dfs(score + points[next], depth + 1);
                    visited[now] = 1;
                    visited[next] = 0;
                    pawn[i] = now;
                }
                else {
                    visited[now] = 0;
                    pawn[i] = next;
                    dfs(score, depth + 1);
                    visited[now] = 1;
                    pawn[i] = now;
                }
            }
        }
    }
    
    return;
}


int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    for (int i=0; i<10; ++i) {
        cin >> command[i];
    }
    vector<pair<int, bool> > pawn(4, {0, false});
    
    graph[0] = 1; points[0] = 0;
    for (int i=1; i<=30; ++i) {
        graph[i] = i + 1;
    }
    graph[21] = -1; graph[27] = 25; graph[30] = 25; graph[25] = 31; graph[31] = 32; graph[32] = 20;
    
    for (int i=1; i<=20; ++i) {
        points[i] = i * 2;
    }
    points[21] = 0; points[22] = 13; points[23] = 16; points[24] = 19; points[25] = 25; points[26] = 22;
    points[27] = 24; points[28] = 28; points[29] = 27; points[30] = 26; points[31] = 30; points[32] = 35;
    
    special_route[5] = 22; special_route[10] = 26; special_route[15] = 28;
    
    dfs(0, 0); 

    cout << result;
    
    return 0;
}
