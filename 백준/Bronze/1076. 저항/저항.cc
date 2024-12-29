#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <cmath>

using namespace std;

unordered_map<string, char> num_power = {{"black", '0'}, {"brown", '1'}, {"red", '2'}, {"orange", '3'}, {"yellow", '4'},
    {"green", '5'}, {"blue", '6'}, {"violet", '7'}, {"grey", '8'}, {"white", '9'}
};

int main()
{
    string one, two, three;
    cin >> one >> two >> three;
    
    long long result = 0;
    result += (num_power[one] - '0') * 10;
    result += num_power[two] - '0';
    result *= pow(10, (num_power[three] - '0'));
    
    cout << result;
    
    return 0;
}
