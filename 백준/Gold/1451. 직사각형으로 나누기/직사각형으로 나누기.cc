#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

long long make_sum(vector<vector<int>>& board, int sx, int ex, int sy, int ey) {
    int total = 0;
    
    for (int i=sx; i<=ex; ++i) {
        for (int j=sy; j<=ey; ++j) {
            total += board[i][j];
        }
    }
    
    return total;
    
}

int main()
{
    int N, M;
    cin >> N >> M;
    
    vector<vector<int>> board;
    
    string data;
    for (int i=0; i<N; ++i) {
        cin >> data;
        vector<int> one_line;
        
        for (char c : data) {
            one_line.push_back(c - '0');
        }
        
        board.push_back(one_line);
    }
    
    long long result = 0;
    
    
    // 가로로 만드는 케이스
    for (int i=0; i<N - 2; ++i) {
        for (int j = i + 1; j < N - 1; ++j){
            long long top_row_sum = make_sum(board, 0, i, 0, M - 1);
            long long mid_row_sum = make_sum(board, i + 1, j, 0, M - 1);
            long long end_row_sum = make_sum(board, j + 1, N - 1, 0, M - 1);
            
            long long row_result = top_row_sum * mid_row_sum * end_row_sum;
            if (result < row_result) {
                result = row_result;
            }
            
        }
    }
    
    // 세로로 만드는 케이스
    for (int i=0; i < M - 2; ++i) {
        for (int j = i + 1; j < M - 1; ++j){
            long long top_column_sum = make_sum(board, 0, N - 1, 0, i);
            long long mid_column_sum = make_sum(board, 0, N - 1, i + 1, j);
            long long end_column_sum = make_sum(board, 0, N - 1, j + 1, M - 1);
            
            long long column_result = top_column_sum * mid_column_sum * end_column_sum;
            if (result < column_result) {
                result = column_result;
            }
            
        }
    }
    
    // 위 세로 1줄 나머지 반가르기
    for (int i=0; i < N - 1; ++i) {
        long long top_row_divide_sum = make_sum(board, 0, i, 0, M - 1);
        for (int k=0; k < M - 1; ++k) {
            long long left_row_divide_sum = make_sum(board, i + 1, N - 1, 0, k);
            long long right_row_divide_sum = make_sum(board, i + 1, N - 1, k + 1, M - 1);
            
            long long top_row_divide_result = top_row_divide_sum * left_row_divide_sum * right_row_divide_sum;
            if (result < top_row_divide_result) {
                result = top_row_divide_result;
            }
            
        }
    }
    
    // 아래 세로 1줄 나머지 반가르기
    for (int i= N - 1; i>=1; --i) {
        long long bottom_row_divide_sum = make_sum(board, i, N - 1, 0, M - 1);
        for (int k=0; k < M - 1; ++k) {
            long long left_bottom_row_divide_sum = make_sum(board, 0, i - 1, 0, k);
            long long right_bottom_row_divide_sum = make_sum(board, 0, i - 1, k + 1, M - 1);
            
            long long bottom_row_divide_result = bottom_row_divide_sum * left_bottom_row_divide_sum * right_bottom_row_divide_sum;
            if (result < bottom_row_divide_result) {
                result = bottom_row_divide_result;
            }
            
        }
    }
    
    // 왼쪽 1줄 나머지 반가르기
    for (int i=0; i < M - 1; ++i) {
        long long left_column_sum = make_sum(board, 0, N - 1, 0, i);
        for (int k=0; k < N - 1; ++k) {
            long long top_divide_column_sum = make_sum(board, 0, k, i + 1, M - 1);
            long long bottom_divide_column_sum = make_sum(board, k + 1, N - 1, i + 1, M - 1);
            
            long long left_column_sum_result = left_column_sum * top_divide_column_sum * bottom_divide_column_sum;
            if (result < left_column_sum_result) {
                result = left_column_sum_result;
            }
        }
    }
    
    // 오른쪽 1줄 나머지 반가르기
    for (int i = M - 1; i>=1; --i) {
        long long right_column_sum = make_sum(board, 0, N - 1, i, M - 1);
        for (int k=0; k< N - 1; ++k) {
            long long top_left_divide_column_sum = make_sum(board, 0, k, 0, i - 1);
            long long bottom_left_divide_column_sum = make_sum(board, k + 1, N - 1, 0, i - 1);
            
            long long right_column_sum_result = right_column_sum * top_left_divide_column_sum * bottom_left_divide_column_sum;
            if (result < right_column_sum_result) {
                result = right_column_sum_result;
            }
        }
    }

    cout << result;

    return 0;
}
