#include "testavimas.h"

// ========================= NUSKAITYMAS =========================
template<typename Container>
void nuskaitytiIsFailo(Container& studentai, const std::string& failoVardas) {
    std::ifstream failas(failoVardas);
    if (!failas) throw std::runtime_error("Failas nerastas: " + failoVardas);

    std::string eilute;
    getline(failas, eilute); // Praleidžiame antraštę

    while (getline(failas, eilute)) {
        Student s;
        std::istringstream iss(eilute);
        iss >> s.vardas >> s.pavarde;

        int pazymys;
        while (iss >> pazymys) s.namuDarbai.push_back(pazymys);

        if (s.namuDarbai.empty()) throw std::runtime_error("Truksta pazymiu");

        s.egzaminas = s.namuDarbai.back();
        s.namuDarbai.pop_back();
        studentai.push_back(s);
    }
}

// ========================= RŪŠIAVIMAS =========================
template<typename Container>
void rikiuotiStudentus(Container& studentai, char kriterijus) {
    auto comparator = [kriterijus](const Student& a, const Student& b) {
        if (kriterijus == 'V' || kriterijus == 'v') return a.vardas < b.vardas;
        if (kriterijus == 'P' || kriterijus == 'p') return a.pavarde < b.pavarde;
        return a.galutinisBalas > b.galutinisBalas;
    };
    std::sort(studentai.begin(), studentai.end(), comparator);
}

// ========================= 1 STRATEGIJA =========================
template<typename Container>
void strategija1(const Container& studentai, Container& vargsiai, Container& kietiakai) {
    for (const auto& s : studentai) {
        (s.galutinisBalas < 5.0) ? vargsiai.push_back(s) : kietiakai.push_back(s);
    }
}

// ========================= 2 STRATEGIJA =========================
template<typename Container>
void strategija2(Container& studentai, Container& vargsiai) {
    auto it = std::remove_if(studentai.begin(), studentai.end(), [&](const Student& s) {
        if (s.galutinisBalas < 5.0) {
            vargsiai.push_back(s);
            return true;
        }
        return false;
    });
    studentai.erase(it, studentai.end());
}

// ========================= 3 STRATEGIJA =========================
template<typename Container>
void strategija3(Container& studentai, Container& vargsiai) {
    auto it = std::partition(studentai.begin(), studentai.end(), [](const Student& s) {
        return s.galutinisBalas >= 5.0;
    });
    vargsiai.assign(it, studentai.end());
    studentai.erase(it, studentai.end());
}

// ========================= TESTAVIMO FUNKCIJA =========================
template<typename Container>
void testuotiStrategijas(const std::string& failoVardas) {
    Container studentai;
    nuskaitytiIsFailo(studentai, failoVardas);

    Container vargsiai, kietiakai;

    auto start1 = std::chrono::high_resolution_clock::now();
    strategija1(studentai, vargsiai, kietiakai);
    auto end1 = std::chrono::high_resolution_clock::now();

    studentai.clear();
    vargsiai.clear();
    nuskaitytiIsFailo(studentai, failoVardas);

    auto start2 = std::chrono::high_resolution_clock::now();
    strategija2(studentai, vargsiai);
    auto end2 = std::chrono::high_resolution_clock::now();

    studentai.clear();
    vargsiai.clear();
    nuskaitytiIsFailo(studentai, failoVardas);

    auto start3 = std::chrono::high_resolution_clock::now();
    strategija3(studentai, vargsiai);
    auto end3 = std::chrono::high_resolution_clock::now();

    std::cout << "\n=== " << ContainerName<Container>::name() << " ==="
              << "\n1 strategija: " << std::chrono::duration<double>(end1 - start1).count() << " s"
              << "\n2 strategija: " << std::chrono::duration<double>(end2 - start2).count() << " s"
              << "\n3 strategija: " << std::chrono::duration<double>(end3 - start3).count() << " s\n";
}

// ========================= VISŲ KONTEINERIŲ TESTAVIMAS =========================
void testuotiVisusKonteinerius(const std::string& failoVardas) {
    testuotiStrategijas<std::vector<Student>>(failoVardas);
    testuotiStrategijas<std::list<Student>>(failoVardas);
    testuotiStrategijas<std::deque<Student>>(failoVardas);
}

// ========================= Šablonų instancijavimas =========================
template void nuskaitytiIsFailo<std::vector<Student>>(std::vector<Student>&, const std::string&);
template void nuskaitytiIsFailo<std::list<Student>>(std::list<Student>&, const std::string&);
template void nuskaitytiIsFailo<std::deque<Student>>(std::deque<Student>&, const std::string&);

template void rikiuotiStudentus<std::vector<Student>>(std::vector<Student>&, char);
template void rikiuotiStudentus<std::deque<Student>>(std::deque<Student>&, char);
