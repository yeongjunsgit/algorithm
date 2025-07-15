#include <iostream>
#include <string>

using namespace std;

int main()
{
    string A, B, C;
    cin >> A >> B >> C;
    int wow = stoi(A) + stoi(B) - stoi(C);
    string tmp = A + B;
    int amazing = stoi(tmp) - stoi(C);
    
    cout << wow << "\n" << amazing;

    return 0;
}