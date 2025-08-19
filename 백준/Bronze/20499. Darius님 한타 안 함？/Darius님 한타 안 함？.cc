#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    string kda;
    cin >> kda;
    
    vector<string> info(3, "");
    int check = 0;
    for (char a : kda) {
        if (a == '/') check++;
        else {
            info[check] += a;
        }
    }
    
    int K = stoi(info[0]), D = stoi(info[1]), A = stoi(info[2]);
    if (K + A < D || D == 0) cout << "hasu";
    else cout << "gosu";

    return 0;
}