// 같은 가격이면 더 높은걸 적어놓는게 좋다. 이걸 기반으로 해보자!
// 가격이 1원이면 50자리의 수가 나오며 이는 어떤 자료형으로도 감당이 불가능해보이니
// 문자열을 이용해서 하기로했다. 두 문자열의 대소를 가려줄 함수를 만들고, dp를 M의 크기만큼 선언하여
// 지불한 금액 중에서 가장 큰 번호를 기록한다.
// 1부터 M까지 순회하며, 현재 번호에서 추가로 번호를 산 후 그 가격에 기록된 번호보다 크다면 기록, 아니면 패스 하는 방식으로
// 문제를 풀었다.


#include <iostream>
#include <vector>
#include <string>

using namespace std;

int N, M;
vector<int> name_price(10);  


bool check_upper(string a, string b)
{
    int a_size = a.size(), b_size = b.size();
    if (a_size > b_size) return true;
    else if (a_size < b_size) return false;
    
    for (int i=0; i<a_size; ++i) {
        if (a[i] > b[i]) return true;
        else if (a[i] < b[i]) return false;
    }
    return false;
}


int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    vector<string> dp(51, "");
    cin >> N;
    for (int i=0; i<N; ++i) {
        cin >> name_price[i];
        char tmp = i + '0';
        if (dp[name_price[i]] == "") {
            dp[name_price[i]] += tmp;
        }
        else {
            string tt = "";
            tt += tmp;
            if (!check_upper(dp[name_price[i]], tt)) {
                dp[name_price[i]] = tt;
            }
        }
    }
    cin >> M;
    
    for (int i=1; i<=M; ++i) {
        if (dp[i] != "" && dp[i] != "0") {
            for (int j=0; j<N; ++j) {
                if (i + name_price[j] <= M) {
                    char tmp_s = j + '0';
                    string next_s = dp[i] + tmp_s;
                    if (check_upper(next_s, dp[i + name_price[j]])) {
                        dp[i + name_price[j]] = next_s;
                    }
                }
            }
        }
    }
    string best_num = "";
    for (int i=1; i<=M; ++i) {
        if (!check_upper(best_num, dp[i])) {
            best_num = dp[i];
        }
    }
    
    cout << best_num;

    return 0;
}
