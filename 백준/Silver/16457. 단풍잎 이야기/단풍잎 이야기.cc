#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

int N, M, K;
vector<vector<int>> quests;
vector<bool> now_key(21, false);
int result = 0;

void check_quest()
{
    int cnt = 0;
    for (int i=0; i<M; ++i) {
        bool is_ok = true;
        for (int a : quests[i]) {
            if (now_key[a] == false) {
                is_ok = false;
                break;
            }
        }
        if (is_ok == true) {
            cnt += 1;
        }
    }
    
    if (result < cnt) {
        result = cnt;
    }
    return;
}

void select_key(int idx, int pick)
{
    if (idx == N) {
        check_quest();
        return;
    }
    else {
        for (int i=pick; i <= N * 2; ++i) {
            if (now_key[i] == false) {
                now_key[i] = true;
                select_key(idx + 1, i + 1);
                now_key[i] = false;
            }
        }
        return;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> N >> M >> K;
    cin.ignore();
    
    string data;
    int num;
    
    for (int i=0; i<M; ++i) {
        getline(cin, data);
        vector<int> one_line;
        istringstream iss(data);
        while(iss >> num) {
            one_line.push_back(num);
        }
        quests.push_back(one_line);
    }
    
    select_key(0, 1);
    
    cout << result;

    return 0;
}
