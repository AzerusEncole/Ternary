#ifndef TRIT_H
#define TRIT_H

#include <iostream>
#include "trinity.h"

class Trit
{
private:
    Trinity value;
    Trinity negative[3] = {T, U, F};

    Trinity disjunction[3][3] = {{F, U, T},
                                 {U, U, T},
                                 {T, T, T}};

    Trinity conjunction[3][3] = {{T, U, F},
                                 {U, U, U},
                                 {F, U, T}};

    Trinity implication[3][3] = {{T, T, T},
                                 {T, U, U},
                                 {T, U, F}};



    Trinity addition[3][3] = {{T, F, U},
                              {F, U, T},
                              {U, T, F}};

public:
    Trit();
    Trit(char c);
    Trit(Trinity t);
    Trinity getValue() const;
    Trit operator ||(const Trit &right) const;
    Trit operator &&(const Trit &right) const;
    Trit operator !() const;
    Trit impl(const Trit &right) const;

    Trit sum(Trit right) {
        return Trit(addition[this->value][right.value]);
    }

    ~Trit();

    friend std::ostream& operator <<(std::ostream& out, const Trit &t) {
        char result;
        switch (t.getValue()) {
            case T:
                result = 'T';
                break;
            case F:
                result = 'F';
                break;
            case U:
                result = 'U';
                break;
        }

        return out << result;
    }
};

#endif // TRIT_H
