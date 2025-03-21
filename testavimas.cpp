#include "testavimas.h"

// ========================= TESTAVIMO FUNKCIJA =========================
template<typename Container>
void testuotiKonteineri(const std::string& failoVardas) {
    Container studentai;

    // 1. Nuskaitymo laikas
    auto startNuskaitymas = std::chrono::high_resolution_clock::now();
    try {
        nuskaitytiIsFailo(studentai, failoVardas);
    } catch (const std::runtime_error& e) {
        std::cerr << "Klaida: " << e.what() << std::endl;
        return;
    }
    auto endNuskaitymas = std::chrono::high_resolution_clock::now();

    // 2. Rūšiavimo laikas
    auto startRusiavimas = std::chrono::high_resolution_clock::now();
    rikiuotiStudentus(studentai, 'G'); // Rūšiuojama pagal galutinį balą
    auto endRusiavimas = std::chrono::high_resolution_clock::now();

    // 3. Skirstymo laikas
    auto startSkirstymas = std::chrono::high_resolution_clock::now();
    Container vargsiai, kietiakai;
    padalintiStudentus(studentai, vargsiai, kietiakai);
    auto endSkirstymas = std::chrono::high_resolution_clock::now();

    // Rezultatų išvedimas
    std::cout << "\n=== " << ContainerName<Container>::name() << " ==="
              << "\nNuskaitymas: " << std::chrono::duration<double>(endNuskaitymas - startNuskaitymas).count() << " s"
              << "\nRusiavimas: " << std::chrono::duration<double>(endRusiavimas - startRusiavimas).count() << " s"
              << "\nSkirstymas: " << std::chrono::duration<double>(endSkirstymas - startSkirstymas).count() << " s\n";
}

// ========================= VISŲ KONTEINERIŲ TESTAVIMAS =========================
void testuotiVisusKonteinerius(const std::string& failoVardas) {
    testuotiKonteineri<std::vector<Student>>(failoVardas);
    testuotiKonteineri<std::list<Student>>(failoVardas);
    testuotiKonteineri<std::deque<Student>>(failoVardas);
}

// ========================= PAGRINDINĖ FUNKCIJA =========================
int main() {
    std::string failoVardas;
    std::cout << "Iveskite testo failo pavadinima: ";
    std::getline(std::cin, failoVardas);

    testuotiVisusKonteinerius(failoVardas);
    return 0;
}