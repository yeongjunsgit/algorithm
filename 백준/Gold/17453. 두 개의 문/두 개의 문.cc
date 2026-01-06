#include <iostream>
#include <vector>
#include <bitset>

using namespace std;

int N, M;
vector<bitset<100> > door_switch(101);
vector<vector<int> > plus_switch(101), minus_switch(101);
vector<int> plus_size(101, -1), minus_size(101, -1);

void combi(bitset<100> now, int idx, vector<int> passed)
{
    int front_door = now.count();
    int now_year = front_door - (N - front_door);
    if (now_year >= 0 && plus_size[now_year] == -1) {
        plus_switch[now_year] = passed;
        plus_size[now_year] = passed.size();
    } 
    else if (now_year < 0 && minus_size[now_year * -1] == -1) {
        minus_switch[now_year * -1] = passed;
        minus_size[now_year * -1] = passed.size();
    }

    for (int i=idx; i<=M; ++i) {
        bitset<100> next = now ^ door_switch[i];
        vector<int> next_passed = passed;
        next_passed.push_back(i);
        combi(next, i+1, next_passed);
    }
    
    return;
}


int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    string data;
    cin >> N >> M >> data;
    bitset<100> base(data);
    for (int m=1; m<=M; ++m) {
        cin >> data;
        bitset<100> tmp(data);
        door_switch[m] = tmp;
    }
    
    combi(base, 1, {});
    
    for (int i=N; i>=1; --i) {
        cout << minus_size[i] << " ";
        for (int a : minus_switch[i]) {
            cout << a << " ";
        }
        cout << "\n";
    }
    for (int i=0; i<=N; ++i) {
        cout << plus_size[i] << " ";
        for (int a : plus_switch[i]) {
            cout << a << " ";
        }
        cout << "\n";
    }

    return 0;
}
