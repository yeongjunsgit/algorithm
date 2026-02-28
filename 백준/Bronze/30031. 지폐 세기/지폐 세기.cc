#include <iostream>
#include <map>

using namespace std;

int N, col, row, result = 0;
map<int, int> prices = {{136, 1000}, {142, 5000}, {148, 10000}, {154, 50000}};

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    for (int i=0; i<N; ++i) {
        cin >> row >> col;
        result += prices[row];
    }
    
    cout << result;
    
    return 0;
}