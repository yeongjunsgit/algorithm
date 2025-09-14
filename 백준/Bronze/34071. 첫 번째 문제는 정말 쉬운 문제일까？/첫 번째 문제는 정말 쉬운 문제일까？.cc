#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N, first, num;
    cin >> N >> first;
    int mini = first, maxy = first;
    
    for (int i=0; i<N-1; ++i) {
        cin >> num;
        mini = min(mini, num);
        maxy = max(maxy, num);
    }
    
    
    if (mini == first) cout << "ez";
    else if (maxy == first) cout << "hard";
    else cout << "?";
    

    return 0;
}