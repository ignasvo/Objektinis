Studentų pažymių skaičiavimo sistema v0.3
Ši versija yra patobulinta ankstesnė v0.2 versija, kurioje atlikti šie pakeitimai:

Pakeitimai v0.3 versijoje
Kodo suskaidymas į kelis failus

vektorine.cpp – pagrindinis programos vykdymas.
studentai.h – studento struktūra.
funkcijos.h – funkcijų deklaracijos.
funkcijos.cpp – funkcijų realizacija.
Pridėtas klaidų valdymas (Exception Handling)

Failo nuskaitymo patikra: jei failas neegzistuoja arba jo struktūra neteisinga, rodoma klaida.
Įvesties validacija: patikrinama, ar įvesta reikšmė yra tinkama (pvz., skaičiai vietoj raidžių, sveikieji skaičiai pažymiams).
Apsauga nuo kritinių klaidų: įtraukti try-catch blokai, kad programa nepertrauktų darbo net ir kilus nenumatytoms klaidoms.