#include <iostream>
#include <vector>

using namespace std;

struct train_menu
{
    long long ticket;
    long long IC_card;
    long long use_card;
};

int N, M;
vector<long long> destinations(100001), use_train(100001, 0);
vector<train_menu> train_info(100001);

long long get_money()
{
    long long result = 0;
    long long now_ride = 0;
    for (int i=1; i<N; ++i) {
        now_ride += use_train[i];
        long long ticket_price = train_info[i].ticket * now_ride;
        long long card_price = train_info[i].IC_card + train_info[i].use_card * now_ride;
        // cout << "현재 " << i << "번째 철도를 " << use_train[i] << "번 탑승하였고, 티켓으로 탄다면 " << ticket_price << "이고, 카드로 탄다면 " << card_price << "이다. \n"; 
        result += min(ticket_price, card_price);
    }
    
    return result;
}


int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M >> destinations[1];
    long long now = destinations[1];
    
    for (int i=2; i<=M; ++i) {
        cin >> destinations[i];
        use_train[min(now, destinations[i])]++;
        use_train[max(now, destinations[i])]--;
        now = destinations[i];
    }
    for (int i=1; i<N; ++i) {
        cin >> train_info[i].ticket >> train_info[i].use_card >> train_info[i].IC_card;
    }
    
    cout << get_money();    


    return 0;
}
