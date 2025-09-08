#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N;
    vector<int> years(100);
    cin >> N;
    for (int i=0; i<N; ++i) {
        cin >> years[i];
    }
    
    cout << years[N-1] + (years[1] - years[0]);
    

    return 0;
}