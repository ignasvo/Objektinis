#include "funkcijos.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <cctype>
#include <sstream>
#include <limits>
#include <stdexcept>
#include <chrono>

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
        if (!(iss >> studentas.vardas >> studentas.pavarde)) {
            throw std::runtime_error("Neteisinga eilutes struktera faile: " + failoVardas);
        }

        int pazymys;
        while (iss >> pazymys) {
            studentas.namuDarbai.push_back(pazymys);
        }

        if (studentas.namuDarbai.empty()) {
            throw std::runtime_error("Truksta pazymiu studentui: " + studentas.vardas + " " + studentas.pavarde);
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

void rikiuotiStudentus(std::vector<Student>& studentai, char kriterijus) {
    while (true) {
        if (kriterijus == 'V' || kriterijus == 'v') {
            std::sort(studentai.begin(), studentai.end(), [](const Student& a, const Student& b) {
                return a.vardas < b.vardas;
            });
            break;
        } else if (kriterijus == 'P' || kriterijus == 'p') {
            std::sort(studentai.begin(), studentai.end(), [](const Student& a, const Student& b) {
                return a.pavarde < b.pavarde;
            });
            break;
        } else if (kriterijus == 'G' || kriterijus == 'g') {
            std::sort(studentai.begin(), studentai.end(), [](const Student& a, const Student& b) {
                return a.galutinisBalas > b.galutinisBalas;
            });
            break;
        } else {
            std::cout << "KLAIDA: Neteisingas rikiavimo kriterijus. Bandykite dar karta.\n";
            std::cout << "Pasirinkite rikiavimo kriteriju (V - vardas, P - pavardė, G - galutinis balas): ";
            std::cin >> kriterijus;
        }
    }
}

void generuotiFaila(const std::string& failoPavadinimas, int studentuKiekis, int ndSk, char metodas) {
    // Sugeneruojame studentų duomenis
    std::vector<Student> studentai;
    generuotiStudentus(studentai, studentuKiekis, ndSk);
    
    // Apskaičiuojame galutinius balus kiekvienam studentui 
    for (auto& s : studentai) {
         skaiciuotiGalutiniBala(s, metodas);
    }
    
    // Atidarome failą įrašymui
    std::ofstream out(failoPavadinimas);
    if (!out) {
         std::cerr << "Nepavyko atidaryti failo: " << failoPavadinimas << std::endl;
         return;
    }
    
    // Įrašome antraštę (pasirinktina)
    out << std::left << std::setw(15) << "Vardas" << std::setw(15) << "Pavarde";
    for (int i = 0; i < ndSk; ++i) {
        out << std::setw(5) << ("ND" + std::to_string(i + 1));
    }
    out << std::setw(10) << "Egzaminas\n";
    
    // Įrašome kiekvieno studento duomenis eilutėmis
    for (const auto& studentas : studentai) {
        out << std::left << std::setw(15) << studentas.vardas << std::setw(15) << studentas.pavarde;
        for (int paz : studentas.namuDarbai) {
            out << std::setw(5) << paz;
        }
        out << std::setw(10) << studentas.egzaminas << "\n";
    }
    
    out.close();
}

void padalintiStudentus(const std::vector<Student>& studentai, std::vector<Student>& vargsiai, std::vector<Student>& kietiakai) {
for (const auto& stud : studentai) {
    if (stud.galutinisBalas < 5.0)
    vargsiai.push_back(stud);
else
    kietiakai.push_back(stud);
}
}

void spausdintiStudentusIFaila(const std::vector<Student>& studentai, const std::string& failoVardas) {
    std::ofstream out(failoVardas);
    if (!out) {
        std::cerr << "Nepavyko atidaryti failo: " << failoVardas << "\n";
        return;
    }
    spausdintiRezultatus(studentai, out);
    out.close();
}

void apdorotiFaila(const std::string& failoVardas) {
    std::vector<Student> studentai;
    try {
        nuskaitytiIsFailo(studentai, failoVardas);
    } catch (const std::runtime_error& e) {
        std::cerr << e.what() << std::endl;
        return;
    }
    
    // (Pasikartotinai apskaičiuojame galutinį balą, jei reikia)
    for (auto& s : studentai) {
         skaiciuotiGalutiniBala(s, 'v');
    }
    
    // Padalijame į dvi grupes
    std::vector<Student> vargsiai, kietiakai;
    padalintiStudentus(studentai, vargsiai, kietiakai);
    
    // Sugeneruojame naujų failų vardus – pridėsime priesagą pagal įvertinimą
    std::string baseName = failoVardas.substr(0, failoVardas.find_last_of('.'));
    std::string failoVargsiukai = baseName + "_vargsiukai.txt";
    std::string failoKietiakai = baseName + "_kietiakai.txt";
    
    // Išvedame duomenis į atskirus failus
    spausdintiStudentusIFaila(vargsiai, failoVargsiukai);
    spausdintiStudentusIFaila(kietiakai, failoKietiakai);
    
    std::cout << "Failas " << failoVardas << " buvo apdorotas:\n";
    std::cout << "  - Vargsių rezultatai: " << failoVargsiukai << "\n";
    std::cout << "  - Kietių rezultatai: " << failoKietiakai << "\n";
}

void spausdintiRezultatus(const std::vector<Student>& studentai, std::ostream& out) {

    if (studentai.empty()) {
        out << "Nera studentu duomenu.\n";
        return;
    }

    out << std::fixed << std::setprecision(2);
    out << "--------------------------------------------------\n";
    out << std::left << std::setw(15) << "Vardas" << std::setw(15) << "Pavarde" << "Galutinis balas\n";
    out << "--------------------------------------------------\n";
    for (const auto& studentas : studentai) {
       out << std::left << std::setw(15) << studentas.vardas << std::setw(15) << studentas.pavarde << studentas.galutinisBalas << "\n";
    }
}

void vykdytiPrograma() {
    std::vector<Student> studentai;
    srand(time(0));

    try {
        char metodas;
        do {
            std::cout << "Pasirinkite skaiciavimo metoda (V - vidurkis, M - mediana): ";
            std::cin >> metodas;
        } while (metodas != 'V' && metodas != 'v' && metodas != 'M' && metodas != 'm');

        bool testi = true;
        while (testi) {
            try {
                std::cout << "\nPasirinkite veiksma:\n";
                std::cout << "1 - Ivesti ranka\n";
                std::cout << "2 - Generuoti pazymius\n";
                std::cout << "3 - Generuoti studentus ir pazymius\n";
                std::cout << "4 - Nuskaityti is failo\n";
                std::cout << "5 - Generuoti failus\n";
                std::cout << "6 - Apdoroti faila\n";
                std::cout << "7 - Baigti\n";
                std::cout << "Jusu pasirinkimas: ";
                
                int pasirinkimas;
                if (!(std::cin >> pasirinkimas)) {
                    throw std::runtime_error("Neteisingas pasirinkimas! Iveskite sveikaji skaiciu.");
                }
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                
                if (pasirinkimas == 7) {
                    testi = false;
                    break;
                }
                
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

                    auto start = std::chrono::high_resolution_clock::now();

                    try {
                        nuskaitytiIsFailo(studentai, failoVardas);
                        for (auto& s : studentai) skaiciuotiGalutiniBala(s, metodas);
                        auto end = std::chrono::high_resolution_clock::now();
                        std::chrono::duration<double> diff = end - start;
                        std::cout << "Failas: " << failoVardas << " apdorotas per " << diff.count() << " sekundes.\n";
                    } catch (const std::runtime_error& e) {
                        std::cout << e.what() << std::endl;
                    }

                }

                else if (pasirinkimas == 5) { 
                    int studentuKiekis, ndSk;
                    std::string failoPavadinimas;
                    std::cout << "Kiek studentu sugeneruoti? ";
                    std::cin >> studentuKiekis;
                    std::cout << "Kiek namu darbu? ";
                    std::cin >> ndSk;
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cout << "Iveskite failo pavadinima: ";
                    std::getline(std::cin, failoPavadinimas);
                    
                    auto start = std::chrono::steady_clock::now();
                    generuotiFaila(failoPavadinimas, studentuKiekis, ndSk, metodas);
                    auto end = std::chrono::steady_clock::now();
                    std::chrono::duration<double> diff = end - start;
                    
                    std::cout << "Failo " << failoPavadinimas << " generavimas uztruko " << diff.count() << " s\n";
                }

                else if (pasirinkimas == 6) {
                    std::string failoVardas;
                    std::cout << "Iveskite failo pavadinima: ";
                    std::getline(std::cin, failoVardas);
                    apdorotiFaila(failoVardas);
                }

            } catch (const std::exception& e) {
                std::cout << "Klaida vykdant pasirinkta veiksma: " << e.what() << std::endl;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
        }

        char rikiavimas;
        std::cout << "Pasirinkite rikiavimo kriteriju (V - vardas, P - pavarde, G - galutinis balas): ";
        std::cin >> rikiavimas;
        rikiuotiStudentus(studentai, rikiavimas);

        char isvedimoBudas;
        std::cout << "\nPasirinkite isvedimo budą:\n";
        std::cout << "T - isvesti i terminala\n";
        std::cout << "F - isvesti i faila\n";
        std::cout << "Jusu pasirinkimas: ";
        std::cin >> isvedimoBudas;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        if (isvedimoBudas == 'F' || isvedimoBudas == 'f') {
            std::string failoVardas;
            std::cout << "Iveskite failo pavadinima, į kuri isvesti rezultatus: ";
            std::getline(std::cin, failoVardas);
            std::ofstream out(failoVardas);
        if (!out) {
            std::cerr << "Nepavyko atidaryti failo: " << failoVardas << std::endl;
            return;
        }
        spausdintiRezultatus(studentai, out);
        out.close();
        std::cout << "Rezultatai isvesti i faila: " << failoVardas << std::endl;
    } else {
        // Išveda į terminalą
        spausdintiRezultatus(studentai, std::cout);
    }

    } catch (const std::exception& e) {
        std::cerr << "Kritine klaida: " << e.what() << std::endl;
    }
}
