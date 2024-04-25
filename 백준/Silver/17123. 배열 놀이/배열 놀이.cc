#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    cin >> T;
    
    for (int t=0; t<T; ++t) {
        int N, M;
        cin >> N >> M;
        
        cin.ignore();
        
        vector<int> row_sum;
        vector<int> column_sum(N);
        
        for (int i=0; i<N; ++i) {
            int r_sum = 0;
            string data;
            getline(cin, data);
            istringstream iss(data);
            int num;
            int idx = 0;
            
            while (iss >> num) {
                r_sum += num;
                column_sum[idx] += num;
                idx += 1;
            }
            row_sum.push_back(r_sum);
        }
        
        for (int i=0; i<M; ++i) {
            int x1, y1, x2, y2, weight;
            cin >> x1 >> y1 >> x2 >> y2 >> weight;
            
            for (int j = x1-1; j <= x2-1; ++j) {
                row_sum[j] += weight * (y2 - y1 + 1);
            }
            for (int k = y1-1; k <= y2-1; ++k) {
                column_sum[k] += weight * (x2 - x1 + 1);
            }
        }
        
        
        for (int i=0; i<N; ++i) {
            cout << row_sum[i] << " ";
        }
        
        cout << "\n";
        
        for (int i=0; i<N; ++i) {
            cout << column_sum[i] << " ";
        }
        
        cout << "\n";
    }

    return 0;
}
