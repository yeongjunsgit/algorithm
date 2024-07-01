
#include <iostream>
#include <sstream>
#include <vector>
#include <map>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N, M;
    cin >> N;
    cin.ignore();
    
    int num;
    string data;
    getline(cin, data);
    map<int, int> match_num;
    
    istringstream iss(data);
    
    while (iss >> num) {
        if (match_num.find(num) == match_num.end()) {
            match_num[num] = 1;
        }
        else {
            match_num[num] += 1;
        }
    }
    
    cin >> M;
    cin.ignore();
    
    getline(cin, data);
    istringstream isss(data);
    
    while (isss >> num) {
        cout << match_num[num] << " ";
    }
    
    return 0;
}
