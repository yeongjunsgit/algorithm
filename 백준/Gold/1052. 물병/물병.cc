#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
    // N = 물병의 개수, K = 물이들어있는 물병의 최대 개수
    int N, K;
    cin >> N >> K;
    
    int result = -1;
    
    if (N <= K) {
        result = 0;
    }
    
    else {
        for (int i=0; i<K; ++i) {
            if (i != K-1) {
                int temp = 1;
                while (temp < N) {
                    temp *= 2;
                }   
                N -= temp / 2;
            }
            else {
                int temp = 1;
                while (temp < N) {
                    temp *= 2;
                }   
                N -= temp;
            }
        }
        
        result = N * -1;
    }
    
    cout << result;

    return 0;
}
