#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define pll pair<int, int>

using namespace std;

struct in_Compare
{
    bool operator()(const pair<int, pll>& a, const pair<int, pll>& b) {
        return a.second.first < b.second.first;
    }
};

struct out_Compare
{
    bool operator()(const pair<int, pll>& a, const pair<int, pll>& b) {
        return a.second.second > b.second.second;
    }
};


int N, now_num, s, e;
vector<pair<int, pll> > class_info;
vector<int> room_num(100001, 0);


// 정렬한 강의들에게 강의실을 배정한다.
int in_to_the_classroom()
{
    // 정렬된 강의 중 첫번째 강의를 첫번째 강의실에 배치
    int max_room_num = 1;
    priority_queue<pair<int, pll>, vector<pair<int, pll> >, out_Compare> que;
    que.push({max_room_num, {class_info[0].second.first, class_info[0].second.second}});
    room_num[class_info[0].first] = 1;
    
    // 이후 강의들을 배치, 만약 강의실 중에 끝나는 시간이 가장 짧은 강의보다 시작시간이 빠르다면, 새 강의실을 이용
    // 아니라면, 가장 일찍 끝나는 강의실에 배정
    for (int i=1; i<N; ++i) {
        // cout << "현재 " << i << "번째 순회중 " << que.top().second.second << " " << class_info[i].second.first << "\n";
        if (que.top().second.second > class_info[i].second.first) {
            max_room_num++;
            que.push({max_room_num, {class_info[i].second.first, class_info[i].second.second}});
            room_num[class_info[i].first] = max_room_num;
        }
        else {
            room_num[class_info[i].first] = que.top().first;
            que.push({que.top().first, {que.top().second.first, class_info[i].second.second}});
            que.pop();
        }
    }
    
    return max_room_num;
}





int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    for (int i=0; i<N; ++i) {
        cin >> now_num >> s >> e;
        class_info.push_back({now_num, {s, e}});
        // cout << class_info[i].first << class_info[i].second.first << class_info[i].second.second << "\n";
    }
    sort(class_info.begin(), class_info.end(), in_Compare());
    // cout << class_info[0].first << " " << class_info[0].second.first << " " << class_info[0].second.second << "\n";
    
    cout << in_to_the_classroom() << "\n";
    
    for (int i=1; i<=N; ++i) {
        cout << room_num[i] << "\n";
    }
    

    return 0;
}

