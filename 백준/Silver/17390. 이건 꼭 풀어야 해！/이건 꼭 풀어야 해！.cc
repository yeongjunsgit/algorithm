#include <iostream>
#include <algorithm>
#include <sstream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio (false);
    cin.tie (NULL);
    
    int N, Q;
    cin >> N >> Q;
    
    cin.ignore();
    
    string data;
    getline(cin, data);
    
    istringstream iss(data);
    
    int num;
    vector<int> numbers;
    numbers.push_back(0);
    
    while (iss >> num) {
        numbers.push_back(num);
    }
    
    sort(numbers.begin(), numbers.end());
    
    int stack_sum[N+1] = {0};
    stack_sum[1] = numbers[1];
    
    for (int i=2; i<N+1; ++i) {
        stack_sum[i] = stack_sum[i-1] + numbers[i];
    }
    
    for (int j=0; j<Q; ++j) {
        int start_point, end_point;
        cin >> start_point >> end_point;
        
        int result = stack_sum[end_point] - stack_sum[start_point-1];
        
        cout << result << "\n";
    }

    return 0;
}