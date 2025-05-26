#include <iostream>
#include <vector>
#include <set>
#include <unordered_map>

using namespace std;

int N;
set<int> numbers;
unordered_map<int, int> num_cnt;

int meowmeow()
{
    int cnt = 1, previous = -1;
    num_cnt[-1] = num_cnt[0];
    
    for (int a : numbers) {
        if (a == previous + 1) {
            if (num_cnt[a] > 0 && num_cnt[a] <= 2 && num_cnt[previous] >= num_cnt[a]) {
                cnt *= num_cnt[previous];
            }
            else {
                return 0;
            }
            previous = a;
        }
        else {
            return 0;
        }
    }
    
    if (num_cnt[0] == 1) {
        cnt *= 2;
    }
    
    return cnt;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    int num;
    for (int i=0; i<N; ++i) {
        cin >> num;
        numbers.insert(num);
        num_cnt[num]++;
    }
    
    cout << meowmeow();

    return 0;
}
