#include <iostream>
#include <vector>
#include <limits>

using namespace std;

int T, N;
long long LLMAX = numeric_limits<long long>::max();


bool is_complete(vector<long long>& damages, vector<long long>& heal_point, vector<char>& magic, long long now, long long total_damage)
{
    if (now > total_damage) return true;
    
    for (int i=0; i<N; ++i) {
        now -= damages[i];
        total_damage -= damages[i];
        if (now <= 0) return false;
        
        if (magic[i] == '+') {
            if (LLMAX - heal_point[i] < now) now = LLMAX;
            else now += heal_point[i];
        }
        
        else {
            if (LLMAX / heal_point[i] < now) now = LLMAX;
            else now *= heal_point[i];
        }
        if (now > total_damage) return true;
    }
    
    return true;
}


long long binary_search(vector<long long>& damages, vector<long long>& heal_point, vector<char>& magic, long long total_damage)
{
    long long start = 0, end = LLMAX;
    
    while (start <= end) {
        long long mid = (start + end) / 2;
        bool check = is_complete(damages, heal_point, magic, mid, total_damage);
        if (check) end = mid - 1;
        else start = mid + 1;
    }
    
    return start;
    
}



int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> T;
    for (int t=0; t<T; ++t) {
        cin >> N;
        vector<long long> damages(N), heal_point(N);
        vector<char> magic(N);
        long long total_damage = 0;
        for (int i=0; i<N; ++i) {
            cin >> damages[i];
            total_damage += damages[i];
        }
        for (int i=0; i<N; ++i) {
            cin >> magic[i];
        }
        for (int i=0; i<N; ++i) {
            cin >> heal_point[i];
        }
        
        cout << binary_search(damages, heal_point, magic, total_damage) << "\n";
        
    }
    
    return 0;
}
