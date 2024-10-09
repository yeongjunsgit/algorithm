#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

unordered_map<char, int> arabian = {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};

int discover_num(string ara_num)
{
    int N = ara_num.size();
    int numnum = 0;
    int idx = 0;
    while (idx < N) {
        if (ara_num[idx] == 'I') {
            if (ara_num[idx + 1] == 'V') {
                numnum += 4;
                idx++;
            }
            else if (ara_num[idx + 1] == 'X') {
                numnum += 9;
                idx++;
            }
            else {
                numnum += 1;
            }
        }
        else if (ara_num[idx] == 'X') {
            if (ara_num[idx + 1] == 'L') {
                numnum += 40;
                idx++;
            }
            else if (ara_num[idx + 1] == 'C') {
                numnum += 90;
                idx++;
            }
            else {
                numnum += 10;
            }
        }
        else if (ara_num[idx] == 'C') {
            if (ara_num[idx + 1] == 'D') {
                numnum += 400;
                idx++;
            }
            else if (ara_num[idx + 1] == 'M') {
                numnum += 900;
                idx++;
            }
            else {
                numnum += 100;
            }
        }
        else {
            numnum += arabian[ara_num[idx]];
        }
        idx++;
    }
    
    return numnum;
}

void make_arabian(int power_num)
{
    int num = power_num;
    unordered_map<char, int> used_time;
    string result;
    
    while (num != 0) {
        if (num >= 1000) {
            int repeat_time = num / 1000;
            for (int i=0; i<repeat_time; ++i) {
                result += "M";
                num -= 1000;
            }
        }
        else if (num >= 500) {
            if (num >= 900) {
                result += "CM";
                num -= 900;
            }
            else {
                result += "D";
                num -= 500;
            }
        }
        else if (num >= 100) {
            if (num >= 400) {
                result += "CD";
                num -= 400;
            }
            else {
                int repeat_time = num / 100;
                for (int i=0; i<repeat_time; ++i) {
                    result += "C";
                    num -= 100;
                }
            }
        }
        else if (num >= 50) {
            if (num >= 90) {
                result += "XC";
                num -= 90;
            }
            else {
                result += "L";
                num -= 50;
            }
        }
        else if (num >= 10) {
            if (num >= 40) {
                result += "XL";
                num -= 40;
            }
            else {
                int repeat_time = num / 10;
                for (int i=0; i<repeat_time; ++i) {
                    result += "X";
                    num -= 10;
                }
            }
        }
        else if (num >= 5) {
            if (num >= 9) {
                result += "IX";
                num -= 9;
            }
            else {
                result += "V";
                num -= 5;
            }
        }
        else if (num >= 1) {
            if (num >= 4) {
                result += "IV";
                num -= 4;
            }
            else {
                int repeat_time = num / 1;
                for (int i=0; i<repeat_time; ++i) {
                    result += "I";
                    num -= 1;
                }
            }
        }
    }
    
    cout << result;
    
    return;
}

int main()
{
    string one, two;
    cin >> one >> two;
    
    int int_result = discover_num(one) + discover_num(two);
    
    cout << int_result << "\n";
    
    make_arabian(int_result);

    return 0;
}
