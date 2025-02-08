#include <iostream>

using namespace std;

int main()
{
    int N;
    cin >> N;
    

    int start = 1;
    int room = 1;
    while (start < N) {
        start += room * 6;
        room++;
    }
    
    cout << room;


    return 0;
}