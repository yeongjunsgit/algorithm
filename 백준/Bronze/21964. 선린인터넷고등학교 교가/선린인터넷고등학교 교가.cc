#include <iostream>
#include <string>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N;
    string data;
    cin >> N >> data;
    
    string result = data.substr(N-5);
    
    cout << result;
    

    return 0;
}