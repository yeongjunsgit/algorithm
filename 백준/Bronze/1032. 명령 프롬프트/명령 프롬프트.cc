#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N;
    cin >> N;
    
    string base, now;
    int idx = 0;
    int M;
    vector<char> result;
    
    for (int i=0; i<N; ++i) {
        if (idx == 0) {
            idx++;
            cin >> base;
            M = base.size();
            result.resize(M, '.');
            
            for (int j=0; j<M; ++j) {
                result[j] = base[j];
            }
        }
        else {
            cin >> now;
            for (int j=0; j<M; ++j) {
                if (base[j] != now[j]) {
                    result[j] = '?';
                }
            }
            
        }
    }
    
    for (char c : result) {
        cout << c;
    }

    return 0;
}
