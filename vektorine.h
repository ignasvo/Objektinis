#ifndef VEKTORINE_H
#define VEKTORINE_H

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>
#include <cstdlib>
#include <ctime>


struct Student {
    std::string vardas, pavarde;
    std::vector<int> namuDarbai;
    int egzaminas;
    double galutinisBalas;
};

double skaiciuotiVidurki(const std::vector<int>& paz);
double skaiciuotiMediana(std::vector<int> paz);
void spausdintiRezultatus(const std::vector<Student>& studentai);
void generuotiStudentus(std::vector<Student>& studentai, int kiek, int ndSk);
void vykdytiPrograma();

#endif