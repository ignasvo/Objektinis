#include <iostream>
#include "studentai.h"

int main() {
    Student studentas;
    int ndSk;

    std::cout << "Iveskite studento varda ir pavarde: ";
    std::cin >> studentas.vardas >> studentas.pavarde;

    std::cout << "Iveskite atliktu namu darbu skaiciu: ";
    std::cin >> ndSk;

    std::cout << "Iveskite namu darbu rezultatus: ";
    for (int i = 0; i < ndSk; ++i) {
        int paz;
        std::cin >> paz;
        studentas.namuDarbai.push_back(paz);
    }

    std::cout << "Iveskite egzamino rezultata: ";
    std::cin >> studentas.egzaminas;

    std::cout << "Duomenys sekmingai ivesti!\n";
    return 0;
}
