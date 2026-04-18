#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<int> cookies(1000000);

bool can_make(int now)
{
    int cnt = 0;
    for (int i=0; i<M; ++i) {
        cnt += cookies[i] / now;
    }
    
    if (cnt >= N) return true;
    else return false;
}


void binary_check()
{
    int start = 1, end = 1000000000;
    
    while (start <= end) {
        int mid = (start + end) / 2;
        
        bool check = can_make(mid);
        
        if (check) start = mid + 1;
        else end = mid - 1;
        
    }
    
    cout << end;
    
    return;
}


int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;
    for (int i=0; i<M; ++i) {
        cin >> cookies[i];
    }
    
    binary_check();

    return 0;
}
