#include <iostream>
#include <sstream>
#include <vector>
#include <unordered_map>

using namespace std;

int N, M;
int result = 0;
vector<int> my_root(1000001, 0);

int find_root(int x) {
    if (my_root[x] == x) {
        return x;
    }
    return my_root[x] = find_root(find_root(my_root[x]));
}

void union_root(int a, int b) {
    int root_a = find_root(a);
    int root_b = find_root(b);
    
    if (root_a != root_b) {
        my_root[root_b] = root_a;
    }
}

void match_root(vector<int>& study_progress, int now) {
    for (int i=1; i<N; ++i) {
        if (find_root(now) != find_root(study_progress[i])) {
            result += 1;
        }
        now = study_progress[i];
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> N >> M;
    
    for (int i=1; i<=N; ++i) {
        my_root[i] = i;
    }
    
    int s, e;
    
    for (int i=0; i<M; ++i) {
        cin >> s >> e;
        union_root(s, e);
    }
    
    cin.ignore();
    
    vector<int> study_progress;
    
    string data;
    getline(cin, data);
    istringstream iss(data);
    int num;
    
    while (iss >> num) {
        study_progress.push_back(num);
    }
    
    match_root(study_progress, study_progress[0]);
    
    cout << result;

    return 0;
}
