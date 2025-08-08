#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

unordered_map<string, int> name_to_idx;
vector<vector<int> > give_gift(50, vector<int>(50, 0));
vector<int> gift_power(50, 0), next_month(50, 0);

int solution(vector<string> friends, vector<string> gifts) {
    int N = friends.size(), answer = 0, idx = 0;
    for (string s : friends) {
        name_to_idx[s] = idx;
        idx++;
    }
    
    for (string a : gifts) {
        string one = "", two = "";
        bool is_blank = false;
        for (char c : a) {
            if (c == ' ') {
                is_blank = true;
                continue;
            }
            if (is_blank) two += c;
            else one += c;
        }
        int s = name_to_idx[one]; int e = name_to_idx[two];
        gift_power[s]++; gift_power[e]--;
        give_gift[s][e]++; give_gift[e][s]--;
    }
    
    for (int i=0; i<N; ++i) {
        for (int j=i+1; j<N; ++j) {
            if (give_gift[i][j] == 0 && give_gift[j][i] == 0) {
                if (gift_power[i] < gift_power[j]) next_month[j]++;
                else if (gift_power[i] > gift_power[j]) next_month[i]++;
            }
            else if (give_gift[i][j] < give_gift[j][i]) next_month[j]++;
            else if (give_gift[i][j] > give_gift[j][i]) next_month[i]++;
        }
    }
    
    for (int i=0; i<N; ++i) {
        answer = max(answer, next_month[i]);
    }
    
    return answer;
}