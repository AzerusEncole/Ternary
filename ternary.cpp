#include "ternary.h"
#include <cmath>

Ternary::Ternary() {
    value = std::list<Trit>();
}

Ternary::Ternary(std::string t) {
    value = std::list<Trit>();

    for (auto c : t) {
        value.push_back(Trit(c));
    }
}

Ternary::Ternary(std::list<Trit> t) {
    value = t;
}

void Ternary::add(char c) {
    add(Trit(c));
}

void Ternary::add(Trit c) {
    value.push_back(c);
}

Ternary Ternary::operator +(const Ternary &right) {
    auto larger = this->value;
    auto lower = right.value;

    int diff = larger.size() - lower.size();

    if (diff != 0) {
        if (diff < 0) {
            auto temp = lower;
            lower = larger;
            larger = temp;
        }

        diff = std::fabs(diff);

        for (int i = 0; i < diff; i++) {
            lower.push_front(U);
        }
    }

    auto itLarger = larger.rbegin();
    auto itLower = lower.rbegin();

    auto result = Ternary();
    auto transfer = U;

    while (itLarger != larger.rend()) {
        auto lar = (*itLarger).getValue();
        auto low = (*itLower).getValue();

        if (lar == T && low == T) {

            if (transfer == T) {
                result.value.push_front(Trit(U));
            } else if (transfer == F) {
                result.value.push_front(Trit(T));
                transfer = U;
            } else {
                result.value.push_front(Trit(F));
                transfer = T;
            }

        } else if (lar == F && low == F) {

            if (transfer == T) {
                result.value.push_front(Trit(F));
                transfer = U;
            } else if (transfer == F) {
                result.value.push_front(Trit(U));
            } else {
                result.value.push_front(Trit(T));
                transfer = F;
            }

        } else {
            auto trit = Trit(lar).sum(Trit(low));
            auto trinity = trit.getValue();

            if (transfer == T) {

                if (trinity == T) {
                    result.value.push_front(Trit(F));
                } else if (trinity == F) {
                    result.value.push_front(Trit(U));
                    transfer = U;
                } else {
                    result.value.push_front(Trit(T));
                    transfer = U;
                }

            } else if (transfer == F) {

                if (trinity == T) {
                    result.value.push_front(Trit(U));
                    transfer = U;
                } else if (trinity == F) {
                    result.value.push_front(Trit(T));
                    transfer = F;
                } else {
                    result.value.push_front(Trit(F));
                    transfer = U;
                }

            } else {
                result.value.push_front(trit);
            }

        }
        ++itLarger;
        ++itLower;
    }

    if (transfer != U) {
        result.value.push_front(Trit(transfer));
    }

    auto itResult = result.value.begin();

    while ((*itResult).getValue() == U) {
        result.value.pop_front();
        ++itResult;
    }

    return result;
}


Ternary Ternary::operator *(const Ternary &right) {
    auto leftTern = this->value;
    auto rightTern = right.value;

    auto itRightTern = rightTern.rbegin();
    int nulls = 0;

    std::vector<Ternary> terns;

    while (itRightTern != rightTern.rend()) {
        auto trit = (*itRightTern);
        Ternary tern;

        auto itLeftTern = leftTern.rbegin();

        while (itLeftTern != leftTern.rend()) {
            tern.value.push_front(trit && (*itLeftTern));
            itLeftTern++;
        }

        for (int i = 0; i < nulls; i++) {
            tern.add(Trit('U'));
        }

        terns.push_back(tern);

        ++nulls;
        itRightTern++;
    }


    Ternary sum = terns[0];

    if (terns.size() > 1) {
        for (int i = 1; i < terns.size(); i++) {
            sum = sum + terns[i];
        }
    }

    return sum;
}

Ternary::~Ternary() {}

