#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M, K, Q;

vector<int> y_lines;
int max_x = 0;

bool check_ok(int paper_size)
{
    int idx = 0;
    int use_paper = 0;
    while (idx < Q && use_paper < K) {
        use_paper++;
        int now_size = y_lines[idx] + paper_size - 1;
        while (y_lines[idx] <= now_size && idx < Q) {
            idx++;
        }
    }
    
    if (idx == Q) {
        return true;
    }
    else {
        return false;
    }
}

void binary_catch()
{
    int start = max_x;
    int end = N;
    
    while (start <= end) {
        
        int mid = (start + end) / 2;
        
        bool is_ok = check_ok(mid);
        
        if (is_ok == true) {
            end = mid - 1;
        }
        else {
            start = mid + 1;
        }
    }
    
    cout << start;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> N >> M >> K >> Q;
    
    int s, e;
    for (int i=0; i<Q; ++i) {
        cin >> s >> e;
        y_lines.push_back(e);
        if (max_x < s) {
            max_x = s;
        }
    }
    
    sort(y_lines.begin(), y_lines.end(), less<int>());
    
    binary_catch();

    return 0;
}
