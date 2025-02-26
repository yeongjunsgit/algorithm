#include <iostream>
#include <vector>
#include <string>

using namespace std;


int main()
{
    string data;
    cin >> data;
    
    vector<int> numbers;
    vector<char> calcul;
    string tmp = "";
    int tmp_num;
    
    for (char c : data) {
        if ('0' <= c && c <= '9') {
            tmp += c;
        }
        else {
            tmp_num = stoi(tmp);
            if (calcul.size() == 0) {
                numbers.push_back(tmp_num);
                tmp = "";
            }
            else {
                if (calcul.back() == '+') {
                    calcul.pop_back();
                    int before = numbers.back();
                    numbers.pop_back();
                    before += tmp_num;
                    numbers.push_back(before);
                }
                else {
                    numbers.push_back(tmp_num);
                }
            }
            tmp = "";
            calcul.push_back(c);
        }
    }
    tmp_num = stoi(tmp);
    if (calcul.size() == 0) {
        numbers.push_back(tmp_num);
    }
    else {
        if (calcul.back() == '+') {
            calcul.pop_back();
            int before = numbers.back();
            numbers.pop_back();
            before += stoi(tmp);
            numbers.push_back(before);
        }
        else {
            numbers.push_back(tmp_num);
        }
    }
    
    int result = numbers[0];
    int num_size = numbers.size();
    for (int i=1; i<num_size; ++i) {
        result -= numbers[i];
    }
    
    cout << result;

    return 0;
}