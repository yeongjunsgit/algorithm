#include <iostream>
#include <string>

using namespace std;

int main()
{
    string data;
    cin >> data;
    
    int start = 0;
    int cut_size = 10;
    int N = data.size();
    
    while (start < N) {
        cout << data.substr(start, cut_size) << "\n";
        start += 10;
    }

    return 0;
}
