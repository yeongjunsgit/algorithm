/*
최소 공통 조상을 이용하여 이동거리를 측정하자!
단, 깊이를 dfs로 계산하기엔 노드의 개수가 너무나도 많으므로 K진 트리인 규칙을 이용하여 부모와 깊이를
찾아야한다.
현재 노드의 부모는 (now-1) / K 이다. 노드 번호가 0번 부터 시작한다고 했을때, 각 노드들이 정확히 K개의 자식을 가짐으로
가능한 규칙이다. 10진 트리의 51번 노드의 부모는 (51-1) / 10 으로 5번이다. 
각 노드의 깊이를 찾기위해 주어진 K를 이용하여 각 깊이에 해당하는 범위를 정해 그 안에 들어오는 값인지 확인하여
깊이를 찾는다.
서로 깊이가 다르다면 더 깊은쪽의 깊이를 올려 cnt를 올린수 만큼 더해주고 올린만큼 부모를 찾아 해당 값으로 이동한다.
깊이가 같아지면 최소 공통조상 매커니즘을 이용해 값이 같아질때까지 cnt를 2씩 더하면서 같이 올라간다.
*/


#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

long long N;
int K, Q;

long long check_depth(long long now) {
    if (K == 1) {
        return now;
    }
    

    long long depth = 0;
    
    if (now != 0) {
        depth = 1;
        long long left = 1, right = K;
        
        while ((left <= now && now <= right) == false) {
            depth++;
            left = right + 1;
            right += pow(K, depth);
        }
    }
    
    return depth;
}

void check_distance(long long s, long long e)
{
    long long s_depth = check_depth(s);
    long long e_depth = check_depth(e);
    
    if (s_depth < e_depth) {
        swap(s_depth, e_depth);
        swap(s, e);
    }
    
    if (K == 1) {
        cout << s_depth - e_depth << "\n";
    }
    
    else {
        long long result = 0;
        
        if (s_depth > e_depth) {
            long long gap = s_depth - e_depth;
            
            for (int i=0; i<gap; ++i) {
                result++;
                s = (s-1) / K;
            }
        }
        
        while (s != e) {
            s = (s-1) / K;
            e = (e-1) / K;
            result += 2;
            
            if (s == e) {
                break;
            }
        }
        
        cout << result << "\n";
    }
    
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> N >> K >> Q;
    long long s, e;
    
    for (int i=0; i<Q; ++i) {
        cin >> s >> e;
        
        check_distance(s-1, e-1);
        
    }
    
    return 0;
}
