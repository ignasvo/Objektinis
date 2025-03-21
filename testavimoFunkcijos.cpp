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
// Specializuota list versija
template<>
void rikiuotiStudentus(std::list<Student>& studentai, char kriterijus) {
    auto comparator = [kriterijus](const Student& a, const Student& b) {
        if (kriterijus == 'V' || kriterijus == 'v') return a.vardas < b.vardas;
        if (kriterijus == 'P' || kriterijus == 'p') return a.pavarde < b.pavarde;
        return a.galutinisBalas > b.galutinisBalas;
    };
    studentai.sort(comparator);
}

// Bendroji vector/deque versija
template<typename Container>
void rikiuotiStudentus(Container& studentai, char kriterijus) {
    auto comparator = [kriterijus](const Student& a, const Student& b) {
        if (kriterijus == 'V' || kriterijus == 'v') return a.vardas < b.vardas;
        if (kriterijus == 'P' || kriterijus == 'p') return a.pavarde < b.pavarde;
        return a.galutinisBalas > b.galutinisBalas;
    };
    std::sort(studentai.begin(), studentai.end(), comparator);
}

// ========================= SKIRSTYMAS =========================
template<typename Container>
void padalintiStudentus(const Container& studentai, Container& vargsiai, Container& kietiakai) {
    for (const auto& s : studentai) {
        (s.galutinisBalas < 5.0) ? vargsiai.push_back(s) : kietiakai.push_back(s);
    }
}

template void nuskaitytiIsFailo<std::vector<Student>>(std::vector<Student>&, const std::string&);
template void nuskaitytiIsFailo<std::list<Student>>(std::list<Student>&, const std::string&);
template void nuskaitytiIsFailo<std::deque<Student>>(std::deque<Student>&, const std::string&);

template void rikiuotiStudentus<std::vector<Student>>(std::vector<Student>&, char);
template void rikiuotiStudentus<std::deque<Student>>(std::deque<Student>&, char);

template void padalintiStudentus<std::vector<Student>>(const std::vector<Student>&, std::vector<Student>&, std::vector<Student>&);
template void padalintiStudentus<std::list<Student>>(const std::list<Student>&, std::list<Student>&, std::list<Student>&);
template void padalintiStudentus<std::deque<Student>>(const std::deque<Student>&, std::deque<Student>&, std::deque<Student>&);