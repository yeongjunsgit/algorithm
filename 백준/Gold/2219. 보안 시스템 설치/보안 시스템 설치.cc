/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <vector>

#define pll pair<int, int>

using namespace std;

int N, M, s, e, dist;
vector<vector<int> > graph(201, vector<int>(201, 999999999));


int get_best_computer()
{
    int best_time = 999999999, best_num = 0;
    
    for (int k=1; k<=N; ++k) {
        for (int i=1; i<=N; ++i) {
            for (int j= 1; j<=N; ++j) {
                if (i == j) continue;
                graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
                
            }
        }
    }
    
    for (int i=1; i<=N; ++i) {
        int tmp = 0;
        for (int j=1; j<=N; ++j) {
            if (i == j) continue;
            tmp += graph[i][j];
        }
        if (best_time > tmp) {
            best_time = tmp;
            best_num = i;
        }
    }
    
    return best_num;
}


int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;
    for (int i=0; i<M; ++i) {
        cin >> s >> e >> dist;
        graph[s][e] = dist;
        graph[e][s] = dist;
    }
    
    cout << get_best_computer();
    

    return 0;
}