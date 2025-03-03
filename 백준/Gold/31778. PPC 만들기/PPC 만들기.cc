#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, K;
vector<char> PPC;
vector<int> after_C;
priority_queue<int, vector<int>, greater<int> > C_que;
priority_queue<int, vector<int>, less<int> > P_que;
long long result = 0;

void change_loca()
{
    if (P_que.size() > 0 && C_que.size() > 0) {
        for (int i=0; i<K; ++i) {
            int best_C = C_que.top();
            int best_P = P_que.top();
            
            if (best_C > best_P) {
                break;
            }
            
            C_que.pop(); P_que.pop();
            PPC[best_C] = 'P'; PPC[best_P] = 'C';
            C_que.push(best_P); P_que.push(best_C);
        }
        
        for (int i=N-1; i>=0; --i) {
            if (PPC[i] == 'C') {
                if (i != N-1) {
                    after_C[i] = after_C[i + 1] + 1; 
                }
                else {
                    after_C[i] = 1;
                }
            }
            else {
                if (i != N-1) {
                    after_C[i] = after_C[i + 1]; 
                }
            }
        }
    }
    
    return;

}

void get_PPC()
{
    
    if (P_que.size() > 0 && C_que.size() > 0) {
        while (!P_que.empty()) {
            long long now_P = P_que.top();
            P_que.pop();
            long long before_P = P_que.size();
            
            result += after_C[now_P] * before_P;
        }
    }
    
    cout << result;
    
    return;
}


int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> K;
    PPC.resize(N);
    after_C.resize(N, 0);
    string data;
    cin >> data;
    
    for (int i=0; i<N; ++i) {
        PPC[i] = data[i];
        if (data[i] == 'C') {
            C_que.push(i);
        }
        else {
            P_que.push(i);
        }
    }
    
    change_loca();
    get_PPC();

    return 0;
}
