/**
 유클리드 호재법 및 최대공약수, 최소공배수 를 구하는 규칙을 이용하여 문제를 풀자
 어떤 값이든 무조건 최대 공약수로 나누어지는 값일 것이기 때문에 최대 공약수의 배수로 미지수를 정하고
 브루트 포스를 하자! 단, 최대 공약수의 배수라고 할지라도 나오는 두개의 값의 최대 공약수가 주어진 최대 공약수라는
 보장이 없기 때문에 다시한번 두 값을 유클리드 호재법을 이용해 최대 공약수가 맞는지 확인한다.
 N * M 이 long long을 넘어가는 경우 때문에 더미값이 생성돼서 시간초과가 계속 발생했다....
 따라서 N의 개수로 나누어 계산해보았다 제발 맞아줘
 **/
#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;
int N, M;

bool euclidean(long long x, long long y) {
    int left_num = -1;
    while (true) {
        left_num = y % x;
        if (left_num == 0) {
            if (x == N) {
                return true;
            }
            else {
                return false;
            }
        }
        y = x;
        x = left_num;
    }
}

int main()
{
    cin >> N >> M;
    
    long long result = 200000001;
    long long one, two;
    
    int x = 1;
    
    while (true) {
        if (M % x == 0) {
            int tmp = (N * x) + (M / x);
            if (result > tmp) {
                if (euclidean(N * x, M / x)) {
                    result = tmp;
                    one = N * x;
                    two =  M / x;
                }
            }
            else {
                break;
            }
        }
        x++;
        if (x > sqrt(N * M)) {
            break;
        }
    }
    
    cout << one << " " << two; 

    return 0;
}
