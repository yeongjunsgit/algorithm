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
    
    vector<int> row_stack(M, 0);
    
    for (int i=0; i<N; ++i) {
        int zero, one, two;
        cin >> zero >> one >> two;
        
        pair<int, int> loca = {M, 0};
        int progressing = 0;
        
        for (int i=0; i<zero; ++i) {
            progressing += 1;
            if (loca.first != 0) {
                loca.first -= 1;
            }
            else {
                loca.second += 1;
            }
        }
        
        for (int i=0; i<one; ++i) {
            progressing += 1;
            if (loca.first != 0) {
                loca.first -= 1;
            }
            else {
                loca.second += 1;
            }
            
            worms[loca.first][loca.second] += 1;
            
            if (progressing > M) {
                row_stack[loca.second] += 1;
            }
        }
        
        for (int i=0; i<two; ++i) {
            progressing += 1;
            if (loca.first != 0) {
                loca.first -= 1;
            }
            else {
                loca.second += 1;
            }
            
            worms[loca.first][loca.second] += 2;
            
            if (progressing > M) {
                row_stack[loca.second] += 2;
            }
        }
    }
    
    for (int i=0; i<M; ++i) {
        for (int j=0; j<M; ++j) {
            if (i == 0 || j == 0) {
                cout << worms[i][j] << " ";
            }
            else {
                cout << worms[i][j] + row_stack[j] << " ";
            }
        }
        cout << "\n";
    }

    return 0;
}
