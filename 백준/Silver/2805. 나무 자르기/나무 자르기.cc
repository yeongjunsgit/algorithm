#include <iostream>
#include <vector>

using namespace std;

int N, M;
int trees[1000000];

long long cut_trees(int height)
{
    long long cnt = 0;
    for (int i=0; i<N; ++i) {
        long long tmp = trees[i] - height;
        if (tmp > 0) {
            cnt += tmp;
        }
    }
    
    return cnt;
}

int set_height()
{
    int start = 0;
    int end = 1000000000;
    
    while (start <= end) {
        long long mid = (start + end) / 2;
        long long firewood = cut_trees(mid);
        
        if (firewood >= M) {
            start = mid + 1;
        }
        else {
            end = mid - 1;
        }
    }
    
    return end;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    cin >> N >> M;
    int num;
    for (int i=0; i<N; ++i) {
        cin >> trees[i];
    }

    cout << set_height();

    return 0;
}
