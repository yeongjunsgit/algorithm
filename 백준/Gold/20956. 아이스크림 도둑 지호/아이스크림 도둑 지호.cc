#include <iostream>
#include <vector>
#include <queue>

#define pll pair<int, int>
using namespace std;

int N, M;
vector<int> ice_cream;

struct left_Compare
{
    bool operator()(const pll& a, const pll& b) {
        if (a.first == b.first) {
            return a.second > b.second;
        }
        return a.first < b.first;
    }
};

struct right_Compare
{
    bool operator()(const pll& a, const pll& b) {
        if (a.first == b.first) {
            return a.second < b.second;
        }
        return a.first < b.first;
    }
};

priority_queue<pll, vector<pll>, left_Compare > left_ice;
priority_queue<pll, vector<pll>, right_Compare> right_ice;
vector<bool> used;


void eat_icecream()
{
    int is_left = 0;
    
    for (int i=0; i<M; ++i) {
        if (is_left == 0) {
            while (used[left_ice.top().second] == true) {
                left_ice.pop();
            }
            pll now = left_ice.top();
            left_ice.pop();

            int now_ice = now.first;
            int now_idx = now.second;
            
            used[now_idx] = true;
            
            if (now_ice % 7 == 0) {
                is_left++;
                is_left %= 2;
            }
            
            cout << now_idx << "\n";
        }
        else {
            while (used[right_ice.top().second] == true) {
                right_ice.pop();
            }
            pll now = right_ice.top();
            right_ice.pop();
            
            int now_ice = now.first;
            int now_idx = now.second;
            
            used[now_idx] = true;
            
            if (now_ice % 7 == 0) {
                is_left++;
                is_left %= 2;
            }
            
            cout << now_idx << "\n";
        }
        
    }
    
    return;
}


int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;
    ice_cream.resize(N+1, 0);
    used.resize(N+1, false);
    
    int num;
    for (int i=1; i<=N; ++i) {
        cin >> num;
        ice_cream[i] = num;
        left_ice.push({num, i});
        right_ice.push({num, i});
    }
    
    eat_icecream();

    return 0;
}
