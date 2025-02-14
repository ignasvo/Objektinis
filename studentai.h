#ifndef STUDENTAI_H
#define STUDENTAI_H

#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include <iomanip>

struct Student {
    std::string vardas, pavarde;
    std::vector<int> namuDarbai;
    int egzaminas;
};

double skaiciuotiVidurki(const std::vector<int>& pazymiai);
double skaiciuotiMediana(std::vector<int> pazymiai);

#endif
