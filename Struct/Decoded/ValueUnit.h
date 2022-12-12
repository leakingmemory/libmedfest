//
// Created by sigsegv on 12/12/22.
//

#ifndef LEGEMFEST_VALUEUNIT_H
#define LEGEMFEST_VALUEUNIT_H

#include <string>

class ValueUnit {
private:
    double value;
    std::string unit;
public:
    ValueUnit() : value(0.0), unit() {}
    ValueUnit(double value, const std::string &unit) : value(value), unit(unit) {}
    double GetValue() const;
    [[nodiscard]] std::string GetUnit() const;
};


#endif //LEGEMFEST_VALUEUNIT_H
