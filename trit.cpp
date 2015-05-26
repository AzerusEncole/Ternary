#include "trit.h"

Trit::Trit() {}

Trit::Trit(char c) {
    switch (c) {
        case 'T':
            value = T;
            break;
        case 'F':
            value = F;
            break;
        case 'U':
            value = U;
            break;
    }
}

Trit::Trit(Trinity t) {
    value = t;
}

Trinity Trit::getValue() const {
    return value;
}

Trit Trit::operator ||(const Trit &right) const {
    return Trit(disjunction[this->value][right.value]);
}

Trit Trit::operator &&(const Trit &right) const {
    return Trit(conjunction[this->value][right.value]);
}

Trit Trit::operator !() const {
    return Trit(negative[this->value]);
}

Trit Trit::impl(const Trit &right) const {
    return Trit(implication[this->value][right.value]);
}

Trit::~Trit() {}

