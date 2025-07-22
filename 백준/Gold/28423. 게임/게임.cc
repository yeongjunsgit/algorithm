#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>

using namespace std;

int s, e;
unordered_map<int, int> gatcha;
int result = 0;
unordered_set<int> passed;

int make_number(int x)
{
    int plus_tmp = 0, multi_tmp = 1;
    
    while (x != 0) {
        int now_num = x % 10;
        plus_tmp += now_num;
        multi_tmp *= now_num;
        x /= 10;
    }
    
    string num_front = to_string(plus_tmp);
    string num_back = to_string(multi_tmp);
    
    num_front += num_back;
    
    return stoi(num_front);
    
}


int lets_check(int num)
{
    if (gatcha.find(num) == gatcha.end()) {
        int tmp = make_number(num);
        if (tmp > 100000) {
            gatcha[num] = -1;
            return -1;
        }
        else if (tmp == num) {
            gatcha[num] = 1;
            return 1;
        }
        else if (passed.find(tmp) != passed.end()) {
            gatcha[num] = 0;
            return 0;
        }
        else {
            passed.insert(num);
            int chain_num = lets_check(tmp);
            passed.erase(num);
            gatcha[num] = chain_num;
            return chain_num;
        }
    }
    else {
        return gatcha[num];
    }
}



int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> s >> e;
    
    for (int i=s; i<=e; ++i) {
        result += lets_check(i);
    }
    
    cout << result;
    
    return 0;
}
