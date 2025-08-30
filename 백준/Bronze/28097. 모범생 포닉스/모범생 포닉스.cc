#include <iostream>
#include <vector>

using namespace std;

int N, num, study_time = 0;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    for (int i=0; i<N; ++i) {
        cin >> num;
        study_time += num;
    }
    study_time += 8 * (N-1);
    
    cout << study_time / 24 << " " << study_time % 24;

    return 0;
}