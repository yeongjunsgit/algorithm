#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    // N = 학생의 수, M = 색상의 수
    long long N, M;
    cin >> N >> M;
    
    // 가장 많은 보석의 종류가 end 값이 됨, 보석은 무조건 1개 이상이니까 start는 1부터
    long long start = 1;
    long long end = 0;
    long long result = 0;
    
    
    // 보석의 개수를 받으면서 가장 큰 값은 end에 기록
    vector<long long> jewel(M+1, 0);
    long long color;
    for (int i=0; i<M; ++i) {
        cin >> color;
        end = max(end, color);
        jewel[i] = color;
    }
    
    // 이분탐색 시작
    while (start <= end) {
        long long mid = (start + end) / 2;
        // 현재 mid 값을 질투심 값으로 봤을때 몇명의 사람이 보석을 가지는지를 기록할 get_jewel 선언
        long long get_jewel = 0;
        
        // 모든 보석의 개수를 순회
        for (int i=0; i<M; ++i) {
            // 만약 현재 설정한 질투심이 해당 보석의 개수보다 크다면?
            if (mid >= jewel[i]) {
                // 한 사람이 해당 보석을 다 가짐 (1명만 늘어남)
                get_jewel += 1;
            }
            // 만약 현재 설정한 질투심보다 해당 보석의 개수가 많다면?
            else {
                // 해당 보석의 개수가 질투심에 딱 맞아 떨어지게 나뉜다면 나눈 몫 만큼 사람수 증가
                if (jewel[i] % mid == 0) {
                    get_jewel += jewel[i] / mid;
                }
                // 해당 보석의 개수가 질투심으로 나눈값이 딱 맞아 떨어지지 않는다면 누군가는 나머지를 받을 테니
                // 나눈 몫 + 1명 증가
                else {
                    get_jewel += jewel[i] / mid + 1;
                }
            }
        }
        // 만약 보석을 받은 사람이 현재 사람수 보다 많다면 질투심 크기를 늘린다.
        if (N < get_jewel) {
            start = mid + 1;
        }
        // 만약 보석을 받은 사람이 현재 사람수 보다 적다면 못받는 사람이 발생해도 괜찮으니까 현재 질투심을
        // 기록해두고 질투심 값을 내려봄
        else {
            result = mid;
            end = mid - 1;
        }
    }
    
    cout << result;

    return 0;
}
