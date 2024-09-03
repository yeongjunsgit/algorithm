#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <cmath>

using namespace std;

// N = 최대 층수, K = 디스플레이 자리, P는 LED 최대 반전 개수, X = 실제 층
int N, K, P;
string X;
int cnt = 0;
int tmp = 0;

map<int, vector<int> > change_num;

void fill_change_num()
{
    change_num[0] = {0, 4, 3, 3, 4, 3, 2, 3, 1, 2};
    change_num[1] = {4, 0, 5, 3, 2, 5, 6, 1, 5, 4};
    change_num[2] = {3, 5, 0, 2, 5, 4, 3, 4, 2, 3};
    change_num[3] = {3, 3, 2, 0, 3, 2, 3, 2, 2, 1};
    change_num[4] = {4, 2, 5, 3, 0, 3, 4, 3, 3, 2};
    change_num[5] = {3, 5, 4, 2, 3, 0, 1, 4, 2, 1};
    change_num[6] = {2, 6, 3, 3, 4, 1, 0, 5, 1, 2};
    change_num[7] = {3, 1, 4, 2, 3, 4, 5, 0, 4, 3};
    change_num[8] = {1, 5, 2, 2, 3, 2, 1, 4, 0, 1};
    change_num[9] = {2, 4, 3, 1, 2, 1, 2, 3, 1, 0};
    
    if (X.size() < K) {
        int cover_range = K - X.size();
        string attach_s = "";
        for (int i=0; i<cover_range; ++i) {
            attach_s += '0';
        }
        X = attach_s + X;
    }
}

void search_num(int idx, int now_use)
{
    if (idx == K) {
        if (stoi(X) != tmp && tmp != 0) {
            if (tmp <= N && now_use <= P) {
                cnt += 1;
            }
        }
            
        return;
    }
    else {
        for (int i=0; i<=9; ++i) {
            if (X[idx] - '0' != i) {
                if (change_num[X[idx] - '0'][i] + now_use <= P) {
                    tmp *= 10;
                    tmp += i;
                    search_num(idx + 1, change_num[X[idx] - '0'][i] + now_use);
                    tmp /= 10;
                }
            }
            else {
                tmp *= 10;
                tmp += i;
                search_num(idx + 1, now_use);
                tmp /= 10;
            }
        }
        return;
    }
}

int main()
{
    cin >> N >> K >> P >> X;
    fill_change_num();
    
    search_num(0, 0);
    
    cout << cnt;
    
    return 0;
}
