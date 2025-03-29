#include <iostream>
#include <vector>

using namespace std;


int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int N;
    cin >> N;
    vector<int> numbers, checking;
    numbers.resize(N);
    int now_length = 0;
    int result = 0;
    for (int i=0; i<N; ++i) {
        cin >> numbers[i];
        if (i != 0 && numbers[i - 1] == numbers[i]) {
            checking.push_back(now_length);
            now_length = 1;
        }
        else {
            now_length++;
            result = max(result, now_length);
        }
    }
    checking.push_back(now_length);
    
    int now_size = checking.size();
    if (now_size >= 3) {
        for (int i=0; i<now_size - 2; ++i) {
            int tmp = checking[i] + checking[i + 1] + checking[i + 2];
            result = max(result, tmp);
        }
    }
    else if (now_size == 2) {
        result = max(result, checking[0] + checking[1]);
    }
    
    cout << result;

    return 0;
}