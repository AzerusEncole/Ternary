#include <iostream>
#include "ternary.h"

#include <vector>

using namespace std;

int main()
{

    Trit trit = Trit(U) || Trit(F);

    cout << "U || F : " << trit << endl;

    trit = Trit(T) && Trit(F);

    cout << "T && F : " << trit << endl;

    trit = Trit(F).impl(Trit(T));

    cout << "F -> T : " << trit << endl;

    trit = !Trit(F);

    cout << "!F : " << trit << endl;

    Ternary ternary1 = Ternary("FTUUTUUT");   // -1430
    Ternary ternary2 = Ternary("TUFUFTF");    // 641
    Ternary result = ternary1 + ternary2;     // -1430 + 641 = -789

    cout << "TFUUTUUT + TUFUFTF = " << result << " (-1430 + 641 = -789)" << endl;

    ternary1 = Ternary("FTUFTT");     // -167
    ternary2 = Ternary("TUFF");       // 23
    result = ternary1 * ternary2;     // 3841

    cout << "TFUTFF + TUFF = " << result << " (-167 * 23 = -3841)" << endl;

//    Ternary t1 = Ternary("TT");
//    Ternary t2 = Ternary("TFUFU");

//    Ternary t3 = t1 * t2;

//    cout << t3 << endl;

//    cout << result << endl;

//    vector<int> *v = new vector<int>();
//    v->push_back(1);
//    v->push_back(2);
//    v->push_back(3);
//    v->push_back(4);

//    for (auto i: *v) {
//        cout << i;
//    }
}
