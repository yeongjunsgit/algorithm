#include <iostream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

int N;
vector<long long> int_ip;

void get_ip()
{
    long long subnet_mask = (1ll << 32) - 1;
    bool is_over = false;
    int next = 0;
    while (!is_over) 
    {
        bool is_make = true;
        int base = subnet_mask & int_ip[0];
        for (int i=0; i<N; ++i) {
            int tmp = subnet_mask & int_ip[i];
            if (base != tmp) {
                subnet_mask &= ~(1 << next);
                next++;
                is_make = false;
                break;
            }
        }
        if (is_make == true) {
            is_over = true;
        }
    }
    long long network_ip = subnet_mask & int_ip[0];

    int shift = 32;
    for (int i=1; i<=4; ++i) {
        int octet = ((network_ip >> (shift - (8 * i))) & (1 << 8) - 1);
        cout << octet;
        if (i != 4) {
            cout << '.';
        }
    }
    cout << "\n";
    
    for (int i=1; i<=4; ++i) {
        int octet = ((subnet_mask >> (shift - (8 * i))) & (1 << 8) - 1);
        cout << octet;
        if (i != 4) {
            cout << '.';
        }
    }
    
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> N;
    string ip;
    int_ip.resize(N, 0);
    
    for (int i=0; i<N; ++i) {
        cin >> ip;
        istringstream iss(ip);
        string tmp;
        while (getline(iss, tmp, '.')) {
            long long one_octet = stoi(tmp);
            int_ip[i] <<= 8;
            int_ip[i] |= one_octet;
        }
    }
    
    get_ip();

    return 0;
}
