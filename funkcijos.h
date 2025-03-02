#ifndef FUNKCIJOS_H
#define FUNKCIJOS_H

#include "studentai.h"
#include <string>
#include <vector>

bool arTinkamasVardas(const std::string& tekstas);
bool arTinkamasPazymys(int& pazymys);
void generuotiPazymius(Student& studentas, int kiek);
void generuotiStudentus(std::vector<Student>& studentai, int kiek, int ndSk);
double skaiciuotiVidurki(const std::vector<int>& paz);
double skaiciuotiMediana(std::vector<int> paz);
void skaiciuotiGalutiniBala(Student& studentas, char metodas);
void spausdintiRezultatus(const std::vector<Student>& studentai);
void nuskaitytiIsFailo(std::vector<Student>& studentai, const std::string& failoVardas);
void rikiuotiStudentus(std::vector<Student>& studentai, char kriterijus);
void vykdytiPrograma();

#endif