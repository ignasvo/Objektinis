# V1.0 Pradinė

Ši programa testuoja trijų skirtingų konteinerių (`std::vector`, `std::list`, `std::deque`) veikimo spartą apdorojant studentų duomenis. Testavimas atliekamas su skirtingo dydžio failais, kuriuose yra nuo 1 000 iki 10 000 000 įrašų.

---

## Testavimo rezultatai

### Testavimo sistemos parametrai
- **Procesorius:** AMD Ryzen 7 7840U
- **RAM:** 16 GB DDR4
- **Disko tipas:** SSD
---

### Rezultatai

#### Failas: `studentai_1000.txt` (1 000 įrašų)
| Konteineris | Nuskaitymas (s) | Rūšiavimas (s) | Skirstymas (s) |
|-------------|-----------------|----------------|----------------|
| Vector      | 0.004           | 0.001          | 0.0004         |
| List        | 0.004           | 0.001          | 0.0004         |
| Deque       | 0.006           | 0.002          | 0.0004         |

![image](https://github.com/user-attachments/assets/df49b163-970f-418f-9bab-55774788e90d)

#### Failas: `studentai_10000.txt` (10 000 įrašų)
| Konteineris | Nuskaitymas (s) | Rūšiavimas (s) | Skirstymas (s) |
|-------------|-----------------|----------------|----------------|
| Vector      | 0.038           | 0.020          | 0.005          |
| List        | 0.032           | 0.005          | 0.008          |
| Deque       | 0.032           | 0.028          | 0.005          |

![image](https://github.com/user-attachments/assets/9d4a70c9-89b1-49ac-ad60-4f2a00e68308)

#### Failas: `studentai_100000.txt` (100 000 įrašų)
| Konteineris | Nuskaitymas (s) | Rūšiavimas (s) | Skirstymas (s) |
|-------------|-----------------|----------------|----------------|
| Vector      | 0.316           | 0.269          | 0.039          |
| List        | 0.347           | 0.044          | 0.055          |
| Deque       | 0.319           | 0.339          | 0.037          |

![image](https://github.com/user-attachments/assets/fe3c6219-b07d-4b98-93ea-db45a3fbb80e)

#### Failas: `studentai_1000000.txt` (1 000 000 įrašų)
| Konteineris | Nuskaitymas (s) | Rūšiavimas (s) | Skirstymas (s) |
|-------------|-----------------|----------------|----------------|
| Vector      | 3.217           | 3.256          | 0.479          |
| List        | 3.263           | 0.428          | 0.425          |
| Deque       | 3.099           | 4.048          | 0.343          |

![image](https://github.com/user-attachments/assets/e076bbbf-b860-4439-adec-e1e8a07d2dc3)

#### Failas: `studentai_10000000.txt` (10 000 000 įrašų)
| Konteineris | Nuskaitymas (s) | Rūšiavimas (s) | Skirstymas (s) |
|-------------|-----------------|----------------|----------------|
| Vector      | 16.077          | 21.79          | 2.735          |
| List        | 16.430          | 3.571          | 2.597          |
| Deque       | 15.833          | 26.12          | 1.956          |

![image](https://github.com/user-attachments/assets/82f0fe0b-5cf4-49b0-a5e6-d828d95752ad)

---

### 1. **Nuskaitymas**  
- **Deque** buvo šiek tiek lėtesnis su mažais failais, bet greitesnis su 10M įrašų.  
- **Vector** ir **List** parodė panašų našumą.  

### 2. **Rūšiavimas**  
- **List** žymiai greitesnis (pvz., 10M įrašų: **3.571 s** vs **21.79 s** Vector).  
- **Deque** lėčiausias dėl neefektyvaus `std::sort` algoritmo.  

### 3. **Skirstymas**  
- **Deque** greičiausias (10M įrašų: **1.956 s**).  
- **List** lėčiausias dėl atminties fragmentacijos.  

---

# V1.0 Finalinė

## Strategijų palyginimas pagal veikimo laiką  

Buvo atliktas eksperimentas, kuriame **studentų sąrašai buvo dalijami į „vargšiukų“ ir „kietiakų“ grupes** naudojant tris strategijas ir tris skirtingus konteinerių tipus:  
- **`std::vector`**  
- **`std::list`**  
- **`std::deque`**  

Pagrindinis tikslas – **išmatuoti skirstymo operacijos našumą** priklausomai nuo naudojamos strategijos ir konteinerio tipo.  

### Strategijų aprašymas  
1. **Strategija 1:** Sukuria du naujus konteinerius (`vargsiai`, `kietiakai`) ir kopijuoja studentus iš bendro konteinerio. **Didelės atminties sąnaudos**.  
2. **Strategija 2:** Sukuria tik vieną naują konteinerį (`vargsiai`), iš bendro konteinerio trindama „vargšiukus“. **Daug trynimų – gali būti lėtesnė tam tikrais atvejais**.  
3. **Strategija 3:** **Naudojama tik su `std::vector`**, optimizuota naudojant **`std::partition`**, kuris efektyviai surūšiuoja studentus vietoje, perkeldamas „vargšiukus“ į vieną sąrašo dalį. **Greičiausia strategija**. 

#### Failas: `studentai_1000.txt` (1 000 įrašų)
| Konteineris |   Strategija1    |  Strategija2   | Strategija3    |
|-------------|------------------|----------------|----------------|
| Vector      | 0.0002           | 0.0001         | 0.0001         |
| List        | 0.0002           | 0.0003         | N/A            |
| Deque       | 0.0002           | 0.0003         | N/A            |

![image](https://github.com/user-attachments/assets/3b1d7619-3cd2-4fea-ad3e-ec6ba32d0663)

#### Failas: `studentai_10000.txt` (10 000 įrašų)
| Konteineris |   Strategija1    |  Strategija2   | Strategija3    |
|-------------|------------------|----------------|----------------|
| Vector      | 0.0033           | 0.0032         | 0.0022         |
| List        | 0.0069           | 0.0037         | N/A            |
| Deque       | 0.0032           | 0.0030         | N/A            |

![image](https://github.com/user-attachments/assets/aeff8d55-fa19-4ec6-bc7e-e2871b310d62)

#### Failas: `studentai_100000.txt` (100 000 įrašų)
| Konteineris |   Strategija1    |  Strategija2   | Strategija3    |
|-------------|------------------|----------------|----------------|
| Vector      | 0.0400           | 0.0356         | 0.0328         |
| List        | 0.0655           | 0.0643         | N/A            |
| Deque       | 0.0215           | 0.0310         | N/A            |

![image](https://github.com/user-attachments/assets/aa40cee0-58fd-4279-abbf-078248253e8b)

#### Failas: `studentai_1000000.txt` (1 000 000 įrašų)
| Konteineris |   Strategija1    |  Strategija2   | Strategija3    |
|-------------|------------------|----------------|----------------|
| Vector      | 0.3004           | 0.2130         | 0.2053         |
| List        | 0.2950           | 0.4601         | N/A            |
| Deque       | 0.2085           | 0.3442         | N/A            |

![image](https://github.com/user-attachments/assets/b7d007e5-3e38-4323-a797-4234d364410d)

#### Failas: `studentai_10000000.txt` (10 000 000 įrašų)
| Konteineris |   Strategija1    |  Strategija2   | Strategija3    |
|-------------|------------------|----------------|----------------|
| Vector      | 3.3017           | 2.2470         | 2.1734         |
| List        | 3.2299           | 4.8972         | N/A            |
| Deque       | 2.2971           | 4.6221         | N/A            |

![image](https://github.com/user-attachments/assets/3ccdfa1f-7719-4bc2-b89e-a063a09c5b93)

## Išvados ir optimizacijos  
1. **Geriausias konteineris: `std::vector`**  
   - Strategija 3 su `std::vector` yra **optimaliausia**, nes `std::partition` leidžia greitai atskirti elementus **vietoje** be papildomos atminties.  
2. **`std::list` ir `std::deque` nėra tinkami 3 strategijai**  
   - `std::partition` negali būti naudojamas su `list`, todėl buvo išvestas `"N/A"`.  
   - `list::partition()` galėtų būti alternatyva, tačiau jos efektyvumas vis tiek mažesnis.  
3. **2 strategija – geriausias pasirinkimas `list` ir `deque` konteineriams**  
   - Ji leidžia mažinti atminties sąnaudas, bet gali būti lėtesnė dėl `erase` operacijų.  

---
