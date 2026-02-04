#include <iostream>
#include <string>

using namespace std;

int main()
{
    string data;
    cin >> data;
    int N = data.size(), cnt = 0;
    for (int i=0; i<=N-4; ++i) {
        string tmp = data.substr(i, 4);
        if (tmp == "DKSH") cnt++;
    }
    
    cout << cnt;

    return 0;
}