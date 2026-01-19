#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

int N, M;
vector<int> dp(101, 99999999), previous_idx(101, -1), choice_idx(101, -1);
string phone_number;
vector<string> piece_of_numbers(50000, "no"), sentences(50000);
unordered_map<char, char> pad_number = {
  {'a', '2'}, {'b', '2'}, {'c', '2'}, {'d', '3'}, {'e', '3'}, {'f', '3'}, {'g', '4'}, {'h', '4'}, {'i', '1'}, {'j', '1'},
  {'k', '5'}, {'l', '5'}, {'m', '6'}, {'n', '6'}, {'o', '0'}, {'p', '7'}, {'q', '0'}, {'r', '7'}, {'s', '7'}, {'t', '8'},
  {'u', '8'}, {'v', '8'}, {'w', '9'}, {'x', '9'}, {'y', '9'}, {'z', '0'}
};
unordered_map<char, vector<int> > first_num_idx;

string change_number(string now)
{
    string tmp = "";
    for (char c : now) {
        if ('a' <= c && c <= 'z') tmp += pad_number[c];
        else return "no";
    }
    return tmp;
}


void find_result()
{
    dp[0] = 0;
    
    for (int i=0; i<M; ++i) {
        for (int j=0; j<N; ++j) {
            int now_size = piece_of_numbers[j].size();
            if (i + now_size <= M && phone_number.substr(i, now_size) == piece_of_numbers[j]) {
                if (dp[i + now_size] > dp[i] + 1) {
                    dp[i + now_size] = dp[i] + 1;
                    previous_idx[i + now_size] = i;
                    choice_idx[i + now_size] = j;
                }
            }
        }
    }
    
    if (dp[M] != 99999999) {
        cout << dp[M] << "\n";
        vector<int> passed;
        int now = M;
        while (now != -1) {
            if (previous_idx[now] != -1) passed.push_back(choice_idx[now]);
            now = previous_idx[now];
        }
        
        while (!passed.empty()){
            cout << sentences[passed.back()] << "\n";
            passed.pop_back();
        }
    } 
    else {
        cout << 0 << "\n";
        cout << "No solution.";
    }
    
    return;
}


int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> phone_number >> N;
    M = phone_number.size();
    for (int i=0; i<N; ++i) {
        cin >> sentences[i];
        string checking = change_number(sentences[i]);
        if (checking != "no") {
            piece_of_numbers[i] = checking;
            first_num_idx[piece_of_numbers[i][0]].push_back(i);
        }
    }
    
    find_result();

    return 0;
}

