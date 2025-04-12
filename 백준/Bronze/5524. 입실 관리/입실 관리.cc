#include <iostream>

using namespace std;

int N;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    cin >> N;
    string data;
    for (int i=0; i<N; ++i) {
        cin >> data;
        for (char a : data) {
            if ('A' <= a && a <= 'Z') {
                char b = a + 32;
                cout << b;
            }
            else {
                cout << a;
            }
        }
        cout << "\n";
    }

    return 0;
}