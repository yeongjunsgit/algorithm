#include <iostream>
#include <vector>

using namespace std;

int main()
{
    string data;
    
    cin >> data;
    int pipe = 0, result = 0;
    int N = data.size();
    for (int i=0; i<N; ++i) {
        if (data[i] == '(') {
            pipe++;
        }
        else if (data[i] == ')') {
            pipe--;
            if (data[i-1] == '(') {
                if (pipe > 0) {
                    result += pipe;
                }
            }
            else {
                result++;
            }
        }
    }
    
    cout << result;

    return 0;
}