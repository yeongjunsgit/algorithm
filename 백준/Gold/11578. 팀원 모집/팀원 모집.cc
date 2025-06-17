#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<vector<int> > can_solve(10);
int result = 11;
vector<int> solve_people(11, 0), visited(10, 0);


bool is_over()
{
    for (int i=1; i<=N; ++i) {
        if (!solve_people[i]) return false;
    }
    return true;
}


void match_team(int depth, int idx)
{
    if (is_over()) {
        result = min(result, depth);
        return;
    }
    
    if (depth + 1 < result) {
        for (int i=idx; i<=M; ++i) {
            if (visited[i] == 0) {
                visited[i] = 1;
                for (int a : can_solve[i]) {
                    solve_people[a]++;
                }
                match_team(depth + 1, i + 1);
                for (int a : can_solve[i]) {
                    solve_people[a]--;
                }
                visited[i] = 0;
            }
        }
    }
    
    return;
}


int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;
    int num, solve;
    for (int i=0; i<M; ++i) {
        cin >> num;
        for (int j=0; j<num; ++j) {
            cin >> solve;
            can_solve[i].push_back(solve);
        }
    }
    
    match_team(0, 0);
    
    if (result == 11) cout << -1;
    else cout << result;

    return 0;
}
