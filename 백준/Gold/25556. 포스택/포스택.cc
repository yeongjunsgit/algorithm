#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

int main()
{
    int N;
    cin >> N;
    
    cin.ignore();
    
    string data;
    getline(cin, data);
    
    vector<vector<int>> four_stack(4);
    istringstream iss(data);
    int num;
    int idx = 3;
    string result = "YES";
    
    while (iss >> num) {
        if (idx == 3) {
            four_stack[idx].push_back(num);
            idx -= 1;
        }
        else {
            int too_small = 0;
            int dist = 999999;
            int best_way = -1;
            for (int i=0; i<4; ++i) {
                if (four_stack[i].size() != 0) {
                    if (four_stack[i].back() < num) {
                        int tmp = num - four_stack[i].back();
                        if (tmp < dist) {
                            dist = tmp;
                            best_way = i;
                        }
                    }
                    else {
                        too_small += 1;
                    }
                }
                else {
                    too_small += 1;
                }
            }
            if (too_small == 4 && idx != -1) {
                four_stack[idx].push_back(num);
                idx -= 1;
            }
            else {
                if (dist != 999999 && best_way != -1) {
                    four_stack[best_way].push_back(num);
                }
                else {
                    result = "NO";
                    break;
                }
            }
        }
    }
    
    cout << result;

    return 0;
}
