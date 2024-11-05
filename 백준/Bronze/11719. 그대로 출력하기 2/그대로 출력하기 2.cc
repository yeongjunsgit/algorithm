#include <iostream>
#include <string>

using namespace std;

int main()
{
    string data;
    
    while (getline(cin, data)) {
        cout << data << "\n";
    }

    return 0;
}
