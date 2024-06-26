#include <iostream>
#include <vector>
#include <map>

using namespace std;

int N;

int mind_distance(vector<string>& combo) {
    int distance = 0;
    
    for (int i=0; i<4; ++i) {
        if (combo[0][i] != combo[1][i]) {
            distance += 1;
        }
        if (combo[0][i] != combo[2][i]) {
            distance += 1;
        }
        if (combo[1][i] != combo[2][i]) {
            distance += 1;
        }
    }
    
    return distance;
}

void make_combination(vector<string>& mbti, vector<bool>& passed, int idx, vector<string>& combi, int& result) {
    if (combi.size() == 3) {
        int tmp_result = mind_distance(combi);
        if (result > tmp_result) {
            result = tmp_result;
        }
        return;
    }
    
    for (int i=idx; i<mbti.size(); ++i) {
        if (passed[i] == false) {
            passed[i] = true;
            combi.push_back(mbti[i]);
            make_combination(mbti, passed, i + 1, combi, result);
            passed[i] = false;
            combi.pop_back();
        }
    }
    
    return;
}

int main()
{
    int T;
    cin >> T;
    
    for (int t=0; t<T; ++t) {
        cin >> N;
        
        map<string, int> mbti_max;
        
        vector<bool> passed(N, false);
        
        string data;
        vector<string> mbti;
        
        int result = 9999999;
        
        for (int i=0; i<N; ++i) {
            cin >> data;
            if (mbti_max.find(data) == mbti_max.end()) {
                mbti_max[data] = 1;
                mbti.push_back(data);
            }
            else {
                if (mbti_max[data] < 3) {
                    mbti_max[data] += 1;
                    mbti.push_back(data);
                }
            }
        }
        
        vector<string> combi;
        make_combination(mbti, passed, 0, combi, result);
        
        cout << result << "\n";
    }

    return 0;
}
