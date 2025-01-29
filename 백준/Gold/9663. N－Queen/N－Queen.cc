#include <iostream>
#include <vector>
#include <cmath>

#define pll pair<int, int>

using namespace std;

int N;
vector<int> board(15, 0);
int result = 0;

bool checking(int low)
{
    for (int i=0; i<low; ++i) {
        int one = abs(i - low);
        int two = abs(board[i] - board[low]);
        if (board[i] == board[low] || one == two) return true;
    }

    return false;
}

void set_queen(int x)
{
    if (x == N) {
        result++;
        return;
    }
    
    for (int j=0; j<N; ++j) {
        
        board[x] = j;
        
        if (!checking(x)) {
            set_queen(x+1);
        }
    }
    
    return;
}

int main()
{
    cin >> N;
    
    set_queen(0);
    
    cout << result;

    return 0;
}
