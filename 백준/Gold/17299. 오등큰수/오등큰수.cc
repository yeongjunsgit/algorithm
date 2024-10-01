#include <iostream>
#include <sstream>
#include <vector>
#include <unordered_map>

using namespace std;

int N, best_power = 0;

vector<int> numbers;
vector<int> result;
unordered_map<int, int> num_power;

void check_NGF()
{
    vector<pair<int, int> > stacker;
    
    for (int i=0; i<N; ++i) {
        if (stacker.size() > 0) {
            while (stacker.size() > 0 && stacker.back().first < num_power[numbers[i]]) {
                result[stacker.back().second] = numbers[i];
                stacker.pop_back();
            }
        }
        
        if (num_power[numbers[i]] == best_power) {
            result[i] = -1;
        }
        else {
            stacker.push_back({num_power[numbers[i]], i});
        }
    }
    
    if (stacker.size() > 0) {
        for (auto a : stacker) {
            result[a.second] = -1;
        }
    }
    
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> N;
    cin.ignore();
    
    result.resize(N, 0);
    string data;
    int num;
    
    getline(cin, data);
    istringstream iss(data);
    while (iss >> num) {
        numbers.push_back(num);
        num_power[num] += 1;
        if (best_power < num_power[num]) {
            best_power = num_power[num];
        }
    }
    
    check_NGF();
    
    for (int a : result) {
        cout << a << " ";
    }

    return 0;
}
