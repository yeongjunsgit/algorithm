#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int L, A, B, C, D;
    cin >> L >> A >> B >> C >> D;
    
    int AC =  A / C;
    if (A % C != 0) {
        AC++;
    }
    int BD = B / D;
    if (B % D != 0) {
        BD++;
    }
    
    cout << L - max(AC, BD);

    return 0;
}