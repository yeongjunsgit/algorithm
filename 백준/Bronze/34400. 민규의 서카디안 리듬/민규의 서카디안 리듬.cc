#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T, num;
    
    cin >> T;
    for (int t=0; t<T; ++t) {
        cin >> num;
        
        int now_time = num % 25;
        if (now_time < 17) cout << "ONLINE\n";
        else cout << "OFFLINE\n";
    } 
    return 0;
}