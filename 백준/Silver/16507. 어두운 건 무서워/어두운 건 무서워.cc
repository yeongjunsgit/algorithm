#include <iostream>
#include <vector>
#include <sstream>

using namespace std;


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    // N = 세로 길이, M = 가로 길이, Q = 질문의 개수
    int N, M, Q;
    cin >> N >> M >> Q;
    
    cin.ignore();
    
    vector<vector<int>> arr;
    vector<vector<int>> arr_sum;
    
    vector<int> tmp_vector;
    
    for (int i=0; i<N; ++i) {
        tmp_vector.push_back(0);
    }
    
    arr.push_back(tmp_vector);
    arr_sum.push_back(tmp_vector);
    
    for (int i=0; i<N; ++i) {
        string data;
        getline(cin, data);
        
        istringstream iss(data);
        int num;
        int sum_num = 0;
        vector<int> tmp_arr;
        vector<int> tmp_sum_arr;
        tmp_arr.push_back(0);
        tmp_sum_arr.push_back(0);
        
        while (iss >> num) {
            tmp_arr.push_back(num);
            sum_num += num;
            tmp_sum_arr.push_back(sum_num);
        }
        
        arr.push_back(tmp_arr);
        arr_sum.push_back(tmp_sum_arr);
    }
    
    for (int i=0; i<Q; ++i){
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        
        int result = 0;
        
        for (int x = x1; x<x2+1; ++x) {
            result += (arr_sum[x][y2] - arr_sum[x][y1-1]);
        }
        int each = (y2 - (y1-1)) * (x2 - (x1-1));
        result /= each;
        cout << result << "\n";
    }

    return 0;
}