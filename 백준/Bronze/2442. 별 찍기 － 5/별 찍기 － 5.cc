#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    int N;
    cin >> N;
    
    for (int i=0; i<N; ++i) {
        for (int j= N - 1 - i; j>0; --j) {
            cout << ' ';
        }
        for (int k=0; k<i; ++k) {
            cout << '*';
        }
        cout << '*';
        for (int k=0; k<i; ++k) {
            cout << '*';
        }
        cout << "\n";
    }
    

    return 0;
}