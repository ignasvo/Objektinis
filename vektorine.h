#ifndef VEKTORINE_H
#define VEKTORINE_H

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>

struct Student {
    std::string vardas, pavarde;
    std::vector<int> namuDarbai;
    int egzaminas;
    double galutinisBalas;
};

void ivestiStudentus(std::vector<Student>& studentai);
double skaiciuotiVidurki(const std::vector<int>& paz);
double skaiciuotiMediana(std::vector<int> paz);
void spausdintiRezultatus(const std::vector<Student>& studentai);

#endif