#ifndef STUDENTAI_H
#define STUDENTAI_H

#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <string>
#include <numeric>

struct Student {
    std::string vardas;
    std::string pavarde;
    std::vector<int> namuDarbai;
    int egzaminas;
    double galutinisBalas;
};

double skaiciuotiVidurki(const std::vector<int>& pazymiai);
double skaiciuotiMediana(std::vector<int> pazymiai);

#endif
