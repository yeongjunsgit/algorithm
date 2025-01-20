#include <iostream>
#include <vector>

using namespace std;

int N, num;
int result = 0;
vector<int> lines;
vector<int> LIS;

int binary_check(int x)
{
    int start = 0;
    int end = LIS.size() - 1;
    
    while (start <= end) {
        int mid = (start + end) / 2;
        
        if (LIS[mid] <= x) {
            start = mid + 1;
        }
        else {
            end = mid - 1;
        }
    }
    
    return start;
}

void make_sort()
{
    LIS.push_back(lines[0]);
    
    for (int i=1; i<N; ++i) {
        int idx = binary_check(lines[i]);
        
        if (idx > LIS.size() - 1) {
            LIS.push_back(lines[i]);
        }
        else {
            LIS[idx] = lines[i];
        }
    }
    
    cout << N - LIS.size();
    
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> N;
    
    for (int i=0; i<N; ++i) {
        cin >> num;
        lines.push_back(num);
    }
    
    make_sort();

    return 0;
}
