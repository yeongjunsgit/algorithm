/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
/*
1, 2, 3, 4 의 발판마다 각 발에 올려져있는 경우에 가질 수 있는 최소 값을 기록해두자.
그 후 현재 주어지는 idx 값에 더해질 경우에 최소 값을 생각해서 기록해보자!
*/

#include <iostream>
#include <sstream>
#include <vector>
#include <cmath>

using namespace std;

vector<int> commands;
vector<vector<vector<int> > > dp(100001, vector<vector<int> >(5, vector<int>(5, 400001)));
int N;

void Dance_Dance_Revolution()
{
    dp[0][0][commands[0]] = 2;
    
    for (int i=1; i<N-1; ++i) {
        int command = commands[i];
        for (int j=0; j<5; ++j) {
            int front_cost;
            
            if (j == 0) {
                front_cost = 2;
            }
            else if (j == command) {
                front_cost = 1;
            }
            else if (abs(j - command) == 2) {
                front_cost = 4;
            }
            else {
                front_cost = 3;
            }
            
            for (int k=0; k<5; ++k) {
                dp[i][command][k] = min(dp[i][command][k], dp[i-1][j][k] + front_cost);
                
                int end_cost;
                
                if (k == 0) {
                    end_cost = 2;
                }
                else if (k == command) {
                    end_cost = 1;
                }
                else if (abs(k - command) == 2) {
                    end_cost = 4;
                }
                else {
                    end_cost = 3;
                }
                
                dp[i][j][command] = min(dp[i][j][command], dp[i-1][j][k] + end_cost);
            }
        }
    }
    
    int result = 400001;
    
    for (int i=0; i<5; ++i) {
        for (int j=0; j<5; ++j) {
            if (dp[N-2][i][j] < result) {
                result = dp[N-2][i][j];
            }
        }
    }
    
    cout << result;
    
    return;
    
}

int main()
{
    string data;
    getline(cin, data);
    
    istringstream iss(data);
    int num;
    while (iss >> num) {
        commands.push_back(num);
    }
    
    N = commands.size();
    
    Dance_Dance_Revolution();
    

    return 0;
}
