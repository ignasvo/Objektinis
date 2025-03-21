#include "testavimas.h"

int main() {
    std::string failoVardas;
    std::cout << "Iveskite testo failo pavadinima: ";
    std::getline(std::cin, failoVardas);

    testuotiVisusKonteinerius(failoVardas);
    return 0;
}
