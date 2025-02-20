#include "vektorine.h"

std::vector<std::string> vardai = {"Jonas", "Petras", "Marius", "Tomas", "Lukas", "Paulius", "Mantas", "Kazys", "Antanas", "Darius"};
std::vector<std::string> pavardes = {"Kazlauskas", "Petraitis", "Jankauskas", "Jonaitis", "Brazinskas", "Stankevicius", "Kavaliauskas", "Zukauskas", "Kavolis"};

void generuotiStudentus(std::vector<Student>& studentai, int kiek, int ndSk) {
    for (int i = 0; i < kiek; ++i) {
        Student studentas;
        studentas.vardas = vardai[rand() % vardai.size()];
        studentas.pavarde = pavardes[rand() % pavardes.size()];

        studentas.namuDarbai.resize(ndSk);
        for (int j = 0; j < ndSk; ++j) {
            studentas.namuDarbai[j] = rand() % 10 + 1;
        }

        studentas.egzaminas = rand() % 10 + 1;
        studentai.push_back(studentas);
    }
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
    std::cout << "Pasirinkite skaiciavimo metoda visiems studentams (V - vidurkis, M - mediana): ";
    std::cin >> metodas;

    while (true) {
        std::cout << "Pasirinkite veiksma:\n";
        std::cout << "1 - Ivesti ranka\n";
        std::cout << "2 - Generuoti pazymius\n";
        std::cout << "3 - Generuoti studentus ir pazymius\n";
        std::cout << "4 - Baigti\n";
        std::cout << "Jusu pasirinkimas: ";
        
        int pasirinkimas;
        std::cin >> pasirinkimas;
        
        if (pasirinkimas == 4) {
            std::cout << "Programa baigta.\n";
            break;
        }
        
        Student studentas;
        
        if (pasirinkimas == 1) {
            std::cout << "Iveskite studenta (vardas pavarde): ";
            std::cin >> studentas.vardas >> studentas.pavarde;

            int ndSk;
            std::cout << "Iveskite namu darbu skaiciu: ";
            std::cin >> ndSk;
            std::cout << "Iveskite namu darbu rezultatus: ";
            for (int i = 0; i < ndSk; ++i) {
                int pazymys;
                std::cin >> pazymys;
                studentas.namuDarbai.push_back(pazymys);
            }
            std::cout << "Iveskite egzamino rezultata: ";
            std::cin >> studentas.egzaminas;
        } 
        else if (pasirinkimas == 2) {
            std::cout << "Iveskite studenta (vardas pavarde): ";
            std::cin >> studentas.vardas >> studentas.pavarde;

            int ndSk;
            std::cout << "Kiek pazymiu generuoti? ";
            std::cin >> ndSk;
            for (int i = 0; i < ndSk; ++i) {
                studentas.namuDarbai.push_back(rand() % 10 + 1);
            }
            studentas.egzaminas = rand() % 10 + 1;
            std::cout << "Sugeneruoti namu darbu pazymiai ir egzaminas.\n";
        } 
        else if (pasirinkimas == 3) {
            int kiekStudentu, ndSk;
            std::cout << "Kiek studentu generuoti? ";
            std::cin >> kiekStudentu;
            std::cout << "Kiek namu darbu kiekvienam? ";
            std::cin >> ndSk;

            generuotiStudentus(studentai, kiekStudentu, ndSk);
            std::cout << kiekStudentu << "Studentai sugeneruoti.\n";
            for (auto& studentas : studentai) {
                if (metodas == 'V' || metodas == 'v') {
                    studentas.galutinisBalas = 0.4 * skaiciuotiVidurki(studentas.namuDarbai) + 0.6 * studentas.egzaminas;
                } else {
                    studentas.galutinisBalas = 0.4 * skaiciuotiMediana(studentas.namuDarbai) + 0.6 * studentas.egzaminas;
                }
            }
            continue;
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
