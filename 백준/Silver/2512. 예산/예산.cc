#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<int> numbers;
int result = 0;

int divide_money(int now)
{
    int cnt = 0;
    for (int a : numbers) {
        cnt += min(a, now);
    }
    
    return cnt;
}

int check_binary(int max_money)
{
    int start = 1;
    int end = max_money;
    
    while (start <= end) {
        int mid = (start + end) / 2;
        int tmp = divide_money(mid);
        
        if (tmp > M) {
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
    cin >> N;
    int max_money = 0;
    numbers.resize(N);
    for (int i=0; i<N; ++i) {
        cin >> numbers[i];
        max_money = max(max_money, numbers[i]);
    }
    
    cin >> M;
    
    cout << check_binary(max_money);
    

    return 0;
}
