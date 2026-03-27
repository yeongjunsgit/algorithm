#include <iostream>

using namespace std;

int main()
{
    double N, M;
    cin >> N >> M;
    
    int now_time = 1440 * M / N ;
    
    int hour = now_time / 60;
    int minute = now_time % 60;
    
    if (hour < 10) cout << 0;
    cout << hour << ":";
    if (minute < 10) cout << 0;
    cout << minute;
    
    

    return 0;
}