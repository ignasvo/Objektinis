#ifndef MISRI_H
#define MISRI_H

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>

const int MAX_PAZ = 100;

struct Student {
    std::string vardas;
    std::string pavarde;
    int namuDarbai[MAX_PAZ];
    int pazKiekis;
    int egzaminas;
    double galutinisBalas;
};

void ivestiStudentus(std::vector<Student>& studentai);
double skaiciuotiVidurki(const int paz[], int kiekis);
double skaiciuotiMediana(int paz[], int kiekis);
void spausdintiRezultatus(const std::vector<Student>& studentai);

#endif