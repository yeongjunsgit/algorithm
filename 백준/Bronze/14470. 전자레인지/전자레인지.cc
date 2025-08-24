#include <iostream>

using namespace std;

int main() {
    int A, B, C, D, E, T = 0;
    bool iced = false;
    cin >> A >> B >> C >> D >> E;
    if (A < 0) iced = true;
    while (A < B) {
        if (A < 0) {
            T += C;
            A++;
        }
        else if (A == 0 && iced == true) {
            iced = false;
            T += D;
        }
        else {
            T += E;
            A++;
        }
    }
    cout << T;

    return 0;
}