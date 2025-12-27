#include <iostream>
#include <vector>

using namespace std;

int N, T = 0;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    while (true) {
        cin >> N;
        if (N == 0) break;
        T++;
        vector<string> students_names(N+1);
        vector<char> called_nums(N+1, '-');
        string data; int num; char called;
        cin.ignore();
        for (int i=1; i<=N; ++i) {
            getline(cin, data);
            students_names[i] = data;
        }
        for (int i=1; i<= 2 * N - 1; ++i) {
            cin >> num >> called;
            if (called_nums[num] == '-') called_nums[num] = called;
            else if ((called_nums[num] == 'A' && called == 'B') || (called_nums[num] == 'B' && called == 'A') ) called_nums[num] = '0';
        }
        for (int i=1; i<=N; ++i) {
            if (called_nums[i] != '0') cout << T << " " << students_names[i] << "\n";
        }
        
    }
    
    return 0;
}
