#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

int main()
{
    int N, M, num;
    cin >> N >> M;
    cin.ignore();
    string data;
    getline(cin, data);
    istringstream iss(data);
    vector<int> cards;
    while (iss >> num) {
        cards.push_back(num);
    }
    
    int result = 0;
    
    for (int i=0; i<N; ++i) {
        for (int j=i+1; j<N; ++j) {
            for (int k=j+1; k<N; ++k) {
                int tmp = cards[i] + cards[j] + cards[k];
                if (tmp <= M && result < tmp) {
                    result = tmp;
                } 
            }
        }
    }
    
    cout << result;

    return 0;
}