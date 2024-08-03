#include <iostream>
#include <vector>

using namespace std;

int N;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie();
    
    cin >> N;
    
    vector<long long> distance;
    long long all_distance = 0;
    long long max_result = 0;
    
    long long num;
    for (int i=0; i<N; ++i) {
        cin >> num;
        distance.push_back(num);
        all_distance += num;
    }
    
    int one_idx = 0;
    int two_idx = 0;
    long long point_sum = 0;
    
    while (two_idx <= N) {
        if (point_sum > all_distance - point_sum) {
            if (all_distance - point_sum > max_result) {
                max_result = all_distance - point_sum;
            } 
            point_sum -= distance[one_idx];
            one_idx += 1;
        }
        else if (point_sum < all_distance - point_sum) {
            if (point_sum > max_result) {
                max_result = point_sum;
            }
            point_sum += distance[two_idx];
            two_idx += 1;
        }
        else if (point_sum == all_distance - point_sum) {
            max_result = point_sum;
            break;
        }
    }
    
    cout << max_result;

    return 0;
}
