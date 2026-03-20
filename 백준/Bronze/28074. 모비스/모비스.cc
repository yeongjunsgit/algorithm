#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    string data;
    cin >> data;
    map<char, int> check;
    
    for (char c : data) {
        check[c]++;
    }
    
    if (check['M'] && check['O'] && check['B'] && check['I'] && check['S']) {
        cout << "YES";
    }
    else cout << "NO";

    return 0;
}
