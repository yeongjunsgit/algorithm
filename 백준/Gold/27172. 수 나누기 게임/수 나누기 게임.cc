#include <iostream>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int N;
vector<int> numbers;
vector<int> number_score(1000001, 0);

unordered_map<int, int> check_num;

void run_battle()
{
    for (int a : numbers) {
        int power = 2;
        
        while (a * power <= 1000000) {
            if (check_num.find(a * power) != check_num.end()) {
                number_score[a]++;
                number_score[a * power]--;
            }
            power++;
        }
    }
    
    for (int a : numbers) {
        cout << number_score[a] << " ";
    }
    
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> N;
    cin.ignore();
    
    string data;
    int num;
    
    getline(cin, data);
    istringstream iss(data);
    while (iss >> num) {
        numbers.push_back(num);
        check_num[num] = 1;
    }
    
    run_battle();

    return 0;
}
