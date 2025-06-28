#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int s, e;
    while (true) {
        cin >> s >> e;
        if (s == 0 && e == 0) break;
        
        if (s > e) cout << "Yes\n";
        else cout << "No\n";
        
    }
    

    return 0;
}