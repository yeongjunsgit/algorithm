#include <iostream>
#include <vector>

using namespace std;

int N, M;

vector<vector<bool> > graph;
int result = 0;

void check_naemo(int x, int y)
{
    int nx = x;
    int ny = y;
    
    if (y == M) {
        nx++;
        ny = 0;
        if (nx == N) {
            result++;
            return;
        }
    }
    
    check_naemo(nx, ny+1);
    
    graph[nx][ny] = true;
    if (nx - 1 >= 0 && ny - 1 >= 0) {
        if (graph[nx-1][ny-1] == true && graph[nx-1][ny] == true && graph[nx][ny-1] == true) {
            graph[nx][ny] = false;
            return;
        }
    }
    
    check_naemo(nx, ny+1);
    graph[nx][ny] = false;
    
    return;
    
}

int main()
{
    cin >> N >> M;

    graph.resize(N, vector<bool>(M, false));
    
    check_naemo(0, 0);
    
    cout << result;

    return 0;
}
