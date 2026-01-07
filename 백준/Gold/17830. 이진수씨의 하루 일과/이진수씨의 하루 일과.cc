#include <iostream>
#include <vector>

using namespace std;

int T, N;


// 2개의 이진수를 곱하는 함수
// 2개의 이진수를 직접 하나씩 올림 하거나 곱하는 것은 시간 초과를 불러올 수 있다 (100만 ^ 2의 횟수)
// 그렇기 때문에 특별한 방식을 찾아내어야 한다. 이진수의 자릿수에 대해서 찾아본 결과
// N개의 자리수의 이진수와 M개의 자리수의 이진수를 서로 곱하면 최대 N+M개의 자리수이고 최소 N+M-1의 자리수가 된다는걸 알 수 있었다.
// 이제 어떠한 경우에서 N+M이 되고, N+M-1이 되는지 알아야하는데 이는 맨앞자리까지 수가 올라와 1자리가 추가가 되는지를 판별해야한다.
// 이를 위해 앞 몇자리를 이용하여 맨앞까지 수가 올라오는지 구분해야한다.
// 현재 N개의 자리수가 모두 1인 이진수 A는 만약 어떠한 이진수 B와 곱했을때, 가장 앞자리가 1이고, 나머지가 0이 아닌 이상 (ex) 1000) 반드시 N+M이 되어보인다.
// 그 이유는 A는 반드시 B보다 길이가 크거나 같음이 보장되고 맨앞자리와 곱하고 이후에 어떠한 값이 나온다면 이는 반드시 맨앞자리에 곱한 숫자와 만나 올림이 발생하기 때문이다.
// ex) 11111, 1000 = 11111000 = 8자리
//     11111, 1001 = 11111000 + 11111 = 맨 앞에까지 올림이 발생하여 9자리 = 100000111
// 즉 예외 케이스를 제외하고 이를 만들면 되겠다.
int get_num_length(string target)
{
    int last_one = -1, one_cnt = 0;
    
    for (int i=0; i<N; ++i) {
        if (target[N-1-i] == '1') {
            one_cnt++;
            last_one = i;
        }
    }
    
    int result = N;
    if (one_cnt == 0) return 1;
    result += last_one;
    if (one_cnt > 1) result++;
    
    return result;
    
}



int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> T;
    
    for (int t=0; t<T; ++t) {
        string data, max_num = "", min_num = "";
        cin >> N >> data;
        
        // 가장 긴 자릿수는 만들 수 있는 가장 높은 수로, 가장 짧은 자릿수는 만들 수 있는  가장 낮은 수로 만들수 있지 않을까?
        for (int i=0; i<N; ++i) {
            if (data[i] == '?') {
                max_num += '1';
                min_num += '0';
            }
            else {
                max_num += data[i];
                min_num += data[i];
            }
        }
        
        cout << get_num_length(max_num) << " " << get_num_length(min_num) << "\n";
        
    }
    

    return 0;
}
