#include "studentai.h"

double skaiciuotiVidurki(const std::vector<int>& pazymiai) {
    double suma = 0;
    for (int paz : pazymiai) {
        suma += paz;
    }
    return suma / pazymiai.size();
}

double skaiciuotiMediana(std::vector<int> pazymiai) {
    std::sort(pazymiai.begin(), pazymiai.end());
    size_t dydis = pazymiai.size();
    if (dydis % 2 == 0) {
        return (pazymiai[dydis / 2 - 1] + pazymiai[dydis / 2]) / 2.0;
    } else {
        return pazymiai[dydis / 2];
    }
}
