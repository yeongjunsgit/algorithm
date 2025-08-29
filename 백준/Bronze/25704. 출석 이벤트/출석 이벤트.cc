#include <iostream>
using namespace std;

int main() 
{
    int N, price, discount_price = 50001, percent_price = 50001, discount = 0, percent = 0;
    cin >> N >> price;
    
    if (N >= 5) discount = 500;
    if (N >= 10) percent = 10;
    if (N >= 15) discount = 2000;
    if (N >= 20) percent = 4;
    
    discount_price = max(0, price - discount);
    if (percent != 0) percent_price = price - (price / percent);
    
    cout << min(discount_price, percent_price);
    
    return 0;
}