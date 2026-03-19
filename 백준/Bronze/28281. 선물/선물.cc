#include <iostream>
#include <vector>

using namespace std;

int N, X, result = 2002;
vector<int> numbers(100001);

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> X;
    for (int i=0; i<N; ++i) {
        cin >> numbers[i];
    }
    
    for (int i=1; i<N; ++i) {
        result = min(result, numbers[i] + numbers[i - 1]);
    }
    
    cout << result * X;

    return 0;
}
