#include <iostream>
#include <sstream>
#include <vector>
#include <unordered_map>

using namespace std;

long long T; 
int N, M;

vector<long long> arr_N, arr_M;
unordered_map<long long, long long> umap_N, umap_M;

void make_umap(unordered_map<long long, long long>& umap, vector<long long>& arr)
{
    int limit_size = arr.size();
    
    for (int i=0; i<limit_size; ++i) {
        umap[arr[i]]++;
    
        for (int j=0; j<i; ++j) {
            umap[arr[i] - arr[j]]++;
        }
    }
    
    return;
}

long long result = 0;

void find_T()
{
    for (auto a : umap_N) {
        long long target = T - a.first;
        
        if (umap_M.find(target) != umap_M.end()) {
            result += a.second * umap_M[target];
        }
    }
    
    cout << result;
    
    return;
}

int main()
{
    cin >> T >> N;
    cin.ignore();
    
    
    arr_N.resize(N, 0);
    string data;
    long long num;
    getline(cin, data);
    istringstream iss(data);
    int N_idx = 0;
    
    while (iss >> num) {
        if (N_idx != 0) {
            arr_N[N_idx] = num + arr_N[N_idx - 1];
        }
        else {
            arr_N[N_idx] = num;
        }
        N_idx++;
    }
    
    cin >> M;
    cin.ignore();
    arr_M.resize(M, 0);
    
    getline(cin, data);
    istringstream isss(data);
    int M_idx = 0;
    while (isss >> num) {
        if (M_idx != 0) {
            arr_M[M_idx] = num + arr_M[M_idx - 1];
        }
        else {
            arr_M[M_idx] = num;
        }
        M_idx++;
    }

    make_umap(umap_N, arr_N);
    make_umap(umap_M, arr_M);
    
    find_T();

    return 0;
}
