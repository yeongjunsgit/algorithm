#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, C, num;
vector<long long> numbers(31);
vector<vector<long long> > left_right(2);

void get_back_pack(int depth, int idx, int limit_idx, long long now, int left_or_right)
{
    if (now > C) return;
    left_right[left_or_right].push_back(now);
    if (depth == limit_idx) return;
    
    for (int i=idx; i<limit_idx; ++i) {
        get_back_pack(depth + 1, i + 1, limit_idx, now + numbers[i], left_or_right);
    }
    
    return;
}

int binary_check(long long now)
{
    int start = 0;
    int end = left_right[1].size() - 1;
    
    while (start <= end) {
        int mid = (start + end) / 2;
        
        if (left_right[1][mid] + now <= C) {
            start = mid + 1;
        }
        else {
            end = mid - 1;
        }
    }
    
    return start;
    
}


int match_lr()
{
    long long result = 0;
    int left_size = left_right[0].size();
    for (int i=0; i<left_size; ++i) {
        long long now = left_right[0][i];
        long long check_idx = binary_check(now);
        result += check_idx;
        
    }
    return result;
}


int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> C;
    for (int i=0; i<N; ++i) {
        cin >> numbers[i];
    }
    
    get_back_pack(0, 0, N / 2, 0, 0); get_back_pack(0, N / 2, N, 0, 1);
    
    sort(left_right[0].begin(), left_right[0].end(), less<int>());
    sort(left_right[1].begin(), left_right[1].end(), less<int>());
    
    cout << match_lr();

    return 0;
}
