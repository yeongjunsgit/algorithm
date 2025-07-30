#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

long long MOD = 1e9 + 7;
long long fact[50001];    // 팩토리얼 값 저장 (최대 N 50000)
long long invFact[50001]; // 팩토리얼의 모듈러 역원 저장

// a^b % MOD 계산 함수
long long power(long long base, long long exp) {
    long long res = 1;
    base %= MOD;
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * base) % MOD;
        base = (base * base) % MOD;
        exp /= 2;
    }
    return res;
}

// 모듈러 역원 계산 함수 (페르마의 소정리 이용)
long long modInverse(long long n) {
    return power(n, MOD - 2);
}

// 팩토리얼 및 역팩토리얼 전처리 함수
void precompute_factorials(int n) {
    fact[0] = 1;
    invFact[0] = 1; // 0! = 1, 1의 역원은 1
    for (int i = 1; i <= n; i++) {
        fact[i] = (fact[i - 1] * i) % MOD;
        invFact[i] = modInverse(fact[i]);
    }
}

// nCr % MOD 계산 함수
long long nCr_mod_p(int n, int r) {
    if (r < 0 || r > n) return 0;
    // nCr = n! / (r! * (n-r)!)
    // nCr = n! * (r!)^(-1) * ((n-r)!)^(-1) (mod p)
    return (((fact[n] * invFact[r]) % MOD) * invFact[n - r]) % MOD;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int N;
    cin >> N;

    // 최대 N까지 팩토리얼 및 역팩토리얼 전처리
    // 제한이 50000이므로 50000까지 전처리
    precompute_factorials(N);

    long long total_patterns = 0;

    // N에 따른 정방향 키의 개수 결정
    int num_forward_keys;
    if (N <= 5) {
        total_patterns = 1;
        for (int i=0; i<N; ++i) {
            total_patterns *= 4;
        }
    }
    else {
        num_forward_keys = 8;
        // 역방향 키 모드가 랜덤일 때, 역방향 키는 키 노트에 최대 6개까지 등장
        // 즉, 역방향 키의 개수 'c'는 0개부터 6개까지 가능
        for (int c = 0; c <= 6; ++c) {
            // 1. N개의 키 노트 중 c개를 역방향 키로 선택하는 경우의 수: C(N, c)
            long long combinations_N_c = nCr_mod_p(N, c);
    
            // 2. 선택된 c개의 역방향 키 각각이 가질 수 있는 종류의 수: 8^c (8개의 정방향 키에 대한 역방향 키가 존재)
            long long patterns_for_c_inverse_keys = power(8, c);
    
            // 3. 나머지 (N - c)개의 키 노트는 정방향 키. 이들이 가질 수 있는 종류의 수: num_forward_keys^(N-c)
            long long patterns_for_remaining_forward_keys = power(num_forward_keys, N - c);
    
            // 현재 c에 대한 총 패턴 수: C(N, c) * 8^c * num_forward_keys^(N-c)
            long long current_c_patterns = (combinations_N_c * patterns_for_c_inverse_keys) % MOD;
            current_c_patterns = (current_c_patterns * patterns_for_remaining_forward_keys) % MOD;
    
            // 모든 c에 대한 패턴 수를 합산
            total_patterns = (total_patterns + current_c_patterns) % MOD;
        }
    }
    cout << total_patterns;

    return 0;
}