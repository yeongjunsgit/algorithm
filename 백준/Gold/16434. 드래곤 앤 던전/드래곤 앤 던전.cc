#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
long long tmp_HP = 0, HP = 0, attack;

void explore_room(int type, long long ATP, long long target_HP)
{
    // 현재 공격력으로 몬스터를 무찌른다. 이때 필요한 체력을 계산해야함!
    if (type == 1) {
        int turn = target_HP % attack == 0 ? target_HP / attack : target_HP / attack + 1;
        tmp_HP += ATP * (turn - 1);
    }
    // 공격력과 체력을 회복시켜주는 포션을 마신다! 체력이 회복되었다면 그만큼 최대 체력을 아낄 수 있다!
    // 최대 체력의 한도까지 늘려주지 못한다고 하니 이를 고려해서 코드를 작성해야한다.
    else {
        attack += ATP;
        if (tmp_HP -= target_HP < 0) {
            HP = max({HP, tmp_HP});
        }
        tmp_HP = max(0ll, tmp_HP - target_HP);
    }
    
    return;
    
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> attack;
    int type, ATP, target_HP;
    
    for (int i=0; i<N; ++i) {
        cin >> type >> ATP >> target_HP;
        explore_room(type, ATP, target_HP);
        
    }
    HP = max(HP, tmp_HP);
    
    cout << HP + 1;

    return 0;
}