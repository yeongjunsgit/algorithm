#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int N, M;
int result = -1;
vector<vector<int> > graph;

void check_sqrt(int now)
{
    double now_sqrt = sqrt(now);
    int int_now = now_sqrt;
    
    if (now_sqrt - int_now == 0) {
        if (result < now) {
            result = now;
        }
    }
    
    return;
}

void dungcha(int x, int y)
{
    int m_power = M * -1;
    for (int i=0; i<N; ++i) {
        for (int j=m_power; j<M; ++j) {
            if (i == 0 && j == 0) {
                continue;
            }
            int tmp = graph[x][y];
            int reverse_tmp = graph[x][y];
            int nx = x;
            int ny = y;
            check_sqrt(graph[x][y]);
            int reverse_power = 0;
            
            while (true) {
                reverse_power += 1;
                nx += i;
                ny += j;
                
                if (0 <= nx && nx < N && 0 <= ny && ny < M) {
                    tmp = tmp * 10 + graph[nx][ny];
                    reverse_tmp += graph[nx][ny] * pow(10, reverse_power);
                    
                    // if (x == 0 && y == 8 && i == 1 && j == - 2) {
                    //     cout << x << " " << y << " " << i << " " << j << "\n";
                    //     cout << tmp << "\n";
                    //     cout << reverse_tmp << "\n";
                    //     cout << reverse_power << "\n";
                    // }
                    // if (reverse_tmp == 94864) {
                    //     cout << x << " " << y << " " << i << " " << j << "\n";
                    // }
                    
                    check_sqrt(tmp);
                    check_sqrt(reverse_tmp);
                }
                else {
                    break;
                }
            }
        }
    }
    
    return;
}

void find_pow()
{
    for (int i=0; i<N; ++i) {
        for (int j=0; j<M; ++j) {
            dungcha(i, j);
        }
    }
    
    return;
}

int main()
{
    cin >> N >> M;
    
    graph.resize(N, vector<int>(M, 0));
    
    string data;
    
    for (int i=0; i<N; ++i) {
        cin >> data;
        int idx = 0;
        
        for (char a : data) {
            graph[i][idx] = a - '0';
            idx++;
        }
    }
    
    find_pow();
    
    cout << result;

    return 0;
}
