#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N;
    cin >> N;

    for (int i=N; i>0; --i) {
        for (int j=N-i; j>0; --j) {
            cout << ' ';
        }
        for (int j=0; j<i; ++j) {
            cout << '*';
        }
        cout << "\n";
    }
    
    return 0;
}