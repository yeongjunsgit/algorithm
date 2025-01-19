#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

int N, M;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> N >> M;
    string pokemon, command;
    unordered_map<string, int> poke_num;
    unordered_map<int, string> num_poke;
    
    for (int i=1; i<=N; ++i) {
        cin >> pokemon;
        poke_num[pokemon] = i;
        num_poke[i] = pokemon;
    }
    
    for (int i=0; i<M; ++i) {
        cin >> command;
        
        // c에서 존재하던 atoi 메서드를 이용하여 들어온 command의 숫자 여부를 판별한다.
        // atoi는 숫자가 들어오지 않으면 0을 반환한다. 들어오는 숫자가 자연수기 때문에 0이 나올일이 없어 사용해도 된다!
        int numnum = atoi(command.c_str());
        if (numnum == 0) {
            cout << poke_num[command] << "\n";
        }
        
        else {
            cout << num_poke[numnum] << "\n";
        }
    }

    return 0;
}