/*처음 봤을땐 DP를 이용한 3차원 배낭문제처럼 풀까했으나, 테스트케이스가 최대 1000개에 
 배열도 10억짜리 배열을 만들어야해서 안되어 보였다. 그 다음으론 그리디일까 싶었지만, 반드시 비싼 것만으로 하는 등의
 그리디한 요소가 없어서 불가하다고 판단했다. 이러면 브루트포스 밖에 없어보이는데 브루트포스로 하더라도 1000^3은 터질것 같아서
 고민하다가 결국 분류를 보았다. 그런데 왠걸 브루트포스가 아닌가? 그래서 결국 블로그를 보고 접근 방식을 찾아보았다.
 방식은 의외로 간단했는데, 1개의 조합식을 고정해두고 나머지에 대해서 순회를 하는 것이다
 예시로 들자면 AB를 0~가능한 개수까지 순회하면서 정해진 AB를 만들고 남은 나머지 재료로 BC와 CA를 만드는 것이다.
 이때, BC 또한 0 ~ AB를 만들고 남은 개수 중에서 가능한 개수까지 순회하고 나머지 재료를 CA를 만들어서 총합을 구하는 것이다.
 이러면 1000^2로 계산을 줄일 수 있어 브루트포스가 가능해지는 것이다!
 참... 방식이 떠오르지 않을 법한 문제였는데 잘 외워두자..!
*/ 


#include <iostream>
#include <vector>

using namespace std;

int T, A, B, C, AB, BC, CA;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> T;
    for (int t=0; t<T; ++t) {
        cin >> A >> B >> C >> AB >> BC >> CA;
        int A_B_range = min(A, B), result = 0;
        
        for (int i=0; i<=A_B_range; ++i) {
            int B_C_range = min(B - i, C);
            for (int j=0; j<=B_C_range; ++j) {
                int tmp = (AB * i) + (BC * j) + (CA * min(A - i, C - j));
                if (tmp > result) result = tmp;
            }
        }
        
        cout << result << "\n";
        
    }
    
    

    return 0;
}
