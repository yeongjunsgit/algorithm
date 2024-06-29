#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

int main()
{
    vector<vector<int>> board(9, vector<int>(9, 0));
    
    string data;
    
    int num;
    int max_num = 0;
    pair<int, int> result;
    
    for (int i=0; i<9; ++i) {
        getline(cin, data);
        istringstream iss(data);
        int idx = 0;
        
        while (iss >> num) {
            if (max_num < num) {
                max_num = num;
                result = {i, idx};
            }
            
            idx += 1;
        }
    }
    
    cout << max_num << "\n";
    cout << result.first + 1 << " " << result.second + 1;

    return 0;
}
