#include <iostream>
#include <vector>

using namespace std;

int N, K;
long long super_level = 0;
long long min_level = 1000000001;

vector<int> players;

long long check_leveling(long long expoint) {
    long long cost = 0;
    for (int a : players) {
        cost += max(expoint - a, 0ll);
    }
    
    return cost;
}

void binary_check()
{
    long long start = min_level;
    long long end = super_level + K + 1;
    
    while (start <= end) {
        long long mid = (start + end) / 2;
        
        long long tmp = check_leveling(mid);
        
        if (tmp <= K) {
            start = mid + 1;
        }
        else {
            end = mid - 1;
        }
    }
    
    cout << end;
    
    return;
    
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> N >> K;
    int num;
    

    for (int i=0; i<N; ++i) {
        cin >> num;
        players.push_back(num);
        if (num > super_level) {
            super_level = num;
        }
        if (num < min_level) {
            min_level = num;
        }
    }
    
    binary_check();

    return 0;
}
