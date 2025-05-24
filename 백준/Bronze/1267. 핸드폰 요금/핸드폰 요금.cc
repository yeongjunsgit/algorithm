#include <iostream>

using namespace std;

int main()
{
    int N, num, youngsick = 0, minsick = 0;
    cin >> N;
    for (int i=0; i<N; ++i) {
        cin >> num;
        youngsick += (num / 30 + 1) * 10;
        minsick += (num / 60 + 1) * 15;
    }
    
    if (youngsick < minsick) {
        cout << "Y " << youngsick; 
    }
    else if (youngsick > minsick) {
        cout << "M " << minsick;
    }
    else cout << "Y M " << youngsick;

    return 0;
}
