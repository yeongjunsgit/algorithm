#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

int N, M;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> N >> M;
    cin.ignore();
    
    vector<vector<int>> stacker(N, vector<int>(M, 0));
    
    string data;
    int num;
    
    for (int i=0; i<N; ++i) {
        getline(cin, data);
        istringstream iss(data);
        int idx = 0;
        int line_sum = 0;
        
        while (iss >> num) {
            if (i != 0) {
                stacker[i][idx] += stacker[i-1][idx];
            }
            if (idx != 0) {
                stacker[i][idx] += line_sum;
            }
            stacker[i][idx] += num;
            line_sum += num;
            idx += 1;
        }
    }
    
    int orders;
    cin >> orders;
    
    int sx, sy, ex, ey;
    for (int i=0; i<orders; ++i) {
        cin >> sx >> sy >> ex >> ey;
        int base = stacker[ex-1][ey-1];
        bool multiple_check = false;
        if (sx - 1 != 0) {
            multiple_check = true;
            base -= stacker[sx-2][ey-1];
        }
        if (sy - 1 != 0) {
            if (multiple_check == true) {
                base += stacker[sx-2][sy-2];
            }
            base -= stacker[ex-1][sy-2];
        }
        
        cout << base << "\n";
    }

    return 0;
}
