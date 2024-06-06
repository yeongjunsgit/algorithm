#include <iostream>
#include <sstream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int main()
{
    int N;
    cin >> N;
    
    cin.ignore();
    
    vector<vector<int>> dices;
    
    string data;
    int num;
    
    for (int i=0; i<N; ++i) {
        vector<int> dice;
        getline(cin, data);
        istringstream iss(data);
        while (iss >> num) {
            dice.push_back(num);
        }
        
        dices.push_back(dice);
    }

    int result = 0;

    map<int, int> reverse_pair = {{5, 0}, {0, 5}, {1, 3}, {3, 1}, {2, 4}, {4, 2}};

    for (int i=0; i<6; ++i) {
        int now = dices[0][i];
        int now_idx = i;
        int reverse_now = 0;
        int progressing = 0;
        int now_result = 0;
        while (progressing != N) {
            auto address = find(dices[progressing].begin(), dices[progressing].end(), now);
            now_idx = distance(dices[progressing].begin(), address);
            reverse_now = reverse_pair[now_idx];
            int now_best = 0;
            for (int j=0; j<6; ++j) {
                if (j != now_idx && j != reverse_now) {
                    if (now_best < dices[progressing][j]) {
                        now_best = dices[progressing][j];
                    }
                }
            }
            
            now_result += now_best;
            
            now = dices[progressing][reverse_now];
            progressing += 1;
        }
        
        if (result < now_result) {
            result = now_result;
        }
    }
    
    cout << result;

    return 0;
}
