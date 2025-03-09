#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    cin >> N;
    int num;
    vector<int> rope;
    
    for (int i=0; i<N; ++i) {
        cin >> num;
        rope.push_back(num);
    }
    
    int result = 0, cnt = 0;
    sort(rope.begin(), rope.end(), greater<int>());
    
    for (int a : rope) {
        cnt++;
        int tmp = cnt * a;
        if (tmp > result) {
            result = tmp;
        }
    }
    
    cout << result;

    return 0;
}
