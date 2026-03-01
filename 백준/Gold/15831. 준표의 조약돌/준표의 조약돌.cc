#include <iostream>
#include <vector>
#include <deque>
#include <map>

using namespace std;

int N, B, W, best_way = 0;
string walk_way;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> B >> W >> walk_way;
    deque<char> passed;
    int black_stone = 0, white_stone = 0;
    
    for (char c : walk_way) {
        passed.push_back(c);
        if (c == 'W') white_stone++;
        else black_stone++;
        
        if (black_stone > B) {
            while (black_stone > B) {
                if (passed.front() == 'W') white_stone--;
                else black_stone--;
                passed.pop_front();
            }
        }
        
        if (black_stone <= B && white_stone >= W) {
            best_way = max(best_way, black_stone + white_stone);
        }
        
    }
    
    cout << best_way;

    return 0;
}
