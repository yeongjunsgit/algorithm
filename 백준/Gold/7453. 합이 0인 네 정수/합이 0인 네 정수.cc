#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int N;
vector<vector<int> > numbers(4);
vector<int> array_one, array_two;
long long result = 0;

void make_zero()
{
    int one_idx = 0;
    int two_idx = 0;
    
    while (one_idx < N*N && two_idx < N*N) {
        int tmp = array_one[one_idx] + array_two[two_idx];
        if (tmp == 0) {
            // cout << array_one[one_idx] << " " << array_two[two_idx] << " ";
            long long one_same = 1, two_same = 1;
            while (one_idx < N*N - 1 && array_one[one_idx] == array_one[one_idx + 1]) {
                one_same++;
                one_idx++;
            }
            
            while (two_idx < N*N - 1 && array_two[two_idx] == array_two[two_idx + 1]) {
                two_same++;
                two_idx++;
            }
            
            one_idx++;
            two_idx++;
            // cout << one_same << " " << two_same << "\n";
            result += (one_same * two_same);
            
        }
        else if (tmp > 0) {
            two_idx++;
        }
        else {
            one_idx++;
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
    int num;
    
    for (int i=0; i<N; ++i) {
        for (int j=0; j<4; ++j) {
            cin >> num;
            numbers[j].push_back(num);
        }
    }
    

    for (int j=0; j<N; ++j) {
        for (int k=0; k<N; ++k) {
            array_one.push_back(numbers[0][j] + numbers[1][k]);
            array_two.push_back(numbers[2][j] + numbers[3][k]);
        }
    }
    
    sort(array_one.begin(), array_one.end());
    sort(array_two.begin(), array_two.end(), greater<int>());
    
    make_zero();

    return 0;
}
