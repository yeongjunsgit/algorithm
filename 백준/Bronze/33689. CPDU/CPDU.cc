#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N, cnt = 0; string league_name;
    cin >> N;
    for (int i=0; i<N; ++i) {
        cin >> league_name;
        if (league_name[0] == 'C') cnt++;
    }
    
    cout << cnt;
    

    return 0;
}