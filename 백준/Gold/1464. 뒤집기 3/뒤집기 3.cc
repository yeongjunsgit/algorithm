/*
좀 씽크빅 문제인거 같다. 처음에는 그냥 모든 경우의 수를 따지면 될거라 생각했는데
시간 초과가 났다 역시 미리 시간 복잡도 계산을 했어야 했다...
deque를 이용하여 사전순중 가장 앞의 값이 나오게 하기 위하여 그리디하게 풀었어야했다.
i번째 문자가 deque의 맨 앞으로 가면 i번째에서 뒤집었다는 얘기가 되고 맨 뒤로 가면 뒤집지 않은것이 된다는 풀이 방법이 있었다
생각지도 못한 방법으로 i번째 자리에서 뒤집은 것으로 칠 수 있다는 것이 상당히 놀라운 풀이 방법이었다..
창의적인 문제같았다..
*/


#include <iostream>
#include <vector>
#include <deque>
#include <string>
#include <algorithm>

using namespace std;

string my_data;
int N;

void soulution()
{
    deque<char> que;
    
    for (int i=0; i<N; ++i) {
        if (i == 0) {
            que.push_back(my_data[i]);
        } 
        else {
            if (que.front() < my_data[i]) {
                que.push_back(my_data[i]);
            }
            else {
                que.push_front(my_data[i]);
            }
        }
    }
    
    while (!que.empty()) {
        cout << que.front();
        que.pop_front();
    }
    
    return;
}

int main()
{
    cin >> my_data;
    N = my_data.size();
    
    soulution();
    
    return 0;
}
