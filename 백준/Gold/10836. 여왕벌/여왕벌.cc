#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int M, N;
    cin >> M >> N;
    
    vector<vector<int>> worms(M, vector<int>(M, 1));
    
    vector<int> row_stack(2*M-1, 0);
    
    for (int i=0; i<N; ++i) {
        int zero, one, two;
        cin >> zero >> one >> two;
        
        for (int i=zero; i<zero+one; ++i) {
            row_stack[i] += 1;
        }
        
        for (int i=zero+one; i<zero+one+two; ++i) {
            row_stack[i] += 2;
        }
    }
    
    pair<int, int> loca = {M, 0};
    for (int i=0; i<2*M; ++i) {
        if (loca.first > 0) {
            loca.first -= 1;
        }
        else {
            loca.second += 1;
        }
        worms[loca.first][loca.second] += row_stack[i];
    }
    
    for (int i=0; i<M; ++i) {
        for (int j=0; j<M; ++j) {
            if (i == 0 || j == 0) {
                cout << worms[i][j] << " ";
            }
            else {
                cout << worms[i][j] + worms[0][j] - 1 << " ";
            }
        }
        cout << "\n";
    }

    return 0;
}
