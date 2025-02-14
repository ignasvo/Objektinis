#include "studentai.h"

int main() {
    std::vector<Student> studentai;
    int studentuSk;

    std::cout << "Iveskite studentu skaiciu: ";
    std::cin >> studentuSk;

    for (int i = 0; i < studentuSk; ++i) {
        Student studentas;
        int ndSk;
        char pasirinkimas;

        std::cout << "Iveskite " << i + 1 << "-ojo studento varda ir pavarde: ";
        std::cin >> studentas.vardas >> studentas.pavarde;

        std::cout << "Iveskite atliktu namu darbu skaiciu: ";
        std::cin >> ndSk;

        std::cout << "Iveskite namu darbu rezultatus: ";
        for (int j = 0; j < ndSk; ++j) {
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

        studentai.push_back(studentas);
        studentai.back().galutinisBalas = galutinisBalas;
    }

    std::cout << std::fixed << std::setprecision(2);
    std::cout << "---------------------------------------------\n";
    std::cout << "Pavarde    Vardas    Galutinis balas\n";
    std::cout << "---------------------------------------------\n";

    for (const auto& studentas : studentai) {
        std::cout << studentas.pavarde << " " << studentas.vardas << " " << studentas.galutinisBalas << "\n";
    }

    return 0;
}
