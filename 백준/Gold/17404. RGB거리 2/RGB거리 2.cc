#include <iostream>
#include <sstream>
#include <vector>
#include <map>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N, one, two, three;
    cin >> N;
    cin.ignore();
    
    vector<vector<map<int, int> > > dp(N, vector<map<int, int> >(3));
    string data;
    int num;
    
    for (int i=0; i<N; ++i) {
        getline(cin, data);
        istringstream iss(data);
        vector<int> one_line;
        while (iss >> num) {
            one_line.push_back(num);
        }
        
        if (i == 0) {
            for (int j=0; j<3; ++j) {
                dp[0][j][j] = one_line[j];
            }
        }
        else if (i == N-1) {
            for (int j=0; j<3; ++j) {
                for (int k=0; k<3; ++k) {
                    if (k != j) {
                        for (auto p : dp[i-1][k]) {
                            if (p.first != j) {
                                if (dp[i][j].find(p.first) != dp[i][j].end()) {
                                    if (dp[i][j][p.first] > p.second + one_line[j]) {
                                        dp[i][j][p.first] = p.second + one_line[j];
                                    }
                                }
                                else {
                                    dp[i][j][p.first] = p.second + one_line[j];
                                }
                            }
                        }
                    }
                }
            }
        }
        
        else {
            for (int j=0; j<3; ++j) {
                for (int k=0; k<3; ++k) {
                    if (k != j) {
                        for (auto p : dp[i-1][k]) {
                            if (dp[i][j].find(p.first) != dp[i][j].end()) {
                                if (dp[i][j][p.first] > p.second + one_line[j]) {
                                    dp[i][j][p.first] = p.second + one_line[j];
                                }
                            }
                            else {
                                dp[i][j][p.first] = p.second + one_line[j];
                            }
                        }
                    }
                }
            }
        }
    }
    
    int result = 1000001;
    
    for (int i=0; i<3; ++i) {
        for (auto p : dp[N-1][i]) {
            if (p.second < result) {
                result = p.second;
            }
        }
    }

    cout << result;

    return 0;
}
