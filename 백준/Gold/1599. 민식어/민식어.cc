#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

int N;
// 민식어는 a b k d e g h i l m n ng o p r s t u w y의 순서이다.
unordered_map<char, int> string_power = {{'a', 0}, {'b', 1}, {'k', 2}, {'d', 3}, {'e', 4}, {'g', 5}, 
    {'h', 6}, {'i', 7}, {'l', 8}, {'m', 9}, {'n', 10}, {'-', 11}, {'o', 12}, {'p', 13}, {'r', 14}, {'s', 15}, {'t', 16}, {'u', 17}, {'w', 18}, {'y', 19} };

vector<vector<char> > sentences(50); vector<int> s_length(50); vector<string> archetype(50); vector<int> string_idx;


struct Compare
{
    bool operator()(const int& a, const int& b) {
        int a_length = s_length[a], b_length = s_length[b];
        int now_length = min(a_length, b_length);
        
        for (int i=0; i<now_length; ++i) {
            if (string_power[sentences[a][i]] < string_power[sentences[b][i]]) {
                return true;
            }
            else if (string_power[sentences[a][i]] > string_power[sentences[b][i]]) {
                return false;
            }
        }
        if (a_length > b_length) {
            return false;
        }
        else return true;
    }
};

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    string data;
    for (int i=0; i<N; ++i) {
        cin >> data;
        archetype[i] = data;
        int data_len = data.size(), idx = 0;
        string_idx.push_back(i);
        
        for (int j=0; j<data_len; ++j) {
            if (data[j] == 'n' && j+1 < data_len && data[j+1] == 'g') {
                ++j;
                sentences[i].push_back('-');
            }
            else {
                sentences[i].push_back(data[j]);
            }
            idx++;
        }
        s_length[i] = idx;
    }
    
    sort(string_idx.begin(), string_idx.end(), Compare());
    
    for (int i : string_idx) {
        cout << archetype[i] << "\n";
    }

    return 0;
}