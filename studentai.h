#ifndef STUDENTAI_H
#define STUDENTAI_H

#include <string>
#include <vector>

struct Student {
    std::string vardas, pavarde;
    std::vector<int> namuDarbai;
    int egzaminas;
    double galutinisBalas;
};

#endif