#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

int binary_check(vector<int>& bp, int end_point, int base)
{
    int start = 0;
    int end = end_point;
    
    while (start < end) {
        int mid = (start + end) / 2;
        
        if (bp[mid] > base) {
            start = mid + 1;
        }
        else {
            end = mid;
        }
    }
    
    return start;
}

int main()
{
    int N;
    cin >> N;
    cin.ignore();
    
    string data;
    int num;
    getline(cin, data);
    
    vector<int> soilders;
    vector<int> bp(N, 0);
    int bp_idx = 0;
    int cnt = 0;
    
    istringstream iss(data);
    
    while (iss >> num) {
        soilders.push_back(num);

    }
    bp[0] = soilders[0];
    
    for (int i=1; i<N; ++i) {
        if (bp[bp_idx] > soilders[i]) {
            bp[bp_idx + 1] = soilders[i];
            bp_idx++;
        }
        else {
            int idx = binary_check(bp, bp_idx, soilders[i]);
            bp[idx] = soilders[i];
            cnt++;
        }
    }
    
    cout << cnt;
    
    return 0;
}
