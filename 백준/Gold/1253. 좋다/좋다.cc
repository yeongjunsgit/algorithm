#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int N, result = 0;
vector<int> numbers;
unordered_map<int, int> num_cnt;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    numbers.resize(N);
    for (int i=0; i<N; ++i) {
        cin >> numbers[i];
        num_cnt[numbers[i]]++;
    }
    
    for (int i=0; i<N; ++i) {
        for (int j=i+1; j<N; ++j) {
            int tmp = numbers[i] + numbers[j];
            if (num_cnt.find(tmp) != num_cnt.end() && num_cnt[tmp] != 0) {
                // 본인이 사용되면 안된다. 0이 있으면 본인을 사용하면 반드시 값이 만들어지는데 이를 방지하기 위한 코드
                // 만약 0이 있고, 본인과 같은 값을 가진 다른 수가 있다면 이를 이용하여 만들 수 있으니, 이는 가능하므로 패스
                if ((tmp == numbers[i] || tmp == numbers[j]) && num_cnt[tmp] == 1) continue;
                // 0이 2개일 경우도 따로 처리해주어야한다.
                if (tmp == numbers[i] && tmp == numbers[j] && num_cnt[tmp] < 3) continue;
                result += num_cnt[tmp];
                num_cnt[tmp] = 0;
            }
        }
    }
    
    cout << result;    

    return 0;
}

