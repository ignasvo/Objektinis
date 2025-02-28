#include "vektorine.h"

std::vector<std::string> vardai = {"Jonas", "Petras", "Marius", "Tomas", "Lukas", "Paulius", "Mantas", "Kazys", "Antanas", "Darius"};
std::vector<std::string> pavardes = {"Kazlauskas", "Petraitis", "Jankauskas", "Jonaitis", "Brazinskas", "Stankevicius", "Kavaliauskas", "Zukauskas", "Kavolis"};

void nuskaitytiIsFailo(std::vector<Student>& studentai, const std::string& failoVardas) {
    std::ifstream failas(failoVardas);
    if (!failas) {
        throw std::runtime_error("Failas nerastas: " + failoVardas);
    }

    std::string eilute;
    getline(failas, eilute); // Praleidžiama antraštė

    while (getline(failas, eilute)) {
        std::istringstream iss(eilute);
        Student studentas;
        iss >> studentas.vardas >> studentas.pavarde;

        int pazymys;
        while (iss >> pazymys) {
            studentas.namuDarbai.push_back(pazymys);
        }

        studentas.egzaminas = studentas.namuDarbai.back();
        studentas.namuDarbai.pop_back();
        studentai.push_back(studentas);
    }
}


bool arTinkamasVardas(const std::string& tekstas) {
    for (char c : tekstas) {
        if (!std::isalpha(c)) return false;
    }
    return true;
}

bool arTinkamasPazymys(int& pazymys) {
    std::string input;
    while (true) {
        std::getline(std::cin, input);
        std::istringstream iss(input);
        
        if (iss >> pazymys) {
            char leftover;
            if (iss >> leftover) {
                std::cout << "Klaida: netinkama ivestis. Bandykite dar karta: ";
            } else if ((pazymys >= 1 && pazymys <= 10) || pazymys == -1) {
                return true;
            } else {
                std::cout << "Klaida: skaicius turi buti nuo 1 iki 10. Bandykite dar karta: ";
            }
        } else {
            std::cout << "Klaida: iveskite sveikaji skaiciu. Bandykite dar karta: ";
        }
    }
}

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
    while (metodas != 'V' && metodas != 'v' && metodas != 'M' && metodas != 'm') {
        std::cout << "Pasirinkite skaiciavimo metoda (V - vidurkis, M - mediana): ";
        std::cin >> metodas;
    }

    while (true) {
        std::cout << "\nPasirinkite veiksma:\n";
        std::cout << "1 - Ivesti ranka\n";
        std::cout << "2 - Generuoti pazymius\n";
        std::cout << "3 - Generuoti studentus ir pazymius\n";
        std::cout << "4 - Nuskaityti is failo\n";
        std::cout << "5 - Baigti\n";
        std::cout << "Jusu pasirinkimas: ";
        
        int pasirinkimas;
        std::cin >> pasirinkimas;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        
        if (pasirinkimas == 5) break;
        
        Student studentas;
        if (pasirinkimas == 1) {
            while (true) {
                std::cout << "Iveskite varda ir pavarde: ";
                std::string ivestis;
                std::getline(std::cin, ivestis);
                std::istringstream iss(ivestis);
                iss >> studentas.vardas >> studentas.pavarde;
                
                if (arTinkamasVardas(studentas.vardas) && arTinkamasVardas(studentas.pavarde)) {
                    break;
                } else {
                    std::cout << "Klaida: vardas ir pavarde turi buti sudaryti tik is raidziu. Bandykite dar karta.\n";
                }
            }

            std::cout << "Iveskite pazymius (1-10, -1 baigti):\n";
            int paz;
            while (true) {
                std::cout << "Pazymys: ";
                if (arTinkamasPazymys(paz)) {
                    if (paz == -1) break;
                    studentas.namuDarbai.push_back(paz);
                }
            }

            std::cout << "Egzamino pazymys: ";
            arTinkamasPazymys(studentas.egzaminas);

            skaiciuotiGalutiniBala(studentas, metodas);
            studentai.push_back(studentas);
        } 
        else if (pasirinkimas == 2) {
            while (true) {
                std::cout << "Iveskite varda ir pavarde: ";
                std::string ivestis;
                std::getline(std::cin, ivestis);
                std::istringstream iss(ivestis);
                iss >> studentas.vardas >> studentas.pavarde;
                
                if (arTinkamasVardas(studentas.vardas) && arTinkamasVardas(studentas.pavarde)) {
                    break;
                } else {
                    std::cout << "Klaida: vardas ir pavarde turi buti sudaryti tik is raidziu. Bandykite dar karta.\n";
                }
            }
            int kiek;
            std::cout << "Kiek pazymiu generuoti? ";
            std::cin >> kiek;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
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
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            generuotiStudentus(studentai, kiekStudentu, ndSk);
            for (auto& s : studentai) skaiciuotiGalutiniBala(s, metodas);
        }

        else if (pasirinkimas == 4) {
            std::string failoVardas;
            std::cout << "Iveskite failo pavadinima: ";
            std::getline(std::cin, failoVardas);
            try {
                nuskaitytiIsFailo(studentai, failoVardas);
                for (auto& s : studentai) skaiciuotiGalutiniBala(s, metodas);
            } catch (const std::runtime_error& e) {
                std::cout << e.what() << std::endl;
            }
        }
    }

    spausdintiRezultatus(studentai);
}

int main() {
    vykdytiPrograma();
    return 0;
}