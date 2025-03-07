#ifndef FUNKCIJOS_H
#define FUNKCIJOS_H

#include "studentai.h"
#include <string>
#include <vector>

void testuotiDuomenuApdorojima(const std::string& failoVardas);
bool arTinkamasVardas(const std::string& tekstas);
bool arTinkamasPazymys(int& pazymys);
void generuotiPazymius(Student& studentas, int kiek);
void generuotiStudentus(std::vector<Student>& studentai, int kiek, int ndSk);
double skaiciuotiVidurki(const std::vector<int>& paz);
double skaiciuotiMediana(std::vector<int> paz);
void skaiciuotiGalutiniBala(Student& studentas, char metodas);
void spausdintiRezultatus(const std::vector<Student>& studentai, std::ostream& out);
void nuskaitytiIsFailo(std::vector<Student>& studentai, const std::string& failoVardas);
void rikiuotiStudentus(std::vector<Student>& studentai, char kriterijus);
void generuotiFaila(const std::string& failoPavadinimas, int studentuKiekis, int ndSk, char metodas);
void padalintiStudentus(const std::vector<Student>& studentai, std::vector<Student>& vargsiai, std::vector<Student>& kietiakai);
void apdorotiFaila(const std::string& failoVardas);
void spausdintiStudentusIFaila(const std::vector<Student>& studentai, const std::string& failoVardas);
void vykdytiPrograma();

#endif