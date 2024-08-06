#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void make_anagram(vector<char>& my_data, vector<char>& tmp, int& data_length, vector<bool>& used, int idx) {
    if (idx == data_length) {
        for (int i=0; i<data_length; ++i) {
            cout << tmp[i];
        }
        cout << "\n";
        return;
    }
    
    for (int i=0; i<data_length; ++i) {
        if (my_data[i] > tmp[idx] && used[i] == false) {
            tmp[idx] = my_data[i];
            used[i] = true;
            make_anagram(my_data, tmp, data_length, used, idx + 1);
            used[i] = false;
        }
    }
    tmp[idx] = ' ';
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N;
    cin >> N;
    string full_data;
    
    for (int i=0; i<N; ++i) {
        cin >> full_data;
        vector<char> my_data;
        
        for (auto c : full_data) {
            my_data.push_back(c);
        }
        
        sort(my_data.begin(), my_data.end());
        
        int data_length = my_data.size();
        vector<char> tmp(data_length, ' ');
        vector<bool> used(data_length, false);
        make_anagram(my_data, tmp, data_length, used, 0);
    }
    

    return 0;
}
