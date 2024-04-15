#include <iostream>

using namespace std;

int main()
{
    int T;
    cin >> T;
    cin.ignore();
    
    string data;
    for (int i=0; i<T; ++i) {
        getline(cin, data);
        cout << data[0] << data[data.size() - 1] << "\n";
    }

    return 0;
}