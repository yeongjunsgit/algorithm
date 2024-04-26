#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <map>

using namespace std;

int main()
{
    int N;
    cin >> N;
    
    string command;
    cin >> command;
    
    vector<pair<int, int>> direction = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    
    int now_direction = 0;
    
    int max_x = 0;
    int min_x = 0;
    int max_y = 0;
    int min_y = 0;
    
    pair<int, int> now = {0, 0};
    
    map<pair<int,int>, bool> rooms;
    rooms.insert({now, true});
    
    for (int i=0; i<N; ++i) {
        char nc = command[i];
        
        if (nc == 'R') {
            now_direction -= 1;
            if (now_direction == -1) {
                now_direction = 3;
            }
            else if (now_direction == 4) {
                now_direction = 0;
            }
        }
        else if (nc == 'L') {
            now_direction += 1;
            if (now_direction == -1) {
                now_direction = 3;
            }
            else if (now_direction == 4) {
                now_direction = 0;
            }
        }
        else if (nc == 'F') {
            now.first += direction[now_direction].first;
            now.second += direction[now_direction].second;
            
            if (now.first > max_x) {
                max_x = now.first;
            }
            if (now.second > max_y) {
                max_y = now.second;
            }
            if (now.first < min_x) {
                min_x = now.first;
            }
            if (now.second < min_y) {
                min_y = now.second;
            }
            
            rooms.insert({now, true});
        }
    }
    
    for (int i=min_x; i<=max_x; ++i) {
        for (int j=min_y; j<=max_y; ++j) {
            if (rooms.find({i, j}) != rooms.end()) {
                cout << ".";
            }
            else {
                cout << "#";
            }
        }
        cout << "\n";
    }
    

    return 0;
}
