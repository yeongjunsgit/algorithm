#include <iostream>
#include <sstream>
#include <vector>
#include <queue>

using namespace std;

int N;
vector<vector<int> > hate_people;
priority_queue<int, vector<int>, greater<int> > red_team;
priority_queue<int, vector<int>, greater<int> > blue_team;
vector<int> visited;

void bfs(int target)
{
    queue<int> que;
    que.push(target);
    visited[target] = 1;
    
    while (!que.empty()) {
        int now = que.front();
        que.pop();
        
        for (int a : hate_people[now]) {
            if (visited[a] == 0) {
                que.push(a);
                if (visited[now] == 1) {
                    visited[a] = 2;
                }
                else {
                    visited[a] = 1;
                }
            }
        }
    }
    
    return;
}

void result_p()
{
    int red = 0, blue = 0;
    
    for (int i=1; i<=N; ++i) {
        if (visited[i] == 1) {
            red++;
            red_team.push(i);
        }
        else {
            blue++;
            blue_team.push(i);
        }
    }
    
    if (blue == 0) {
        blue++;
        int tmp = red_team.top();
        red_team.pop();
        blue_team.push(tmp);
    }
    
    cout << red << "\n";
    while (!red_team.empty()) {
        cout << red_team.top() << " ";
        red_team.pop();
    }
    cout << "\n";
    cout << blue << "\n";
    while (!blue_team.empty()) {
        cout << blue_team.top() << " ";
        blue_team.pop();
    }
    
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    cin.ignore();
    visited.resize(N+1, 0);

    string data;
    int num;
    hate_people.push_back({0});
    
    for (int i=1; i<=N; ++i) {
        getline(cin, data);
        istringstream iss(data);
        int idx = 0;
        vector<int> one_line;

        while (iss >> num) {
            if (idx == 0) {
                idx++;
            }
            else {
                one_line.push_back(num);
            }
        }
        hate_people.push_back(one_line);
    }
    
    for (int i=1; i<=N; ++i) {
        if (visited[i] == 0) {
            bfs(i);
        }
    }

    result_p();

    return 0;
}
