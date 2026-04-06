#include <iostream>
#include <vector>
#include <cmath>

#define pll pair<int, int>

using namespace std;

int N, M;
vector<int> left_bird(2001, 0), right_bird(2001, 0);
vector<pair<char, string> > birds(2001);

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;
    char bird_type;
    string sing_time;
    for (int i=1; i<=N; ++i) {
        cin >> bird_type >> sing_time;
        birds[i] = {bird_type, sing_time};
        if (bird_type == 'L') {
            for (int i=0; i<M; ++i) {
                left_bird[i+1] += sing_time[i] - '0';
            }
        }
        else {
            for (int i=0; i<M; ++i) {
                right_bird[i+1] += sing_time[i] - '0';
            }
        }
    }
    
    int best_bird = 0, best_power = 99999999;
    
    for (int i=1; i<=N; ++i) {
        if (birds[i].first == 'L') {
            for (int j=0; j<M; ++j) {
                left_bird[j+1] -= birds[i].second[j] - '0';
            }
        }
        else {
            for (int j=0; j<M; ++j) {
                right_bird[j+1] -= birds[i].second[j] - '0';
            }
        }
        int tmp_power = -1, now_left = 0, now_right = 0;
        
        for (int i=1; i<=M; ++i) {
            now_left += left_bird[i];
            now_right += right_bird[i];
            
            int tmp = abs(now_left - now_right);
            if (tmp > tmp_power) {
                tmp_power = tmp;
            }
        }
        if (birds[i].first == 'L') {
            for (int j=0; j<M; ++j) {
                left_bird[j+1] += birds[i].second[j] - '0';
            }
        }
        else {
            for (int j=0; j<M; ++j) {
                right_bird[j+1] += birds[i].second[j] - '0';
            }
        }
        
        if (tmp_power < best_power) {
            best_bird = i;
            best_power = tmp_power;
        }

    }
    
    cout << best_bird << "\n" << best_power;

    return 0;
}
