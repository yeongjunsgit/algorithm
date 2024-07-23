#include <iostream>
#include <vector>

using namespace std;

int main()
{
    long long A, B, C;
    cin >> A >> B >> C;
    
    long long result = 0;
    
    if (B >= C) {
        cout << "-1";
    }
    
    else {
        result = A / (C - B) + 1;
        
        cout << result;
    }

    return 0;
}
