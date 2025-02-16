#include <iostream>
#include <vector>
#include <string>

using namespace std;

string target, bomb;
int bomb_size, target_size;
vector<string> stackers;

void find_bomb()
{
    for (int i=0; i<target_size; ++i) {
        if (stackers.size() == 0) {
            stackers.push_back(string(1, target[i]));
        }
        else {
            if (target[i] == bomb[0]) {
                stackers.push_back(string(1, target[i]));
            }
            else {
                stackers.back() += target[i];
            }
        }
        if (stackers.back().size() == bomb_size && stackers.back() == bomb) {
            stackers.pop_back();
        }
    }
    
    return;
}

int main()
{
    cin >> target >> bomb;
    bomb_size = bomb.size();
    target_size = target.size();
    
    find_bomb();
    
    if (stackers.size() == 0) {
        cout << "FRULA";
    }
    else {
        for (string s : stackers) {
            cout << s;
        }
    }
    
    return 0;
}