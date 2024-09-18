#include <iostream>
#include <sstream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N, M;
vector<int> numbers;

void get_insert()
{
    priority_queue<int, vector<int>, greater<int> > que;
    for (int i=0; i<M; ++i) {
        que.push(0);
    }
    
    for (int i=0; i<N; ++i) {
        que.push(que.top() + numbers[i]);
        que.pop();
    }
    
    int now = 0;
    while (!que.empty()) {
        now = que.top();
        que.pop();
    }
    
    cout << now;
}

int main()
{
    cin >> N >> M;
    cin.ignore();
    
    string data;
    int num;
    getline(cin, data);
    istringstream iss(data);
    
    while (iss >> num) {
        numbers.push_back(num);
    }
    
    sort(numbers.begin(), numbers.end(), greater<int>());
    
    get_insert();

    return 0;
}
