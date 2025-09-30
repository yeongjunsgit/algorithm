#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    long long N, num, now_furry = 0, total_furry = 0;
    cin >> N;
    
    for (int i=0; i<N; ++i) {
        cin >> num;
        if (num) now_furry++;
        else now_furry--;
        
        total_furry += now_furry;
    }
    
    cout << total_furry;
    
    return 0;
}
