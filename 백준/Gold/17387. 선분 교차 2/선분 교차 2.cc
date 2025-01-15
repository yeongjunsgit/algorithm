#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// ccw알고리즘을 이용해 2개의 점(즉, 선분) 에 대해 1개의 점에 대한 외적이 어느 방향에 있는지 구분한다.
// 만약 결과값이 음수라면 시계방향, 양수라면, 반시계방향, 0이라면 평행이다.
int CCW(long long x1, long long y1, long long x2, long long y2, long long tx, long long ty)
{
    long long target = (x2 - x1) * (ty - y1) - (tx - x1) * (y2 - y1);
    
    if (target > 0) return 1;
    else if (target < 0) return -1;
    else return 0;
}

int main()
{
    long long x1, y1, x2, y2, x3, y3, x4, y4;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;

    // 한 선분에 대해, 다른 선분을 구성하는 점 2개에 대한 외적의 방향을 확인한다. 
    int base_one = CCW(x1, y1, x2, y2, x3, y3);
    int base_two = CCW(x1, y1, x2, y2, x4, y4);
    int base_three = CCW(x3, y3, x4, y4, x1, y1);
    int base_four = CCW(x3, y3, x4, y4, x2, y2);
    
    // 만약 두 점에 대한 외적의 방향이 서로 다르다면 (두 결과값의 곱이 음수라면 -와 + 가 곱해진것으로 다른 방향이다.)
    // 교차하고 있다는 뜻이다.
    // 하지만 2개의 방향이 서로 다르다고 하더라도 반드시 교차하는 것은 아니다. 만약 해당 선분이 교차하는 듯이 구성되어있어도
    // 자신의 선분의 안에 들어와 있지 않다면 교차하지 않는 것이다 이를 확인하기 위해 비교 대상이었던 선분을 기준으로 잡아
    // 다시 서로 교차하는지 비교한다. 만약 두 선분이 만나지 않는다면 두 조건문 중 한 개의 조건문에서는 비교 대상인 두 점에 대한 외적이 같은 방향으로 나온다.
    if (base_one * base_two <= 0 && base_three * base_four <= 0) {
        
        // 만약에 두 조건문 모두 0의 값을 갖는다면 완벽히 평행하고 있다는 뜻이다 하지만 이는 반드시 교차한다는 뜻은 아니다.
        // 두 개의 선분이 같은 선상에 존재할 뿐 두 선분이 떨어져 있을 수도 있다. 이때는 좌표값을 이용해 두 선분이 겹쳐져 있는지 확인하여
        // 교차 여부를 판단해야 한다.
        if (base_one * base_two == 0 && base_three * base_four == 0) {
            // 비교하기 쉽게 좌표를 정렬한다.
            // 대각선으로 일직선일때도 판단해야하기 때문에 pair를 이용하여 손쉽게 판단한다.
            pair<long long, long long> one = {x1, y1};
            pair<long long, long long> two = {x2, y2};
            pair<long long, long long> three = {x3, y3};
            pair<long long, long long> four = {x4, y4};
            
            if (one > two) {
                swap(one, two);
            }
            if (three > four) {
                swap(three, four);
            }
            
            // 만약 일직선 상의 두 선분이 겹친다면 1을 반환
            if (three <= two && one <= four) {
                cout << 1;
            }
            else {
                cout << 0;
            }
        }
        // 만약 둘 다 0이 아니라면 잘 교차하고 있으므로 1을 반환
        else {
            cout << 1;
        }
    }
    else {
        cout << 0;
    }

    return 0;
}
