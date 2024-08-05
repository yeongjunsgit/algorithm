/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <vector>

using namespace std;

int idx = 0;
string my_data;
string result = "SUBMARINE";
int N;
void continue_one();
void check_one();

void check_zero() {
    if (idx + 1 < N) {
        if (my_data[idx + 1] == '1') {
            idx += 2;
        }
        else {
            result = "NOISE";
        }
    }
    else {
        result = "NOISE";
    }
    return;
}

void continue_one() {
    while (my_data[idx] == '1' && idx < N) {
        idx += 1;
        if (idx >= N-1) {
            return;
        }
    }
    if (my_data[idx + 1] == '0' && idx + 1 < N) {
        idx -= 1;
        check_one();
    }
    else if (my_data[idx + 1] == '1' && idx + 1 < N) {
        idx += 2;
    }
    else {
        result = "NOISE";
    }
    return;
}

void check_one() {
    if (idx + 3 < N) {
        if (my_data[idx + 1] == '0' && my_data[idx + 2] == '0') {
            idx += 3;
            while (my_data[idx] != '1' && idx < N) {
                idx += 1;
                if (idx == N) {
                    result = "NOISE";
                    return;
                }
            }
            idx += 1;
            if (my_data[idx] == '1') {
                continue_one();
            }
        }
        else {
            result = "NOISE";
        }
    }
    else {
        result = "NOISE";
    }
    return;
}

int main()
{
    cin >> my_data;
    
    N = my_data.size();
    
    while (result == "SUBMARINE" && idx < N) {
        if (my_data[idx] == '1') {
            check_one();
        }
        else if (my_data[idx] == '0') {
            check_zero();
        }
    }
    
    cout << result;

    return 0;
}
