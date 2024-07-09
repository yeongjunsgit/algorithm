/*
bitset을 쓰자!
비트연산을 비트마스킹으로 하려고 했는데 음.. 비트마스킹은 좀 큰수는 감당이 안된다고 한다.
그래서 bitset을 이용해서 만들자
연산하는 방식이 생각해보면 vector<bool>을 비트 위치에 on/off 를 하는것과 다를것이 없는데 굳이 bitset을 쓰는 이유는?>
1. 사이즈가 많이 변하고 비트연산을 간단한 연산만 한다면 vector<bool>을 사용하자
2. 사이즈가 고정적이고 비트연산이 복잡한 연산을 요구한다면 bitset을 이용하자

이번 경우는 고정 사이즈이기 때문에 bitset을 이용하자
*/

#include <iostream>
#include <vector>
#include <bitset>
#include <map>

using namespace std;

int main()
{
    // 현재 값이 50만개 까지 들어온다 이를 sstream으로 받을 수 없으므로 50만개를 빠르게 받기위해 설정
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int num;
    
    // bitset의 사이즈를 적자 (2^25)
    const int BITSET_SIZE = 33554432;
    // 정해진 사이즈로 bitset을 만들자
    bitset<BITSET_SIZE> bitmask;
    
    // 메모리 제한 문제라서 sstream으로 모든 값을 string data에 저장하면 메모리 초과가 나는듯 하다 한개의 변수에
    // 계속해서 저장하는 방식으로 하자
    while (cin >> num) {
        // test()를 이용해서 현재 bitset에 해당 값이 설정(이미 지나친적이 있는지)를 판단한다
        if (bitmask.test(num)) {
            // 만약 이미 값이 설정되어 있다면 패스
            continue;
        }
        // 만약 이미 없는 값이라면 해당 값을 set()를 이용하여 bitset에 설정
        bitmask.set(num);
        // 해당 값을 출력
        cout << num << " ";
    }

    return 0;
}
