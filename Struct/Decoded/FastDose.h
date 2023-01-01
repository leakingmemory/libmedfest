//
// Created by sigsegv on 1/1/23.
//

#ifndef LEGEMFEST_FASTDOSE_H
#define LEGEMFEST_FASTDOSE_H


class FastDose {
private:
    int dagerPa;
    int dagerAv;
public:
    FastDose() : dagerPa(), dagerAv() {}
    FastDose(int dagerPa, int dagerAv) : dagerPa(dagerPa), dagerAv(dagerAv) {}
    [[nodiscard]] int GetDagerPa() const;
    [[nodiscard]] int GetDagerAv() const;
};


#endif //LEGEMFEST_FASTDOSE_H
