#include <iostream>
#include <string>

using namespace std;
int N;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    string data;
    cin >> N >> data;
    int holl = 0, zzack = 0;
    for (int i=0; i<N; ++i) {
        int tmp = data[i] - '0';
        if (tmp % 2 == 0) zzack++;
        else holl++;
    }
    
    if (holl > zzack) cout << 1;
    else if (holl < zzack) cout << 0;
    else cout << -1;
    

    return 0;
}