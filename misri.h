#ifndef MISRI_H
#define MISRI_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <cctype>
#include <limits>
#include <sstream>
#include <stdexcept>

const int MAX_PAZ = 100;

struct Student {
    std::string vardas, pavarde;
    int namuDarbai[MAX_PAZ];
    int pazKiekis;
    int egzaminas;
    double galutinisBalas;
};

bool arTinkamasVardas(const std::string& tekstas);
bool arTinkamasPazymys(int& pazymys);
void generuotiPazymius(Student& studentas, int kiek);
void generuotiStudentus(std::vector<Student>& studentai, int kiek, int ndSk);
double skaiciuotiVidurki(const int paz[], int kiekis);
double skaiciuotiMediana(int paz[], int kiekis);
void skaiciuotiGalutiniBala(Student& studentas, char metodas);
void spausdintiRezultatus(const std::vector<Student>& studentai);
void vykdytiPrograma();

#endif