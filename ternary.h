#ifndef TERNARY_H
#define TERNARY_H

#include <trit.h>
#include <string>
#include <list>
#include <vector>

class Ternary
{
private:
    std::list<Trit> value;

public:
    Ternary();
    Ternary(std::string t);
    Ternary(std::list<Trit> t);
    void add(char c);
    void add(Trit t);

    Ternary operator +(const Ternary &right);
    Ternary operator *(const Ternary &right);

    ~Ternary();

    friend std::ostream& operator <<(std::ostream& out, const Ternary &ternary) {
        for (auto t: ternary.value) {
            out << t;
        }

        return out;
    }
};

#endif // TERNARY_H
