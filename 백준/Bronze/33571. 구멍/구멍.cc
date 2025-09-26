#include <iostream>
#include <unordered_set>

using namespace std;

unordered_set<char> check_list = {'A', 'a', 'b', 'D', 'd', 'e', 'g', 'O', 'o', 'P', 'p', 'Q', 'q', 'R', '@'};

int main()
{
    string S;
    getline(cin, S);
    int cnt = 0;
    for (char c : S) {
        if (check_list.find(c) != check_list.end()) cnt++;
        else if (c == 'B') cnt += 2;
    }
    
    cout << cnt;

    return 0;
}