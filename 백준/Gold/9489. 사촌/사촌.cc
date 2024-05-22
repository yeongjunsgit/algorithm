#include <iostream>
#include <sstream>
#include <vector>
#include <map>

using namespace std;


int main()
{
    while (true) {
        int N, M;
        cin >> N >> M;
        if (N == 0 && M == 0) {
            break;
        }
        
        cin.ignore();
        string data;
        getline(cin, data);
        
        istringstream iss(data);
        vector<int> numbers;
        int num;
        while (iss >> num) {
            numbers.push_back(num);
        }
        
        vector<vector<int>> trees;
        
        trees.push_back({numbers[0]});
        
        map<int, int> num_depths;
        map<int, int> num_parents;
        
        num_depths.insert({numbers[0], 0});
        num_parents.insert({numbers[0], 0});
        
        int idx = 2;
        int now_depths = 1;
        
        while (idx < N) {
            int parents_idx = 0;
            int base_start = numbers[1];
            vector<int> this_depths;
            this_depths.push_back(base_start);
            num_depths.insert({numbers[1], now_depths});
            num_parents.insert({numbers[1], trees[now_depths - 1][parents_idx]});
            
            while (idx < N) {
                // 연속되는 수열 이라면 현재 depths에 기록하고 부모와 현재 depths를 map에 저장
                if (numbers[idx] == base_start + 1) {
                    base_start = numbers[idx];
                    num_depths.insert({numbers[idx], now_depths});
                    num_parents.insert({numbers[idx], trees[now_depths - 1][parents_idx]});
                    this_depths.push_back(numbers[idx]);
                    idx += 1;
                }
                // 연속되는 수열이 아니라면 다음 노드에 자식으로 들어감 만약 현재 노드가 현재 부모 depths 마지막 요소였다면
                // 깊이를 더 들어감
                else {
                    // 현재 부모 노드가 부모 깊이의 마지막 노드라면 다음 깊이로 이동하고 부모 노드를 다시 0번째 인덱스로 변경
                    if (parents_idx == trees[now_depths - 1].size() - 1) {
                        parents_idx = 0;
                        now_depths += 1;
                        trees.push_back(this_depths);
                        this_depths = {};
                    }
                    // 마지막 노드가 아니라면 다음 노드로 이동
                    else {
                        parents_idx += 1;
                    }
                    
                    base_start = numbers[idx];
                    num_depths.insert({numbers[idx], now_depths});
                    num_parents.insert({numbers[idx], trees[now_depths - 1][parents_idx]});
                    this_depths.push_back(numbers[idx]);
                    idx += 1;
                }
            }
            
            trees.push_back(this_depths);
            
        }
        
        
        
        int target_depths = num_depths[M];
        int target_parents = num_parents[M];
        
        if (target_parents == 0) {
            cout << 0 << "\n";
        }
        
        else {
            int result = 0;
            for (int i=0; i<trees[target_depths].size(); ++i) {
                // cout << num_parents[trees[target_depths][i]] << " " << target_parents << "\n";
                if (num_parents[trees[target_depths][i]] == target_parents) {
                    continue;
                }
                else {
                    if (num_parents[num_parents[trees[target_depths][i]]] == num_parents[target_parents]) {
                        result += 1;
                    }
                }
            }
            
            cout << result << "\n";
        }
        
    }

    return 0;
}
