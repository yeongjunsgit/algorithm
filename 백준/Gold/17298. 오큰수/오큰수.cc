#include <iostream>
#include <vector>

#define pll pair<int, int>

using namespace std;

int N;
vector<int> numbers, O_big;

void O_big_num()
{
    vector<int> stacker;
    int stack_size = 0;
    
    for (int i=N-1; i>=0; --i) {
        
        while (stack_size > 0 && stacker.back() <= numbers[i]) {
            stacker.pop_back();
            stack_size--;
        }
        
        if (stack_size > 0) {
            O_big[i] = stacker.back();
        }
        stacker.push_back(numbers[i]);
        stack_size++;
    }
    
    for (int a : O_big) {
        cout << a << " ";
    }
    
    return;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    cin >> N;
    int num;
    O_big.resize(N, -1);
    for (int i=0; i<N; ++i) {
        cin >> num;
        numbers.push_back(num);
    }
    
    O_big_num();

    return 0;
}
