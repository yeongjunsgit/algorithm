#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

int main()
{
    int N;
    cin >> N;
    
    cin.ignore();
    
    string data;
    getline(cin, data);
    
    istringstream iss(data);
    int num;
    
    int numbers[N];
    
    int maxNum = 0;
    
    int idx = 0;
    
    while (iss >> num) {
        numbers[idx] = num;
        idx += 1;
        if (num > maxNum) {
            maxNum = num;
        }
    }
    
    double sumNum = 0;
    
    for (int i = 0; i<N; ++i) {
        double tmpNum = static_cast<double>(numbers[i]) / static_cast<double>(maxNum) * 100;
        sumNum += tmpNum;

    }
    
    double result = sumNum / N;
    
    cout << result;
    

    return 0;
}