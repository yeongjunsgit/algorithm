#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    // N = 땅의 개수, M = 조교의 명령 수
    int N, M;
    cin >> N >> M;
    
    cin.ignore();
    
    vector<int> lands;
    lands.push_back(0);
    
    string data;
    getline(cin, data);
    
    istringstream iss(data);
    int num;
    while (iss >> num) {
        lands.push_back(num);
    }
    
    vector<vector<int>> start_record(N+1);
    vector<vector<int>> end_record(N+1);
    
    for (int i=0; i<M; ++i) {
        int s, e, depth;
        cin >> s >> e >> depth;
        
        start_record[s].push_back(depth);
        end_record[e].push_back(depth);
    }
    
    int now_plus = 0;
    
    // stack에 start를 넣고 그 합만큼 인덱스에 더해주자
    // end stack에 나오면 해당 값을 stack 에서 빼자
    for (int i=1; i<N+1; ++i) {
        if (start_record[i].size() != 0) {
            for (int j=0; j<start_record[i].size(); ++j) {
                now_plus += start_record[i][j];
            }
        }
        
        lands[i] += now_plus;
        
        if (end_record[i].size() != 0) {
            for (int j=0; j<end_record[i].size(); ++j) {
                now_plus -= end_record[i][j];
            }
        }
        
    }
    
    for (int i=1; i<N+1; ++i) {
        cout << lands[i] << " ";
    }

    return 0;
}

