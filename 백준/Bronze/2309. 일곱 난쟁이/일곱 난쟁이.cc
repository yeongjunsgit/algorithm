#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> small_people;
vector<int> pq(7, 0);
int sumsum = 0;
bool is_ok = false;
vector<bool> used(9, false);

void combi(int idx)
{
    if (idx == 7 && sumsum == 100) {
        is_ok = true;
        return;
    }
    
    else {
        for (int i=0; i<9; ++i) {
            if (used[i] == false) {
                sumsum += small_people[i];
                if (sumsum <= 100) {
                    pq[idx] = small_people[i];
                    used[i] = true;
                    combi(idx + 1);
                    if (is_ok == true) {
                        return;
                    }
                    pq[idx] = 0;
                    used[i] = false;
                }
                sumsum -= small_people[i];
            }
        }
        
        return;
    }
}

int main()
{
    int num;
    for (int i=0; i<9; ++i) {
        cin >> num;
        small_people.push_back(num);
    }

    combi(0);

    sort(pq.begin(), pq.end());
    
    for (int a : pq) {
        cout << a << "\n";
    }

    return 0;
}
