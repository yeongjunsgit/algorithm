#include <iostream>
#include <sstream>
#include <vector>

using namespace std;


int main()
{
    int N, M;
    cin >> N >> M;
    
    cin.ignore();
    
    vector<vector<int>> arr_1(N);

    string data;
    int num;

    for (int i=0; i<N; ++i) {
        getline(cin, data);
        istringstream iss(data);
        
        while (iss >> num) {
            arr_1[i].push_back(num);
        }
    }
    
    for (int i=0; i<N; ++i) {
        getline(cin, data);
        istringstream iss(data);
        int idx = 0;
        
        while (iss >> num) {
            arr_1[i][idx] += num;
            idx += 1;
        }
    }

    for (int i=0; i<N; ++i) {
        for (int j=0; j<M; ++j) {
            cout << arr_1[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}
