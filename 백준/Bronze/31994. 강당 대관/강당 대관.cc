#include <iostream>

using namespace std;

int best_num = 0, num;
string best_article, article;

int main()
{
    for (int i=0; i<7; ++i) {
        cin >> article >> num;
        if (num > best_num) {
            best_num = num;
            best_article = article;
        }
    }
    
    cout << best_article;

    return 0;
}
