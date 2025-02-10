#include <iostream>
#include <vector>
#include <unordered_map>

#define dividivi 1000000007

using namespace std;

long long N;
unordered_map<long long, long long> mememo;

long long get_pibo(long long now)
{
    if (mememo.find(now) != mememo.end()) {
        return mememo[now];
    }
    
    long long tmp;
    if (now % 2 == 0) {
        tmp = (get_pibo(now / 2) % dividivi) * ((get_pibo(now / 2 + 1) % dividivi) + (get_pibo(now / 2 - 1) % dividivi));
        mememo[now] = tmp % dividivi;
    }
    else {
        long long front_tmp = (get_pibo((now + 1) / 2) % dividivi);
        long long end_tmp = (get_pibo((now - 1) / 2) % dividivi);
        tmp = (((front_tmp * front_tmp) % dividivi) + ((end_tmp * end_tmp) % dividivi)) % dividivi;
        mememo[now] = tmp;
    }
    
    return mememo[now];
}

int main()
{
    cin >> N;
    
    mememo[0] = 0;
    mememo[1] = mememo[2] = 1;
    
    cout << get_pibo(N);
    

    return 0;
}
