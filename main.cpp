#include <iostream>
#include "ternary.h"

#include <vector>

using namespace std;

int main()
{

    Trit trit = Trit(U) || Trit(F);

    cout << "U || F : " << trit << endl << endl;

    trit = Trit(T) && Trit(F);

    cout << "T && F : " << trit << endl << endl;

    trit = Trit(F).impl(Trit(T));

    cout << "F -> T : " << trit << endl << endl;

    trit = !Trit(F);

    cout << "!F : " << trit << endl << endl;

    Ternary ternary1 = Ternary("FTUUTUUT");   // -1430
    Ternary ternary2 = Ternary("TUFUFTF");    // 641
    Ternary result = ternary1 + ternary2;     // -1430 + 641 = -789

    cout << "TFUUTUUT + TUFUFTF = " << result << " (-1430 + 641 = -789)" << endl << endl;

    result = ternary1 - ternary2;
    cout << "TFUUTUUT - TUFUFTF = " << result << " (-1430 - 641 = -2071)" << endl << endl;

    ternary1 = Ternary("FTUFTT");     // -167
    ternary2 = Ternary("TUFF");       // 23
    result = ternary1 * ternary2;     // -3841

    cout << "TFUTFF * TUFF = " << result << " (-167 * 23 = -3841)" << endl << endl;

    ternary1 = Ternary("FTTFFU");
    ternary2 = Ternary("TFT");
    result = ternary1 / ternary2;

    cout << "FTTFFU / TFT = " << result << " (-147 / 7 = -21)" << endl << endl;

    ternary1 = Ternary();
    cout << "Десятичное число 103 к троичному: " << ternary1.decToTri(103) << endl << endl;
    cout << "Десятичное число -503 к троичному: " << ternary1.decToTri(-503) << endl << endl;

    ternary1 = Ternary("TTFTT");
    cout << "Троичное число TTFTT к десятичному: " << ternary1.triToDec() << endl << endl;

    ternary1 = Ternary("FTUFTUT");
    cout << "Троичное число FTUFTUT к десятичному: " << ternary1.triToDec() << endl << endl;

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
