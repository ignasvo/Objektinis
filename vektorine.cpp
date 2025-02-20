#include "vektorine.h"

std::vector<std::string> vardai = {"Jonas", "Petras", "Marius", "Tomas", "Lukas", "Paulius", "Mantas", "Kazys", "Antanas", "Darius"};
std::vector<std::string> pavardes = {"Kazlauskas", "Petraitis", "Jankauskas", "Jonaitis", "Brazinskas", "Stankevicius", "Kavaliauskas", "Zukauskas", "Kavolis"};

void generuotiPazymius(Student& studentas, int kiek) {
    studentas.namuDarbai.resize(kiek);
    for (int i = 0; i < kiek; ++i) {
        studentas.namuDarbai[i] = rand() % 10 + 1;
    }
    studentas.egzaminas = rand() % 10 + 1;
}

void generuotiStudentus(std::vector<Student>& studentai, int kiek, int ndSk) {
    for (int i = 0; i < kiek; ++i) {
        Student studentas;
        studentas.vardas = vardai[rand() % vardai.size()];
        studentas.pavarde = pavardes[rand() % pavardes.size()];
        generuotiPazymius(studentas, ndSk);
        studentai.push_back(studentas);
    }
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
    return (paz.size() % 2 == 0) ? (paz[paz.size()/2 - 1] + paz[paz.size()/2]) / 2.0 : paz[paz.size()/2];
}

void skaiciuotiGalutiniBala(Student& studentas, char metodas) {
    if (metodas == 'V' || metodas == 'v') {
        studentas.galutinisBalas = 0.4 * skaiciuotiVidurki(studentas.namuDarbai) + 0.6 * studentas.egzaminas;
    } else {
        studentas.galutinisBalas = 0.4 * skaiciuotiMediana(studentas.namuDarbai) + 0.6 * studentas.egzaminas;
    }
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
        std::cout << "\nPasirinkite veiksma:\n";
        std::cout << "1 - Ivesti ranka\n";
        std::cout << "2 - Generuoti pazymius\n";
        std::cout << "3 - Generuoti studentus ir pazymius\n";
        std::cout << "4 - Baigti\n";
        std::cout << "Jusu pasirinkimas: ";
        
        int pasirinkimas;
        std::cin >> pasirinkimas;
        
        if (pasirinkimas == 4) break;
        
        Student studentas;
        if (pasirinkimas == 1) {
            std::cout << "Iveskite varda ir pavarde: ";
            std::cin >> studentas.vardas >> studentas.pavarde;
            
            std::cout << "Iveskite pazymius (-1 baigti): ";
            int paz;
            while (std::cin >> paz && paz != -1) {
                studentas.namuDarbai.push_back(paz);
            }
            
            std::cout << "Egzamino pazymys: ";
            std::cin >> studentas.egzaminas;
            skaiciuotiGalutiniBala(studentas, metodas);
            studentai.push_back(studentas);
        } 
        else if (pasirinkimas == 2) {
            std::cout << "Iveskite varda ir pavarde: ";
            std::cin >> studentas.vardas >> studentas.pavarde;
            
            int kiek;
            std::cout << "Kiek pazymiu generuoti? ";
            std::cin >> kiek;
            generuotiPazymius(studentas, kiek);
            skaiciuotiGalutiniBala(studentas, metodas);
            studentai.push_back(studentas);
        } 
        else if (pasirinkimas == 3) {
            int kiekStudentu, ndSk;
            std::cout << "Kiek studentu generuoti? ";
            std::cin >> kiekStudentu;
            std::cout << "Kiek namu darbu? ";
            std::cin >> ndSk;
            generuotiStudentus(studentai, kiekStudentu, ndSk);
            for (auto& s : studentai) skaiciuotiGalutiniBala(s, metodas);
        }
    }

    spausdintiRezultatus(studentai);
}

int main() {
    vykdytiPrograma();
    return 0;
}