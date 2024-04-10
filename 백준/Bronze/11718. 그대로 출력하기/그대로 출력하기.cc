#include <iostream>

using namespace std;

int main()
{
    string data;
    while (!cin.eof()) {
        getline(cin, data);
        
        cout << data << "\n";
    } 

    return 0;
}
