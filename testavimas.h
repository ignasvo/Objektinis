#ifndef TESTAVIMAS_H
#define TESTAVIMAS_H

#include <vector>
#include <list>
#include <deque>
#include <string>
#include <chrono>
#include <fstream>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <typeinfo>

// Studento struktūra
struct Student {
    std::string vardas, pavarde;
    std::vector<int> namuDarbai;
    int egzaminas;
    double galutinisBalas;
};

// Šabloninės funkcijos
template<typename Container>
void nuskaitytiIsFailo(Container& studentai, const std::string& failoVardas);

template<typename Container>
void rikiuotiStudentus(Container& studentai, char kriterijus);

template<typename Container>
void strategija1(const Container& studentai, Container& vargsiai, Container& kietiakai);

template<typename Container>
void strategija2(Container& studentai, Container& vargsiai);

template<typename Container>
void strategija3(Container& studentai, Container& vargsiai);

template<typename Container>
void testuotiStrategijas(const std::string& failoVardas);

void testuotiVisusKonteinerius(const std::string& failoVardas);

// Funkcija, grąžinanti konteinerio pavadinimą
template<typename Container>
struct ContainerName {
    static std::string name() { return typeid(Container).name(); }
};

// Specializacijos kiekvienam konteineriui
template<>
struct ContainerName<std::vector<Student>> {
    static std::string name() { return "Vector"; }
};

template<>
struct ContainerName<std::list<Student>> {
    static std::string name() { return "List"; }
};

template<>
struct ContainerName<std::deque<Student>> {
    static std::string name() { return "Deque"; }
};

#endif
