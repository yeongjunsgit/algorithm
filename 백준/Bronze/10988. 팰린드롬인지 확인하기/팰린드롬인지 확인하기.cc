#include <iostream>
#include <vector>

using namespace std;

int main()
{
    
    string data;
    cin >> data;
    
    int N = data.size();
    
    int result = 1;
    
    for (int i=0; i<N/2; ++i) {
        char left = data[i];
        char right = data[N-1-i];
        
        if (left != right) {
            result = 0;
            break;
        }
    }

    cout << result;

    return 0;
}
