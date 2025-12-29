#include <iostream>
#include <vector>

using namespace std;

int main()
{
    string data;
    cin >> data;
    int zero_area = 0, one_area = 0, d_size = data.size();
    char now_c = data[0];
    for (int i=1; i<d_size; ++i) {
        if (now_c != data[i]) {
            if (now_c == '0') zero_area++;
            else one_area++;
            now_c = data[i];
        } 
    }
    if (data[d_size-1] == '0') zero_area++;
    else one_area++;
    
    cout << min(zero_area, one_area);
    
    return 0;
}
