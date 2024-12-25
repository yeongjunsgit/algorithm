#include <iostream>
#include <string>

using namespace std;

int main()
{
    string data;
    while (true) {
        getline(cin, data);
        if (data == "#") {
            break;
        }
        
        int result = 0;
        
        for (char c : data) {
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c =='u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') {
                result++;
            }
        }
        
        cout << result << "\n";
    }

    return 0;
}