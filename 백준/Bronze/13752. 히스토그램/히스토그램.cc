#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N, num;
    cin >> N;
    
    for (int i=0; i<N; ++i) {
        cin >> num;
        for (int j=0; j<num; ++j) {
            cout << '=';
        }
        cout << "\n";
    }
    
    return 0;
}