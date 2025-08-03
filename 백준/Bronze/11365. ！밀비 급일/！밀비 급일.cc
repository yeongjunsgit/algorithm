#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    string data;
    while (true) {
        getline(cin, data);
        if (data == "END") break;
        int N_size = data.size();
        
        for (int i=N_size - 1; i>=0; --i) {
            cout << data[i];
        }
        cout << "\n";
    }
    
    return 0;
}
