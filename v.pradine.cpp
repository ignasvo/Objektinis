#include "studentai.h"

int main() {
    Student studentas;
    int ndSk;
    char pasirinkimas;

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

    std::cout << "Pasirinkite skaiciavimo metoda (V - vidurkis, M - mediana): ";
    std::cin >> pasirinkimas;

    double galutinisBalas;
    if (pasirinkimas == 'V' || pasirinkimas == 'v') {
        double vidurkis = skaiciuotiVidurki(studentas.namuDarbai);
        galutinisBalas = 0.4 * vidurkis + 0.6 * studentas.egzaminas;
    } else {
        double mediana = skaiciuotiMediana(studentas.namuDarbai);
        galutinisBalas = 0.4 * mediana + 0.6 * studentas.egzaminas;
    }

    std::cout << std::fixed << std::setprecision(2);
    std::cout << "---------------------------------------------\n";
    std::cout << "Pavarde    Vardas    Galutinis balas\n";
    std::cout << "---------------------------------------------\n";
    std::cout << studentas.pavarde << " " << studentas.vardas << " " << galutinisBalas << "\n";

    return 0;
}
