#include <iostream>
#include <unordered_map>

using namespace std;
long long X, K;
unordered_map<int, long long> left_socks, right_socks;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> X >> K;
    int num;
    long long result = 0;
    for (int i=0; i<X; ++i) {
        cin >> num;
        left_socks[num]++;
    }
    for (int i=0; i<X; ++i) {
        cin >> num;
        right_socks[num]++;
    }
    
    for (auto a : left_socks) {
        result += (X - right_socks[a.first]) * left_socks[a.first];
    }
    
    cout << result;

    return 0;
}

