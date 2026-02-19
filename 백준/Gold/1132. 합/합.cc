#include <iostream>
#include <vector>
#include <cmath>
#include <map>
#include <algorithm>

using namespace std;

struct Compare
{
    bool operator()(const pair<char, long long>& a, const pair<char, long long>& b) {
        return a.second > b.second;
    }
};


int N;
map<char, long long> best_alpha;
vector<string> sentences(50);
map<char, int> is_front = {{'A', 0}, {'B', 0}, {'C', 0}, {'D', 0}, {'E', 0}, {'F', 0}, {'G', 0}, {'H', 0}, {'I', 0}, {'J', 0} };
map<char, int> alpha_to_num = {{'A', -1}, {'B', -1}, {'C', -1}, {'D', -1}, {'E', -1}, {'F', -1}, {'G', -1}, {'H', -1}, {'I', -1}, {'J', -1} };

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    for (int i=0; i<N; ++i) {
        cin >> sentences[i];
        // 현재 숫자의 길이를 찾는다.
        int now_size = sentences[i].size();
        // 현재 가장 앞의 알파벳을 체크한다 이는, 0을 사용할 수 없는 알파벳이 된다.
        is_front[sentences[i][0]] = 1;
        // 현재 자신의 숫자위치의 크기만큼 해당 위치 알파벳에 가중치를 더한다. 이는 어떤 알파벳이 큰 숫자를 가지게 될지 정하는 기준이 된다.
        for (int j=now_size - 1; j>=0; --j) {
            long long now_power = pow(10, j);
            // cout << now_power << " ";
            best_alpha[sentences[i][now_size - j - 1]] += now_power;
            // cout << sentences[i][now_size - j - 1] << " " << best_alpha[sentences[i][now_size - j - 1]] << "\n";
        }
    }
    
    // 알파벳의 가중치를 기준으로 정렬한다.
    vector<pair<char, long long> > alpha_powers(best_alpha.begin(), best_alpha.end());
    sort(alpha_powers.begin(), alpha_powers.end(), Compare());
    
    // 0을 넣어야하는 상황이라면 0을 할당받을 알파벳을 찾는다.
    int M = alpha_powers.size();
    if (M == 10) {
        for (int i=M-1; i>=0; --i) {
            if (is_front[alpha_powers[i].first] == 0) {
                alpha_to_num[alpha_powers[i].first] = 0;
                break;
            }
        }
    }
    
    // 가장 큰 값부터 가장 큰 숫자를 할당한다.
    int num = 9;
    for (int i=0; i<M; ++i) {
        if (alpha_to_num[alpha_powers[i].first] == -1) {
            alpha_to_num[alpha_powers[i].first] = num;
            // cout << alpha_powers[i].first << " " << num << "\n";
            num--;
        }
    }
    // 모든 문자들을 숫자로 치환하여 합한다.
    long long result = 0;
    for (int i=0; i<N; ++i) {
        long long tmp = 0;
        int s_size = sentences[i].size();
        for (int j=0; j<s_size; ++j) {
            long long now = alpha_to_num[sentences[i][j]] * pow(10, s_size - j - 1);
            tmp += now;
        }
        result += tmp;
    }
    
    cout << result;
    
    return 0;
}

