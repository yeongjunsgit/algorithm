// 처음 문제를 봤을때는 단순히 그리디하게 첫번째에서 시작하는 단어를 기준으로 맞추기, 뒤에서 K개의 글자를 합친 단어를 기준으로 맞추기
// 두가지만 보면 문제를 풀 수 있지 않을까? 했으나 이는 그리디함이 보장되지 않아 불가능 하였다. 그래서 재귀를 이용해 브루트포스를 했더니
// 간단한 백트래킹을 해도 2^50만큼 횟수가 나와서 시간초과가 나서 문제를 틀렸다... 다방면으로 생각해도 답이 나지 않아 검색을 했더니
// 이는 유니온파인드를 이용하여 매칭시켜야하는 그룹을 구하고 이 그룹들 안에서 가장 많은 알파벳을 제외한 나머지 개수들 만큼 변경해주면 된다는 얘기였다.
// 이렇게 하면 그리디 하게 할때 이전에 바꾼 알파벳이 뒤에서 영향을 끼치는 경우까지 관리가 가능하고 브루트포스처럼 많은 연산이 필요하지도 않았다!
// 매우 획기적인 아이디어에 감탄해 바로 코드를 작성하였다. 아직 더 많은 문제를 풀어야하는 것 같다...


#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int N, M;
string previous_password;
vector<int> parents(50);
vector<vector<char> > union_group(50);


int find_root(int x)
{
    if (parents[x] == x) return x;
    return parents[x] = find_root(parents[x]);
}


void union_root(int x, int y)
{
    int r_x = find_root(x);
    int r_y = find_root(y);
    
    parents[r_y] = parents[r_x];
    
    return;
}


int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> previous_password >> N;
    M = previous_password.size();
    int result = 0;
    // 각 idx의 부모를 초기화
    for (int i=0; i<M; ++i) {
        parents[i] = i;
    }
    // 같아야하는 idx들을 union을 통해 하나의 그룹으로 만듬
    for (int i=0; i<N; ++i) {
        union_root(0 + i, M - N + i);
    }
    // 그룹안에 자신의 알파벳을 넣음
    for (int i=0; i<M; ++i) {
        union_group[find_root(i)].push_back(previous_password[i]);
    }
    // 그룹 안에서 가장 많은 알파벳을 기준으로 나머지 알파벳들을 변환해야하므로 해당 개수들을 구한다.
    for (int i=0; i<M; ++i) {
        if (union_group[i].size() > 0) {
            unordered_map<char, int> check_map;
            int best_change = 0;
            for (char c : union_group[i]) {
                check_map[c]++;
            }
            for (auto a : check_map) {
                best_change = max(best_change, a.second);
            }
            result += union_group[i].size() - best_change;
        }
    }
    
    cout << result;
    
    return 0;
}

