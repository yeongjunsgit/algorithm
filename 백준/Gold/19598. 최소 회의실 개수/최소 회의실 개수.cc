#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

struct Compare {
    bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
        if (a.first != b.first) {
            return a.first > b.first;
        }
        return a.second > b.second;
    }
};

struct int_Compare {
    bool operator()(const int& a, const int& b) {
        return a > b;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N;
    cin >> N;
    
    int num, start, end;
    int result = 1;
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> que;
    priority_queue<int, vector<int>, int_Compare> classrooms;
    
    for (int i=0; i<N; ++i) {
        cin >> start >> end;
        que.push({start, end});
    }
    
    for (int i=0; i<N; ++i) {
        pair<int, int> now = que.top();
        que.pop();
        
        // 처음 시작하는 회의는 바로 회의실에서 시작
        if (i == 0) {
            classrooms.push(now.second);
        }
        
        else {
            // 만약 가장 일찍 끝나는 회의가 아직 끝났지 않았다면
            if (classrooms.top() > now.first) {
                // 회의실 1개 추가
                result += 1;
            }
            else {
                // 만약 가장 일찍 끝나는 회의가 이미 끝났다면 해당 시간을 제외
                classrooms.pop();
            }
            // 현재 회의의 끝나는 시간을 우선순위 큐로 기록
            classrooms.push(now.second);
        }
    }
    
    cout << result;

    return 0;
}
