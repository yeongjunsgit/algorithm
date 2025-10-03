#include <iostream>

using namespace std;

int main()
{
    int N, W, score = 0;
    cin >> N >> W;
    score += N * 10;
    if (N >= 3) score += 20;
    if (N == 5) score += 50;
    if (W > 1000) score -= 15;
    if (score < 0) score = 0;
    cout << score;

    return 0;
}