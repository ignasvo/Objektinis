#include "vektorine.h"

void generuotiPazymius(Student& studentas, int kiek) {
    studentas.namuDarbai.clear();
    for (int i = 0; i < kiek; ++i) {
        studentas.namuDarbai.push_back(rand() % 10 + 1);
    }
    studentas.egzaminas = rand() % 10 + 1;
}

double skaiciuotiVidurki(const std::vector<int>& paz) {
    if (paz.empty()) return 0.0; //Išvengti dalybos iš nulio

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
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "---------------------------------------------\n";
    std::cout << "Vardas     Pavarde     Galutinis balas\n";
    std::cout << "---------------------------------------------\n";

    for (const auto& studentas : studentai) {
        std::cout << studentas.vardas << "       " << studentas.pavarde << "       " << studentas.galutinisBalas << "\n";
    }
}

void vykdytiPrograma() {
    std::vector<Student> studentai;
    srand(time(0));

    char metodas;
    std::cout << "Pasirinkite skaiciavimo metoda (V - vidurkis, M - mediana): ";
    std::cin >> metodas;

    while (true) {
        std::cout << "Pasirinkite veiksma:\n";
        std::cout << "1 - Ivesti ranka\n";
        std::cout << "2 - Generuoti pazymius\n";
        std::cout << "4 - Baigti\n";
        std::cout << "Jusu pasirinkimas: ";
        
        int pasirinkimas;
        std::cin >> pasirinkimas;
        
        if (pasirinkimas == 4) {
            std::cout << "Programa baigta.\n";
            break;
        }
        
        Student studentas;
        std::cout << "Iveskite studento varda ir pavarde: ";
        std::cin >> studentas.vardas >> studentas.pavarde;
        
        if (pasirinkimas == 1) {
            int ndSk;
            std::cout << "Iveskite namu darbu skaiciu: ";
            std::cin >> ndSk;
            std::cout << "Iveskite namu darbu rezultatus: ";
            for (int i = 0; i < ndSk; ++i) {
                int paz;
                std::cin >> paz;
                studentas.namuDarbai.push_back(paz);
            }
            std::cout << "Iveskite egzamino rezultata: ";
            std::cin >> studentas.egzaminas;
        } 
        else if (pasirinkimas == 2) {
            int kiek;
            std::cout << "Kiek pazymiu generuoti? ";
            std::cin >> kiek;
            generuotiPazymius(studentas, kiek);
        }
        
        if (metodas == 'V' || metodas == 'v') {
            studentas.galutinisBalas = 0.4 * skaiciuotiVidurki(studentas.namuDarbai) + 0.6 * studentas.egzaminas;
        } else {
            studentas.galutinisBalas = 0.4 * skaiciuotiMediana(studentas.namuDarbai) + 0.6 * studentas.egzaminas;
        }
        
        studentai.push_back(studentas);
    }

    spausdintiRezultatus(studentai);
}

int main() {
    vykdytiPrograma();
    return 0;
}
