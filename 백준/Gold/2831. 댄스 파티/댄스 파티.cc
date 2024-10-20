#include <iostream>
#include <sstream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int N;

vector<int> mans_plus;
vector<int> ladys_plus;
vector<int> mans_minus;
vector<int> ladys_minus;

int result = 0;

void make_match()
{
    int m = 0, p = 0;
    while (mans_plus.size() > p && ladys_minus.size() > m) {
        if (mans_plus[p] < abs(ladys_minus[m])) {
            result++;
            m++;
            p++;
        }
        else {
            p++;
        }
    }
    m = 0, p = 0;
    while (mans_minus.size() > m && ladys_plus.size() > p) {
        if (ladys_plus[p] < abs(mans_minus[m])) {
            result++;
            m++;
            p++;
        }
        else {
            p++;
        }
    }
    
    cout << result;
    
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> N;
    cin.ignore();
    
    string data;
    int num;
    getline(cin, data);
    istringstream iss(data);
    while (iss >> num) {
        if (num > 0) {
            mans_plus.push_back(num);
        }
        else {
            mans_minus.push_back(abs(num));
        }
    }
    
    getline(cin, data);
    istringstream isss(data);
    while (isss >> num) {
        if (num > 0) {
            ladys_plus.push_back(num);
        }
        else {
            ladys_minus.push_back(abs(num));
        }
    }
    
    sort(mans_minus.begin(), mans_minus.end(), greater<int>());
    sort(ladys_minus.begin(), ladys_minus.end(), greater<int>());
    sort(mans_plus.begin(), mans_plus.end(), greater<int>());
    sort(ladys_plus.begin(), ladys_plus.end(), greater<int>());
    
    make_match();

    return 0;
}
