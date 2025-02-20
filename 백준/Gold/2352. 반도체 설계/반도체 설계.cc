#include <iostream>
#include <vector>
#include <algorithm>

#define pll pair<int, int>

using namespace std;

int N;
vector<pll> lines;
vector<int> left_LIS;

int binary_check(int now)
{
    int start = 0;
    int end = left_LIS.size() - 1;
    
    while (start <= end) {
        int mid = (start + end) / 2;
        
        if (now <= left_LIS[mid]) {
            end = mid - 1;
        }
        else {
            start = mid + 1;
        }
    }
    
    return start;
}


void make_lines()
{
    int left_size = 0;
    for (int i=0; i<N; ++i) {
        pll now = lines[i];
        if (left_size == 0) {
            left_LIS.push_back(now.second);
            left_size++;
        }
        else {
            int idx = binary_check(now.second);
            if (idx == left_size) {
                left_LIS.push_back(now.second);
                left_size++;
            }
            else {
                left_LIS[idx] = now.second;
            }
        }
    }
    
    cout << left_size;
    
    return;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    cin >> N;
    int num;
    
    for (int i=1; i<=N; ++i) {
        cin >> num;
        lines.push_back({num, i});
    }
    
    sort(lines.begin(), lines.end());
    
    make_lines();

    return 0;
}