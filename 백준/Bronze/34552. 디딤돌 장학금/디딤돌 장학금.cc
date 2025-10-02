#include <iostream>

using namespace std;

int main()
{
    int get_money[11];
    int N, level, cast, result = 0;
    float grade;
    for (int i=0; i<11; ++i) {
        cin >> get_money[i];
    }
    cin >> N;
    for (int i=0; i<N; ++i) {
        cin >> level >> grade >> cast;
        grade *= 100;
        if (grade >= 200 && cast >= 17) {
            result += get_money[level];
        }
    }
    
    cout << result;    

    return 0;
}
