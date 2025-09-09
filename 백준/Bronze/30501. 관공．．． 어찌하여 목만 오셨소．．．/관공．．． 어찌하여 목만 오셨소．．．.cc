#include <iostream>
#include <algorithm>

using namespace std;

int N; string my_name;

void check_name()
{
    for (int i=0; i<N; ++i) {
        cin >> my_name;
        for (char a : my_name) {
            if (a == 'S') {
                cout << my_name;
                return;
            }
        }
    }
    return;
}

int main()
{
    cin >> N;
    check_name();

    return 0;
}
