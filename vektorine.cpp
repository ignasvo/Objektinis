#include "vektorine.h"

void ivestiStudentus(std::vector<Student>& studentai) {
    char testi;
    do {
        Student studentas;
        char pasirinkimas;
        
        std::cout << "Iveskite studento varda ir pavarde: ";
        std::cin >> studentas.vardas >> studentas.pavarde;

        std::cout << "Iveskite namu darbu pazymius (baigti -1): ";
        int paz;
        while (std::cin >> paz && paz != -1) {
            studentas.namuDarbai.push_back(paz);
        }

        std::cout << "Iveskite egzamino rezultata: ";
        std::cin >> studentas.egzaminas;

        std::cout << "Pasirinkite skaiciavimo metoda (V - vidurkis, M - mediana): ";
        std::cin >> pasirinkimas;

        if (pasirinkimas == 'V' || pasirinkimas == 'v') {
            studentas.galutinisBalas = 0.4 * skaiciuotiVidurki(studentas.namuDarbai) + 0.6 * studentas.egzaminas;
        } else {
            studentas.galutinisBalas = 0.4 * skaiciuotiMediana(studentas.namuDarbai) + 0.6 * studentas.egzaminas;
        }

        studentai.push_back(studentas);

        std::cout << "Ar norite ivesti kita studenta? (T/N): ";
        std::cin >> testi;
    } while (testi == 'T' || testi == 't');
}

double skaiciuotiVidurki(const std::vector<int>& paz) {
    if (paz.empty()) return 0.0;

    double suma = 0;
    for (int p : paz) suma += p;
    return suma / paz.size();
}

double skaiciuotiMediana(std::vector<int> paz) {
    if (paz.empty()) return 0.0;

    std::sort(paz.begin(), paz.end());
    int dydis = paz.size();
    
    if (dydis % 2 == 0)
        return (paz[dydis / 2 - 1] + paz[dydis / 2]) / 2.0;
    else
        return paz[dydis / 2];
}

void spausdintiRezultatus(const std::vector<Student>& studentai) {
    std::cout << "---------------------------------------------\n";
    std::cout << "Vardas     Pavarde     Galutinis balas\n";
    std::cout << "---------------------------------------------\n";

    for (const auto& studentas : studentai) {
        std::cout << studentas.vardas << "       " << studentas.pavarde << "       " << studentas.galutinisBalas << "\n";
    }
}

int main() {
    std::vector<Student> studentai;
    ivestiStudentus(studentai);
    spausdintiRezultatus(studentai);
    return 0;
}
