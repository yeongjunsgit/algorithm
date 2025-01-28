#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int N;
vector<vector<char> > paper;

void draw_triangle(int x, int y)
{
    paper[x][y] = '*';
    paper[x+1][y-1] = '*';
    paper[x+1][y+1] = '*';
    for (int i=-2; i<=2; ++i) {
        paper[x+2][y + i] = '*';
    }
    
    return;
}

void star_star(int now, int base, int depth)
{
    if (depth == 1) {
        draw_triangle(base, now);
        return;
    }
    else {
        int depth_size = (depth * 3 / 2);
        int first_point = now;
        int second_point = now - depth_size;
        int third_point = now + depth_size;
        
        star_star(first_point, base, depth / 2);
        star_star(second_point, base + depth_size, depth / 2);
        star_star(third_point, base + depth_size, depth / 2);
        
        return;
    }
}

void print_star()
{
    for (int i=0; i<N; ++i) {
        for (int j=1; j<N * 2; ++j) {
            cout << paper[i][j];
        }
        cout << "\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N;
    paper.resize(N+1, vector<char>(N * 2, ' '));
    
    int twotwo = N / 3;
    
    star_star(N, 0, twotwo);
    
    print_star();

    return 0;
}
