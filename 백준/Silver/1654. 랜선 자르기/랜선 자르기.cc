#include <iostream>
#include <vector>

using namespace std;

int N, K;
vector<int> lan_lines;

int cut_lan(long long lan_length)
{
    int cnt = 0;
    for (int l : lan_lines) {
        int tmp = l / lan_length;
        cnt += tmp;
    }
    
    return cnt;
}

int max_lan()
{
    long long start = 1;
    long long end = 1LL << 32 - 1;
    
    while (start <= end) {
        long long mid = (start + end) / 2;
        int now_cnt = cut_lan(mid);
        
        if (now_cnt < K) {
            end = mid - 1;
        }
        else {
            start = mid + 1;
        }
        
    }
    
    return end;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    cin >> N >> K;
    
    int num;
    for (int i=0; i<N; ++i) {
        cin >> num;
        lan_lines.push_back(num);
    }
    
    cout << max_lan();

    return 0;
}
