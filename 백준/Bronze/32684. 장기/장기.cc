#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> score = {720, 735};
    vector<vector<int> > info(2, vector<int>(6));
    for (int i=0; i<2; ++i) {
        for (int j=0; j<6; ++j) {
            cin >> info[i][j];
        }
    }
    
    for (int i=0; i<2; ++i) {
        score[i] -= (2 - info[i][0]) * 130; 
        score[i] -= (2 - info[i][1]) * 70;
        score[i] -= (2 - info[i][2]) * 50;
        score[i] -= (2 - info[i][3]) * 30;
        score[i] -= (2 - info[i][4]) * 30;
        score[i] -= (5 - info[i][5]) * 20;
    }
    
    if (score[0] > score[1]) cout << "cocjr0208";
    else cout << "ekwoo";

    return 0;
}
