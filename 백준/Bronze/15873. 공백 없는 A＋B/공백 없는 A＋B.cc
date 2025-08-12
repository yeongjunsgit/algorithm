#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    string N;
    cin >> N;
    vector<int> numbers(2, -1);
    int pre = -1;
    for (char a : N) {
        if (a == '0') {
            numbers[pre] *= 10;
        }
        else {        
            if (numbers[0] == -1) {
                numbers[0] = a - '0';
                pre = 0;
            }
            else {
                numbers[1] = a - '0';
                pre = 1;
            }
        }
    }
    
    cout << numbers[0] + numbers[1];

    return 0;
}