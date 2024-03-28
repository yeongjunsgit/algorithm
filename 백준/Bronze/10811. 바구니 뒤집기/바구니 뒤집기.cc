/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main()
{
    int N, M;
    cin >> N >> M;
    
    vector<int> arr;
    
    for (int i =0; i<N; ++i) {
        arr.push_back(i+1);
    }
    
    for (int j=0; j<M; ++j) {
        int I, J;
        cin >> I >> J;
        
        vector<int> tmpVec(arr.begin() + (I-1), arr.begin() + (J));
        reverse(tmpVec.begin(), tmpVec.end());
        int idx = 0;
        
        for (int k = I-1; k<J; ++k) {
            arr[k] = tmpVec[idx];
            idx += 1;
        }
    }

    for (int r=0; r<N; ++r) {
        cout << arr[r] << " ";
    }

    return 0;
}
