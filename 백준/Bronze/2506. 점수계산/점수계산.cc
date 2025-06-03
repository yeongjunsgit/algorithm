#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N, num, cnt = 0, score = 0;
    cin >> N;
    for (int i=0; i<N; ++i) {
        cin >> num;
        if (num == 1) {
            score++;
            cnt += score;
        }
        else if (num == 0) {
            score = 0;
        }
    }
    
    cout << cnt;

    return 0;
}