#include <iostream>

using namespace std;

void get_hour(int h, int m, int s, int ah, int am, int as)
{
    as -= s;
    if (as < 0) {
        as += 60;
        m++;
    }
    am -= m;
    if (am < 0) {
        am += 60;
        h++;
    }
    ah -= h;
    
    cout << ah << " " << am << " " << as << "\n";
    
    return;
}

int main()
{
    int ah, am, as, aah, aam, aas, bh, bm, bs, bah, bam, bas, ch, cm, cs, cah, cam, cas;
    cin >> ah >> am >> as >> aah >> aam >> aas >> bh >> bm >> bs >> bah >> bam >> bas >> ch >> cm >> cs >> cah >> cam >> cas;
    
    get_hour(ah, am, as, aah, aam, aas);
    get_hour(bh, bm, bs, bah, bam, bas);
    get_hour(ch, cm, cs, cah, cam, cas);
    
    return 0;
}