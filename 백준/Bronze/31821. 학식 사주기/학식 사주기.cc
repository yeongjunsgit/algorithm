#include <iostream>
#include <vector>

using namespace std;

int N, M, num, result = 0;
vector<int> price(11, 0);
int main()
{
    cin >> N;
    for (int i=1; i<=N; ++i) {
        cin >> price[i];
    }
    cin >> M;
    for (int i=0; i<M; ++i) {
        cin >> num;
        result += price[num];
    }
    
    cout << result;

    return 0;
}