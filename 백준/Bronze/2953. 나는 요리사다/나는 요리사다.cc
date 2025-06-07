#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int num, best = 0, best_score = 0;
    
    for (int i=1; i<=5; ++i) {
        int tmp = 0;
        for (int j=0; j<4; ++j) {
            cin >> num;
            tmp += num;
        }
        if (tmp > best_score) {
            best_score = tmp;
            best = i;
        }
    }
    
    cout << best << " " << best_score;
    
    return 0;
}