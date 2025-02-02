#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N, num, T, P;
    cin >> N;
    vector<int> tshirt;
    for (int i=0; i<6; ++i) {
        cin >> num;
        tshirt.push_back(num);
    }
    
    cin >> T >> P;
    
    int T_pack = 0, P_pack, P_each;
    for (int i=0; i<6; ++i) {
        T_pack += tshirt[i] / T;
        if (tshirt[i] % T > 0) {
            T_pack += 1;
        }
    }
    
    P_pack = N / P;
    P_each = N % P;
    
    cout << T_pack << "\n";
    cout << P_pack << " " << P_each;

    return 0;
}