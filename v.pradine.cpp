#include <iostream>
#include <iomanip>
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

    double vidurkis = skaiciuotiVidurki(studentas.namuDarbai);
    double mediana = skaiciuotiMediana(studentas.namuDarbai);

    double galutinisVid = 0.4 * vidurkis + 0.6 * studentas.egzaminas;
    double galutinisMed = 0.4 * mediana + 0.6 * studentas.egzaminas;

    std::cout << std::fixed << std::setprecision(2);
    std::cout << "---------------------------------------------\n";
    std::cout << "Pavarde    Vardas    Galutinis (Vid.) / Galutinis (Med.)\n";
    std::cout << "---------------------------------------------\n";
    std::cout << studentas.pavarde << " " << studentas.vardas << " " << galutinisVid << " / " << galutinisMed << "\n";

    return 0;
}
