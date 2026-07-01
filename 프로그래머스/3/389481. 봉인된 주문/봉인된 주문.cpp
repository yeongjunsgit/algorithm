/*
특정 알파벳을 빼고 난 후, 몇 번째 값이 무엇인가? 를 찾아야한다.
모든 주문은 사전순으로 가장 빠른 것이 앞으로 온다.
즉, 현재 빼려는 값이 현재 구하려는 값보다 앞인지 뒤인지를 판단하는게 중요해보인다.
문자열의 대소를 구분하는 것은 어떨까? 어차피 최대 길이는 11자리이니까 비교 연산은 끽해야 22정도이다.
bans의 길이도 30만 정도이니 비교 연산은 30만번 이루어질 예정.
그렇다면 먼저, n번째 값의 알파벳이 무엇인지 연산할 수 있어야한다.
생각해보자 알파벳의 개수는 총 26개이다. 이후 26*26, 26*26*26 순으로 늘어난다. 이를 통해서 현재 n의 값이 몇자리인지 알 수 있다.
먼저 범위를 통해, n의 값이 어디쯤인지 확인하고 이때부터 30만번의 비교연산을 통해 1개씩 줄여나가는 방식으로 진행하는 것이다.
하지만 몇번째 자리인지 확인하는건 ok 이지만 자릿수가 너무 많이 늘어났을때, 정확한 알파벳을 찾으려고 하는게 어렵지 않을까...?
1. 어차피 정확한 알파벳은 찾아야한다. (이건 확실히 해야함)
- 그럼 여기서 2개의 경우로 나뉜다.
    1) n을 숫자로 바꾼다.
    2) bans의 알파벳들을 숫자로 바꾼다.
2)의 경우는 진짜 답도 없다 지금 n 1개만 바꾸는 것도 어려워 보이는데... 그냥 무조건 n을 바꿔야함

가장 간단한 방법은 아스키 코드를 이용하는 것으로 보인다.
27 = 26^1보다 크다. 그렇다면 27 % 26 = 1 을 진행하면 1만 남는다 = "aa"
53 = 53 % 26 = 1, 52 / 26 = 2 = 2 1 = "ba" 이런식으로 조합하면 될 것 같다
어차피 최대 자릿수는 11자리니까 vector를 11자리로 만들어서 해당하는 부분을 만들면 될 것 같다.
ㄱㄱ

실시간 갱신이 필요하다...

*/

#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;


struct Compare
{
    bool operator()(const string& a, const string& b) {
        int a_size = a.size(), b_size = b.size();
        if (a_size != b_size) return a_size < b_size;
        return a < b;
    }
};



// n을 string으로 바꾸는 함수
string n_to_string(long long n)
{
    long long cnt = 1;
    int len = 1;

    for (int i = 1; i <= 11; ++i) {
        cnt *= 26;

        if (n > cnt) {
            n -= cnt;
        } else {
            len = i;
            break;
        }
    }

    // 현재 길이 안에서 0-based 순번
    long long idx = n - 1;

    string result = "";

    long long power = 1;
    for (int i = 1; i < len; ++i) {
        power *= 26;
    }

    for (int i = 0; i < len; ++i) {
        int order = idx / power;
        result += char('a' + order);
        idx %= power;

        if (power > 1) power /= 26;
    }

    return result;
}


long long string_to_num(string s)
{
    long long rank = 0;
    long long power = 1;

    // 1~10 length prefix sum 고려해야 함
    power = 1;

    for (int len = 1; len < s.size(); len++) {
        power *= 26;
        rank += power;
    }

    // 현재 길이 내 사전순 rank
    power = 1;
    for (int i = 1; i < s.size(); i++) power *= 26;

    for (char c : s) {
        rank += (c - 'a') * power;
        power /= 26;
    }

    return rank + 1;
}



string solution(long long n, vector<string> bans) {
    string answer = "";
    sort(bans.begin(), bans.end(), Compare());
    string start = n_to_string(n);
    int now_len = start.size();

    for (string s : bans) {
        long long num_bans = string_to_num(s);
        if (num_bans <= n) n++;
    }
    
    answer = n_to_string(n);
    
    return answer;
}