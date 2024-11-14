#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N, num;
    
    cin >> N;
    
    vector<int> numbers;
    
    for (int i=0; i<N; ++i) {
        cin >> num;
        numbers.push_back(num);
    }
    
    sort(numbers.begin(), numbers.end());
    
    for (int a : numbers) {
        cout << a << "\n";
    }

    return 0;
}