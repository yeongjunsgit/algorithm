#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<int> moneys;
int max_power = 0;

int is_ok(int get_money)
{
    int repeat_time = 0;
    int now_money = 0;
    
    for (int a : moneys) {
        if (a > get_money) {
            return M + 1;
        }
        if (now_money < a) {
            now_money = get_money;
            repeat_time++;
        }
        now_money -= a;
    }
    
    return repeat_time;
}

void binary_check()
{
    int start = 0;
    int end = max_power;
    
    while (start <= end) {
        int mid = (start + end) / 2;
        
        int tmp = is_ok(mid);
        
        if (tmp <= M) {
            end = mid - 1;
        }
        else {
            start = mid + 1;
        }
    }
    
    cout << start;
    
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> N >> M;
    int num;
    
    for (int i=0; i<N; ++i) {
        cin >> num;
        moneys.push_back(num);
        max_power += num;
    }
    
    binary_check();

    return 0;
}
