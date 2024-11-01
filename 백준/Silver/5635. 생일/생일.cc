#include <iostream>
#include <string>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N;
    cin >> N;
    
    string min_name, max_name, name;
    int min_year = 2011, min_month = 13, min_day = 32, max_day = 0, max_month = 0, max_year = 0, d, m, y;
    
    for (int i=0; i<N; ++i) {
        cin >> name >> d >> m >> y;
        if (max_year < y) {
            max_name = name;
            max_year = y;
            max_month = m;
            max_day = d;
        }
        else if (max_year == y) {
            if (max_month < m) {
                max_name = name;
                max_year = y;
                max_month = m;
                max_day = d;
            }
            else if (max_month == m) {
                if (max_day < d) {
                    max_name = name;
                    max_year = y;
                    max_month = m;
                    max_day = d;
                }
            }
        }
        
        if (min_year > y) {
            min_name = name;
            min_year = y;
            min_month = m;
            min_day = d;
        }
        else if (min_year == y) {
            if (min_month > m) {
                min_name = name;
                min_year = y;
                min_month = m;
                min_day = d;
            }
            else if (min_month == m) {
                if (min_day > d) {
                    min_name = name;
                    min_year = y;
                    min_month = m;
                    min_day = d;
                }
            }
        }
    }
    
    cout << max_name << "\n";
    cout << min_name;

    return 0;
}
