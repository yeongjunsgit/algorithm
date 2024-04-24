#include <iostream>
#include <vector>

using namespace std;

int main()
{
    
    int king, queen, luke, bishop, knight, pown;
    cin >> king >> queen >> luke >> bishop >> knight >> pown;
    vector<int> board = {king, queen, luke, bishop, knight, pown};
    vector<int> base = {1, 1, 2, 2, 2, 8};
    
    for (int i=0; i<6; ++i) {
        cout << base[i] - board[i] << " ";
    }    
    

    return 0;
}
