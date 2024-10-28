#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

vector<vector<char> > board;
vector<int> liner(5, 0);
int max_length_sentence = 0;

void repeat_print(int idx, int now)
{
    if (now < liner[idx]) {
        cout << board[idx][now];
    }
    if (idx < 4) {
        repeat_print(idx + 1, now);
    }
    
    return;

}


int main()
{
    string data;
    
    
    for (int i=0; i<5; ++i) {
        cin >> data;
        liner[i] = data.size();
        if (max_length_sentence < liner[i]) {
            max_length_sentence = liner[i];
        }
        
        vector<char> one_line;
        for (auto a : data) {
            one_line.push_back(a);
        }
        board.push_back(one_line);
    }
    
    for (int i=0; i<max_length_sentence; ++i) {
        repeat_print(0, i);
    }
    
    return 0;
}
