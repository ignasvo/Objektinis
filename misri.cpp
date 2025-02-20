#include "misri.h"

void generuotiPazymius(Student& studentas, int kiek) {
    for (int i = 0; i < kiek; ++i) {
        studentas.namuDarbai[i] = rand() % 10 + 1;
    }
    studentas.egzaminas = rand() % 10 + 1;
}

double skaiciuotiVidurki(const int paz[], int kiekis) {
    if (kiekis == 0) return 0.0; //Išvengti dalybos iš nulio	
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
        std::cout << "Iveskite studenta (vardas pavarde): ";
        std::cin >> studentas.vardas >> studentas.pavarde;
        
        int ndSk;
        
        if (pasirinkimas == 1) {
            std::cout << "Iveskite namu darbu skaiciu: ";
            std::cin >> ndSk;
            std::cout << "Iveskite namu darbu rezultatus: ";
            for (int i = 0; i < ndSk; ++i) {
                std::cin >> studentas.namuDarbai[i];
            }
            std::cout << "Iveskite egzamino rezultata: ";
            std::cin >> studentas.egzaminas;
        } 
        else if (pasirinkimas == 2) {
            std::cout << "Kiek pazymiu generuoti? ";
            std::cin >> ndSk;
            generuotiPazymius(studentas, ndSk);
            std::cout << "Sugeneruoti namu darbu pazymiai ir egzaminas.\n";
        }
        
        if (metodas == 'V' || metodas == 'v') {
            studentas.galutinisBalas = 0.4 * skaiciuotiVidurki(studentas.namuDarbai, ndSk) + 0.6 * studentas.egzaminas;
        } else {
            studentas.galutinisBalas = 0.4 * skaiciuotiMediana(studentas.namuDarbai, ndSk) + 0.6 * studentas.egzaminas;
        }
        
        studentai.push_back(studentas);
    }

    spausdintiRezultatus(studentai);
}


int main() {
    vykdytiPrograma();
    return 0;
}
