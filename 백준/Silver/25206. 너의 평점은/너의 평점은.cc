#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

int main()
{
    
    double total = 0.0;
    double kinds_of = 0;
    
    for (int i=0; i<20; ++i) {
        string class_name, grade;
        double class_point;
        
        cin >> class_name >> class_point >> grade;
        
        if (grade == "A+") {
            total += class_point * 4.5;
            kinds_of += class_point;
        }
        
        else if (grade == "A0") {
            total += class_point * 4.0;
            kinds_of += class_point;
        }
        
        else if (grade == "B+") {
            total += class_point * 3.5;
            kinds_of += class_point;
        }
        
        else if (grade == "B0") {
            total += class_point * 3.0;
            kinds_of += class_point;
        }
        
        else if (grade == "C+") {
            total += class_point * 2.5;
            kinds_of += class_point;
        }
        
        else if (grade == "C0") {
            total += class_point * 2.0;
            kinds_of += class_point;
        }
        
        else if (grade == "D+") {
            total += class_point * 1.5;
            kinds_of += class_point;
        }
        
        else if (grade == "D0") {
            total += class_point * 1.0;
            kinds_of += class_point;
        }
        
        else if (grade == "F") {
            total += class_point * 0.0;
            kinds_of += class_point;
        }
        
        else if (grade == "P") {
            continue;
        }
    }

    double result = total / kinds_of;

    cout << fixed << setprecision(6) << result;

    return 0;
}
