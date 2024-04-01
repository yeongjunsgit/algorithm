#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int T;
    cin >> T;
    
    int apartment[15][15];
    
    for (int i=0; i<15; ++i) {
        apartment[0][i] = i;
    }
    
    for (int i=1; i<15; ++i) {
        for (int j=1; j<15; ++j) {
            int tmp_sum = 0;
            for (int k=1; k<j+1; ++k) {
                tmp_sum += apartment[i-1][k];
            }
            apartment[i][j] = tmp_sum;
        }
    }
    
    for (int i=0; i<T; ++i) {
        int building_floor, room_number;
        
        cin >> building_floor;
        cin >> room_number;
        
        cout << apartment[building_floor][room_number] << "\n";
    }

    return 0;
}
