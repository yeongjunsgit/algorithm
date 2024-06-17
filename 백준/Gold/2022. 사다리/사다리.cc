#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
    double x, y, c;
    cin >> x >> y >> c;
    
    double start = 0;
    double end = min(x, y);
    
    double result = 0;
    
    while (end - start > 0.001) {
        double mid = (start + end) / 2;
        
        double h1 = pow((pow(x, 2) - pow(mid, 2)), 0.5);
        double h2 = pow((pow(y, 2) - pow(mid, 2)), 0.5);
        
        double tmp_w = (h1*h2) / (h1+h2);
        
        if (tmp_w >= c) {
            result = mid;
            start = mid;
        }
        
        else {
            end = mid;
        }
    }
    
    cout << fixed << setprecision(3) << result;
    
    return 0;
}
