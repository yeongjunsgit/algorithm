#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    string N, M;
    
    cin >> N >> M;
    
    reverse(N.begin(), N.end());
    reverse(M.begin(), M.end());
    
    if (stoi(N) > stoi(M)) {
        cout << stoi(N);
    }
    else {
        cout << stoi(M);
    }
    

    return 0;
}
