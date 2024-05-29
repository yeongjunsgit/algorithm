#include <iostream>
#include <sstream>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>

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
    
    sort(shoot_area.begin(), shoot_area.end());
    
    // vector<pair<int, int>> animals;
    // map<pair<int, int>, bool> hunted;
    int result = 0;
    
    for (int i=0; i<N; ++i) {
        int s, e;
        cin >> s >> e;
        
        // animals.push_back({s, e});
        // hunted.insert({{s, e}, false});
        
        int start = 0;
        int end = M-1;
        int mid;
        bool is_ok = false;
        long long gap = 1000000001;
        
        while (start <= end) {
            mid = (start + end) / 2;
            if (shoot_area[mid] == s) {
                if (e <= L) {
                    result += 1;
                    is_ok = true;
                    break;
                }
                else {
                    break;
                }
            }
            
            else if (shoot_area[mid] > s){
                end = mid -1;
                if (gap > abs(shoot_area[mid] - s)) {
                    gap = abs(shoot_area[mid] - s);
                }
            }
            
            else if (shoot_area[mid] < s){
                start = mid + 1;
                if (gap > abs(shoot_area[mid] - s)) {
                    gap = abs(shoot_area[mid] - s);
                }
            }
        }
        
        if (is_ok == false) {
                if (gap > abs(shoot_area[start] - s)) {
                    gap = abs(shoot_area[start] - s);
                }
            if (L >= gap + e) {
                result += 1;
            }
        }
    }
    
    cout << result;

    return 0;
}

