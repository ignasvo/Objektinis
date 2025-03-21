# Studentų duomenų apdorojimo testavimas

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

## Išvados

1. **Nuskaitymas:**
   - Greičiausiai veikia `std::vector` ir `std::deque`, nes jie yra optimizuoti atsitiktinei prieigai.
   - `std::list` yra šiek tiek lėtesnis dėl savo dvipusio sąrašo struktūros.

2. **Rūšiavimas:**
   - `std::vector` ir `std::deque` naudoja `std::sort`, kuris yra labai efektyvus.
   - `std::list` naudoja savo vidinį `list::sort()`, kuris yra lėtesnis, bet optimizuotas sąrašams.

3. **Skirstymas:**
   - `std::vector` ir `std::deque` vėlgi dominuoja dėl efektyvios atminties valdymo.
   - `std::list` yra lėtesnis dėl dažnesnio atminties perskirstymo.

---
