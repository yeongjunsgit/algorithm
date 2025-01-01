#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N, num;
    
    cin >> N;
    vector<int> stacker, target;
    vector<char> result;
    for (int i=0; i<N; ++i) {
        cin >> num;
        target.push_back(num);
    }
    
    int now = 1;
    int idx = 0;
    bool is_ok = true;
    
    while (idx != N) {
        if (now <= target[idx]) {
            while (now != target[idx]) {
                stacker.push_back(now);
                result.push_back('+');
                now++;
            }
            now++;
            result.push_back('+');
            result.push_back('-');
            idx++;
        }
        else {
            if (stacker.back() == target[idx]) {
                stacker.pop_back();
                result.push_back('-');
                idx++;
            }
            else {
                is_ok = false;
                break;
            }
        }
    }
    
    if (is_ok == true) {
        int M = result.size();
        for (int i=0; i<M; ++i) {
            cout << result[i] << "\n";
        }
    }
    else {
        cout << "NO";
    }

    return 0;
}
