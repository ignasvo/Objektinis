#ifndef VEKTORINE_H
#define VEKTORINE_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <cctype>
#include <sstream>
#include <limits>
#include <stdexcept>
#include <chrono>

struct Student {
    std::string vardas, pavarde;
    std::vector<int> namuDarbai;
    int egzaminas;
    double galutinisBalas;
};

bool arTinkamasVardas(const std::string& tekstas);
bool arTinkamasPazymys(int& pazymys);
void generuotiPazymius(Student& studentas, int kiek);
void generuotiStudentus(std::vector<Student>& studentai, int kiek, int ndSk);
double skaiciuotiVidurki(const std::vector<int>& paz);
double skaiciuotiMediana(std::vector<int> paz);
void skaiciuotiGalutiniBala(Student& studentas, char metodas);
void spausdintiRezultatus(const std::vector<Student>& studentai, std::ostream& out);
void vykdytiPrograma();
void nuskaitytiIsFailo(std::vector<Student>& studentai, const std::string& failoVardas);
void rikiuotiStudentus(std::vector<Student>& studentai, char kriterijus);


#endif