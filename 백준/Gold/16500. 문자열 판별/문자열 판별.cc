#include <iostream>
#include <vector>
#include <string>

using namespace std;

string target;
int N;
vector<bool> dp(101, false);

void make_target(vector<string>& sentence, int& T) {
    for (int j=0; j<T; ++j) {
        if (dp[j] == true) {
            for (int i=0; i<N; ++i) {
                if (dp[T+1] == false && j + sentence[i].size() <= T) {
                    bool is_ok = true;
                    for (int k=0; k<sentence[i].size(); ++k) {
                        if (target[j+k] != sentence[i][k]) {
                            is_ok = false;
                            break;
                        }
                    }
                    if (is_ok == true) {
                        dp[j + sentence[i].size()] = true;
                    }
                }
            }
        }
    } 
    
    
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> target;
    cin >> N;
    int T = target.size();
    
    vector<string> sentence;
    string data;
    
    for (int i=0; i<N; ++i) {
        cin >> data;
        sentence.push_back(data);
    }
    
    dp[0] = true;
    make_target(sentence, T);
    if (dp[T] == true) {
        cout << 1;
    }
    else {
        cout << 0;
    }

    return 0;
}
