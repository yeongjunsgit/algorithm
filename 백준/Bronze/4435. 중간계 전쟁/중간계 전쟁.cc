#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T, num;
    vector<int> human_power = {1, 2, 3, 3, 4, 10}, evil_power = {1, 2, 2, 2, 3, 5, 10};
    cin >> T;
    for (int t=1; t<=T; ++t) {
        int human = 0, evil = 0;
        for (int i=0; i<6; ++i) {
            cin >> num;
            human += num * human_power[i];
        }
        for (int i=0; i<7; ++i) {
            cin >> num;
            evil += num * evil_power[i];
        }
        
        cout << "Battle " << t;
        if (human < evil) {
            cout << ": Evil eradicates all trace of Good\n";
        }
        else if (human > evil) {
            cout << ": Good triumphs over Evil\n";
        }
        else {
            cout << ": No victor on this battle field\n";
        }
    }

    return 0;
}
