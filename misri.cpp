#include "misri.h"

void ivestiStudentus(std::vector<Student>& studentai) {
    char testi;

    do {
        Student studentas;
        studentas.pazKiekis = 0;

        std::cout << "Iveskite studento varda ir pavarde: ";
        std::cin >> studentas.vardas >> studentas.pavarde;

        std::cout << "Iveskite namu darbu rezultatus (iveskite -1, jei baigete):\n";
        int paz;
        while (studentas.pazKiekis < MAX_PAZ) {
            std::cin >> paz;
            if (paz == -1) break;
            studentas.namuDarbai[studentas.pazKiekis++] = paz;
        }

        std::cout << "Iveskite egzamino rezultata: ";
        std::cin >> studentas.egzaminas;

        char pasirinkimas;
        std::cout << "Pasirinkite skaiciavimo metoda (V - vidurkis, M - mediana): ";
        std::cin >> pasirinkimas;

        if (pasirinkimas == 'V' || pasirinkimas == 'v') {
            studentas.galutinisBalas = 0.4 * skaiciuotiVidurki(studentas.namuDarbai, studentas.pazKiekis) + 0.6 * studentas.egzaminas;
        } else {
            studentas.galutinisBalas = 0.4 * skaiciuotiMediana(studentas.namuDarbai, studentas.pazKiekis) + 0.6 * studentas.egzaminas;
        }

        studentai.push_back(studentas);

        std::cout << "Ar norite ivesti kita studenta? (T/N): ";
        std::cin >> testi;
    } while (testi == 'T' || testi == 't');
}

double skaiciuotiVidurki(const int paz[], int kiekis) {
    if (kiekis == 0) return 0.0;
    int suma = 0;
    for (int i = 0; i < kiekis; i++) suma += paz[i];
    return (double)suma / kiekis;
}

double skaiciuotiMediana(int paz[], int kiekis) {
    if (kiekis == 0) return 0.0;
    std::sort(paz, paz + kiekis);
    if (kiekis % 2 == 0) {
        return (paz[kiekis / 2 - 1] + paz[kiekis / 2]) / 2.0;
    } else {
        return paz[kiekis / 2];
    }
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
