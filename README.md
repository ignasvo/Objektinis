# Studentų pažymių skaičiavimo sistema v0.2  

Programa, skirta studentų galutiniams pažymiams skaičiuoti naudojant **std::vector** duomenų struktūrą. Palaiko rankinį įvedimą, automatinį pažymių generavimą, du skaičiavimo metodus (vidurkis arba mediana) bei rikiavimą pagal vartotojo pasirinktą kriterijų.  

## Funkcijos  

- Įvesties validacija:  
  - Vardai ir pavardės turi būti sudaryti tik iš raidžių.  
  - Pažymiai turi būti sveikieji skaičiai nuo 1 iki 10.  

- Skaičiavimo metodai:  
  - Galutinis pažymys skaičiuojamas naudojant vidurkį arba medianą.  

- Duomenų generavimas:  
  - Automatiškai sugeneruojami studentų duomenys (vardai, pavardės, pažymiai).  
  - Galima nustatyti studentų skaičių ir namų darbų kiekį.  

- Failų nuskaitymas ir testavimas:  
  - Programa gali nuskaityti duomenis iš failų (Studentai10000.txt, Studentai100000.txt, Studentai1000000.txt).  
  - Vykdymo laikas matuojamas kiekvienam failui ir išvedamas vartotojui.  

- Rikiavimas pagal pasirinktą kriterijų:  
  - V – vardą  
  - P – pavardę  
  - G – galutinį balą  

## Naudojimas  

1. Pasirinkite skaičiavimo metodą: V (vidurkis) arba M (mediana).  
2. Pasirinkite duomenų šaltinį: rankinis įvedimas, automatinis generavimas arba failo nuskaitymas.  
3. Pasirinkite rikiavimo kriterijų: V (vardas), P (pavardė) arba G (galutinis balas).  
4. Gaukite rezultatus su apdorojimo laiku.  