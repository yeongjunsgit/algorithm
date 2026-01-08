// 학교까지 도달하기 위해 필요한 최소의 킥보드 용량을 알아야 한다.
// 최적의 킥보드 용량을 알아내는데 이분탐색을 사용하면 어떨까? 1~L까지의 구간에서 이분탐색을 하고
// 끝까지 도달할 수 있는지 여부를 판단하자! 최대 20만이라서 체크를 해도 많은 시도로 나오진 않을것같다!

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// L = 학교까지의 거리, N = 충전소의 개수, K = 최대로 방문 가능한 횟수
int L, N, K;
vector<int> charger_loca;

// 현재 탐색중인 킥보드의 용량이 학교까지 도달하는게 가능한지 여부를 판단하는 함수
// 실패하는 경우는 2가지이다. 충전소와 충전소 사이에 도달을 못할 경우, 충전소를 K번 이상 이용해야 하는 경우
bool is_arrived(int loca)
{
    int now = 0, cnt = 0;
    
    for (int i=0; i<N; ++i) {
        if (cnt > K) return false;
        if (charger_loca[i] <= now + loca && charger_loca[i+1] > now + loca) {
            now = charger_loca[i];
            cnt++;
        }
        else if (charger_loca[i] > now + loca) return false;
    }
    
    if (cnt <= K && now + loca >= L) return true;
    else return false;
    
}


// 이분탐색을 실행할 함수
int binary_check()
{
    int start = 0, end = L;
    
    while (start <= end) {
        int mid = (start + end) / 2;
        bool is_ok = is_arrived(mid);
        
        if (is_ok) end = mid - 1;
        else start = mid + 1;
    }
    
    return start;
    
}


int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> L >> N >> K;
    charger_loca.resize(N);
    for (int i=0; i<N; ++i) {
        cin >> charger_loca[i];
    }
    
    sort(charger_loca.begin(), charger_loca.end(), less());
    charger_loca.push_back(L);
    
    cout << binary_check();

    return 0;
}
