#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    cin >> T;
    
    cin.ignore();
    
    string data;
    
    vector<pair<int, int>> direction = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    
    for (int t=0; t<T; ++t) {
        pair<int, int> now = {0, 0};
        int now_direction = 0;
        
        int minus_x = 0;
        int plus_x = 0;
        int minus_y = 0;
        int plus_y = 0;
        
        getline(cin, data);
        
        for (int i=0; i<data.size(); ++i) {
            char now_command = data[i];
            
            switch (now_command) {
                case 'F':
                    now.first += direction[now_direction].first;
                    now.second += direction[now_direction].second;
                    
                    if (now.first > plus_x) {
                        plus_x = now.first;
                    }
                    else if (now.first < minus_x) {
                        minus_x = now.first;
                    }
                    
                    if (now.second > plus_y) {
                        plus_y = now.second;
                    }
                    else if (now.second < minus_y) {
                        minus_y = now.second;
                    }
                    
                    break;
                
                case 'B':
                    now.first -= direction[now_direction].first;
                    now.second -= direction[now_direction].second;
                    
                    if (now.first > plus_x) {
                        plus_x = now.first;
                    }
                    else if (now.first < minus_x) {
                        minus_x = now.first;
                    }
                    
                    if (now.second > plus_y) {
                        plus_y = now.second;
                    }
                    else if (now.second < minus_y) {
                        minus_y = now.second;
                    }
                    
                    break;
                
                case 'L':
                    now_direction -= 1;
                    if (now_direction < 0) {
                        now_direction = 3;
                    }
                    break;
                    
                case 'R':
                    now_direction += 1;
                    if (now_direction > 3) {
                        now_direction = 0;
                    }
                    break;
            }
        }
        
        int result = (plus_x - minus_x) * (plus_y - minus_y);
        
        cout << result << "\n";
    }

    return 0;
}
