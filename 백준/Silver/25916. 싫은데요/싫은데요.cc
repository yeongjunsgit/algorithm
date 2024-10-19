#include <iostream>
#include <sstream>
#include <vector>
#include <deque>

using namespace std;

int N, M;
vector<int> holes;
int result = 0;

void check_hamster()
{
    deque<int> que;
    int now = 0;
    
    for (int a : holes) {
        que.push_back(a);
        now += a;
        if (now > M) {
            while (now > M) {
                now -= que.front();
                que.pop_front();
            }
        }
        
        if (result < now) {
            result = now;
        }
    }
    
    cout << result;
    
    return;
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
        holes.push_back(num);
    }

    check_hamster();
    
    return 0;
}
