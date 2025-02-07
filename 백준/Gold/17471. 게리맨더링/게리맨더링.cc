#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <numeric>
#include <algorithm>

using namespace std;

int N;
vector<int> people;
int result = 1001;
int full_power = 0;
vector<vector<int> > graph;

void check_power(vector<int> now)
{
    vector<int> visited(N+1, 0);
    queue<int> que;
    que.push(now[0]);
    visited[now[0]] = 1;
    int passed = 1, lefted = 1;
    
    while (!que.empty()) {
        int now_node = que.front();
        que.pop();
        
        for (int a : graph[now_node]) {
            if (visited[a] == 0 && find(now.begin(), now.end(), a) != now.end()) {
                visited[a] = 1;
                que.push(a);
                passed++;
            }
        }
    }
    
    if (passed != now.size()) {
        return;
    }
    
    for (int i=1; i<=N; ++i) {
        if (visited[i] != 1) {
            que.push(i);
            visited[i] = 2;
            break;
        }
    }
    
    while (!que.empty()) {
        int now_node = que.front();
        que.pop();
        
        for (int a : graph[now_node]) {
            if (visited[a] == 0) {
                visited[a] = 2;
                que.push(a);
                lefted++;
            }
        }
    }

    if (N - lefted == passed) {
        int now_sum = 0;
        for (int a : now) {
            now_sum += people[a];
        }
        int tmp = abs(full_power - (now_sum * 2));
        if (tmp < result) {
            result = tmp;
        }

    }
    
    return;
}

void combi(vector<int> now, int depth, int idx)
{
    if (depth > 0) {
        check_power(now);
    }
    else if (depth == N) {
        return;
    }
    
    for (int i=idx; i<=N; ++i) {
        now.push_back(i);
        combi(now, depth + 1, i+1);
        now.pop_back();
    }
    
    return;
}


int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    cin >> N;
    people.resize(N+1, 0);
    graph.resize(N+1);
    int num, liner;
    for (int i=1; i<=N; ++i) {
        cin >> num;
        people[i] = num;
        full_power += num;
    }
    
    for (int i=1; i<=N; ++i) {
        cin >> num;
        for (int j=0; j<num; ++j) {
            cin >> liner;
            graph[i].push_back(liner);
        }
    }
    
    vector<int> now;
    combi(now, 0, 1);
    
    if (result != 1001) {
        cout << result;
    }
    else {
        cout << -1;
    }

    return 0;
}
