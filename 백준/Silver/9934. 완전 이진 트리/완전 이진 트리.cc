#include <iostream>
#include <vector>
#include <sstream>
#include <cmath>


using namespace std;

int setNum(int idx, vector<int>& nodes, int* tree, int& used);

int main()
{
    int deep;
    cin >> deep;
    
    vector<int> nodes;
    
    cin.ignore();
    
    string data;
    getline(cin, data);
    
    istringstream iss(data);
    int num;
    while (iss >> num) {
        nodes.push_back(num);
    }
    
    int tree[nodes.size()+1];
    
    int used = 0;
    
    setNum(1, nodes, tree, used);
    
    int deepPrint = 0;
    int printIdx = 1;
    
    while (deepPrint != deep) {
        int repeat = pow(2, deepPrint);
        for (int i=0; i<repeat; ++i){
            cout << tree[printIdx] << " ";
            printIdx += 1;
        }
        
        cout << endl;
        deepPrint += 1;
    }
    

    return 0;
}

int setNum(int idx, vector<int>& nodes, int* tree, int& used) {
    if (idx * 2 <= nodes.size()) {
        setNum(idx*2, nodes, tree, used);
    }
    tree[idx] = nodes[used];
    used += 1;
    if (idx * 2 +1 <= nodes.size()) {
        setNum(idx*2+1, nodes, tree, used);
    }
    
    return 0;
}