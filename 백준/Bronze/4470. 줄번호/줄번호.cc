#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N;
    cin >> N;
    cin.ignore();
    string data;
    for (int i=1; i<=N; ++i) {
        getline(cin, data);
        cout << i << ". " << data << "\n";
    }

    return 0;
}