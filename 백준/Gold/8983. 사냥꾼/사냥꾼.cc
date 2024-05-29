#include <iostream>
#include <sstream>
#include <vector>
#include <map>
#include <cmath>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    // N = 동물의 수, M = 사대의 수, L = 사정거리 
    int M, N, L;
    cin >> M >> N >> L;
    
    cin.ignore();
    
    vector<int> shoot_area;
    
    string data;
    getline(cin, data);
    int num;
    istringstream iss(data);
    while (iss >> num) {
        shoot_area.push_back(num);
    }
    
    // vector<pair<int, int>> animals;
    // map<pair<int, int>, bool> hunted;
    int result = 0;
    
    for (int i=0; i<N; ++i) {
        int s, e;
        cin >> s >> e;
        
        // animals.push_back({s, e});
        // hunted.insert({{s, e}, false});
        
        for (int i=0; i<M; ++i) {
            pair<int, int> now_base = {shoot_area[i], 0};
            int x_range = abs(now_base.first - s); 
            int y_range = abs(now_base.second - e); 
            
            if (L >= x_range + y_range) {
                result += 1;
                break;
            }
            
        }
    }
    
    cout << result;

    return 0;
}
