#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

string prefix;
vector<char> stacker;
unordered_map<char, int> comp = {{'+', 1}, {'-', 1}, {'*', 2}, {'/', 2}};

void make_postfix()
{
    string postfix;
    for (char c : prefix) {
        if (c - 'A' < 0) {
            if (c == '(') {
                stacker.push_back(c);
            }
            else if (c == ')') {
                while (stacker.back() != '(') {
                    postfix += stacker.back();
                    stacker.pop_back();
                }
                stacker.pop_back();
            }
            else {
                while (stacker.size() > 0 && stacker.back() != '(' && comp[stacker.back()] >= comp[c]) {
                    postfix += stacker.back();
                    stacker.pop_back();
                }
                stacker.push_back(c);
            }
        }
        else {
            postfix += c;
        }
    }
    
    if (stacker.size() > 0) {
        while (stacker.size() > 0) {
            postfix += stacker.back();
            stacker.pop_back();
        }
    }
    
    cout << postfix;
    
    return;
}

int main()
{
    cin >> prefix;
    
    make_postfix();

    return 0;
}
