#include <iostream>
#include <sstream>
#include <vector>
#include <queue>
#include <unordered_set>
#include <functional>

using namespace std;

// 해시함수 선언
struct VectorHash {
    size_t operator()(const vector<int>& v) const {
        size_t seed = 0;
        for (int i : v) {
            seed ^= hash<int>()(i) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
        }
        return seed;
    }
};

int main()
{
    int N;
    cin >> N;
    
    cin.ignore();
    
    int result = -1;
    
    vector<int> target;
    
    for (int i=0; i<N; ++i) {
        target.push_back(i % 3);
    }
    
    vector<int> cards;
    vector<int> change_method;
    
    string data;
    getline(cin, data);
    
    istringstream iss(data);
    int num;
    
    while (iss >> num) {
        cards.push_back(num);
    }
    
    getline(cin,data);
    
    istringstream isss(data);
    
    while (isss >> num) {
        change_method.push_back(num);
    }
    
    queue<pair<vector<int>, int>> que;
    unordered_set<vector<int>, VectorHash> passed;
    que.push({cards, 0});
    passed.insert(cards);
    
    
    while (!que.empty()) {
        pair<vector<int>, int> now = que.front();
        que.pop();
        
        if (now.first == target) {
            result = now.second;
            break;
        }
        
        vector<int> changed_vec(N, 0);
        
        for (int i=0; i<N; ++i) {
            changed_vec[change_method[i]] = now.first[i];
        }
        
        if (passed.find(changed_vec) == passed.end()) {
            passed.insert(changed_vec);
            que.push({changed_vec, now.second+1});
        }
    }
    
    cout << result;

    return 0;
}
