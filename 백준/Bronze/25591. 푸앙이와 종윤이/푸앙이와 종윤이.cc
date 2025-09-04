#include <iostream>

using namespace std;

int N, M;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;
    
    int a = 100 - N;
    int b = 100 - M;
    int c = 100 - (a + b);
    int d = a * b;
    int q = d / 100;
    int r = d % 100;
    
    cout << a << " " << b << " " << c << " " << d << " " << q << " " << r << "\n";
    if (d >= 100) cout << c + q << " " << r;
    else cout << c << " " << d;

    return 0;
}