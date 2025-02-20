#ifndef MISRI_H
#define MISRI_H

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <cstdlib>
#include <ctime>

const int MAX_PAZ = 100;

struct Student {
    std::string vardas, pavarde;
    int namuDarbai[MAX_PAZ];
    int pazKiekis;
    int egzaminas;
    double galutinisBalas;
};

void generuotiPazymius(Student& studentas, int kiek);
void generuotiStudentus(std::vector<Student>& studentai, int kiek, int ndSk);
double skaiciuotiVidurki(const int paz[], int kiekis);
double skaiciuotiMediana(int paz[], int kiekis);
void skaiciuotiGalutiniBala(Student& studentas, char metodas);
void spausdintiRezultatus(const std::vector<Student>& studentai);
void vykdytiPrograma();

#endif