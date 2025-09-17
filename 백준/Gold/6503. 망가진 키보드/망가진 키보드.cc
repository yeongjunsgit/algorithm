#include <iostream>
#include <vector>
#include <deque>
#include <unordered_map>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int M;
    while (true) {
        cin >> M;
        if (M == 0) break;
        deque<char> windows;
        unordered_map<char, int> used;
        string sentence; int now = 0, result = 0, cnt = 0;
        cin.ignore();
        getline(cin, sentence);
        
        for (char c : sentence) {
            windows.push_back(c);
            if (used.find(c) == used.end() || used[c] == 0) now++;
            used[c]++;
            cnt++;
            if (now > M) {
                if (used[c] == 1) {
                    while (now != M) {
                        used[windows.front()]--;
                        if (used[windows.front()] == 0) now--;
                        windows.pop_front();
                        cnt--;
                    }
                }
            }
            result = max(result, cnt);
        }
        cout << result << "\n";
    }
    
    return 0;
}
