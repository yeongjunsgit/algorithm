#include <iostream>

using namespace std;

int main()
{
    int hour, minute, second, cocking;
    cin >> hour >> minute >> second >> cocking;
    
    if (cocking >= 3600) {
        hour += cocking / 3600;
        cocking %= 3600;
    }
    if (cocking >= 60) {
        minute += cocking / 60;
        cocking %= 60;
    }
    if (cocking > 0) {
        second += cocking;
    }
    
    if (second >= 60) {
        minute += second / 60;
        second %= 60;
    }
    if (minute >= 60) {
        hour += minute / 60;
        minute %= 60;
    }
    if (hour >= 24) {
        hour %= 24;
    }
    
    cout << hour << " " << minute << " " << second;

    return 0;
}