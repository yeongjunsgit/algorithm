#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

int result = -2000001;
int N, M;
vector<vector<int> > graph;
vector<vector<int> > stackplus;

void make_stackplus()
{
    for (int i=0; i<N; ++i) {
        stackplus[i][0] = graph[i][0];
        for (int j=1; j<M; ++j) {
            stackplus[i][j] = stackplus[i][j-1] + graph[i][j];
        }
        
        if (i > 0) {
            for (int j=0; j<M; ++j) {
                stackplus[i][j] += stackplus[i-1][j];
            }
        }
    }
    
    return;
}

void find_best()
{
    for (int i=0; i<N; ++i) {
        for (int j=0; j<M; ++j) {
            int base = stackplus[i][j];
            if (result < base) {
                result = base;
            }
            if (i != 0) {
                for (int p=0; p<i; ++p) {
                    int i_tmp = base - stackplus[p][j];
                    if (i_tmp > result) {
                        result = i_tmp;
                    }
                }
            }
            
            if (j != 0) {
                for (int q=0; q<j; ++q) {
                    int j_tmp = base - stackplus[i][q];
                    if (j_tmp > result) {
                        result = j_tmp;
                    }
                }
            }
            
            if (i != 0 && j != 0) {
                for (int p=0; p<i; ++p) {
                    for (int q=0; q<j; ++q) {
                        int i_j_tmp = base - (stackplus[p][j] + stackplus[i][q] - stackplus[p][q]);
                        if (i_j_tmp > result) {
                            result = i_j_tmp;
                        }
                    }
                }
            }
        }
    }
    
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> N >> M;
    cin.ignore();
    
    stackplus.resize(N, vector<int>(M, 0));
    
    string data;
    int num;
    
    for (int i=0; i<N; ++i) {
        vector<int> one_line;
        getline(cin, data);
        istringstream iss(data);
        
        while (iss >> num) {
            one_line.push_back(num);
        }
        
        graph.push_back(one_line);
    }
    
    make_stackplus();

    
    find_best();
    
    cout << result;

    return 0;
}
