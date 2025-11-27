# v1.5 specifikacijos:

<pre>
CPU Intel Core i9-12900H, 12-oji karta, 14 branduolių (6 P + 8 E), 20 gijų, 2.5 GHz bazinis dažnis, iki 5.0 GHz
RAM 16 GB DDR5-4800 MHz, 2× 8 GB 
SSD - 1 TB PCIe Gen 4 NVMe M.2 SSD 
<pre>

## Aprašymas:
   v1.5 buvo pridėta abstrakti klasė Zmogus, su vardas ir pavarde kintamaisiais ir sukurtas zmogus.h failas.
   Atnaujinti studentas.cpp ir studentas.h failai
   papildziau main.cpp faila su demonstracija

## Demonstracija:
<img width="750" height="273" alt="image" src="https://github.com/user-attachments/assets/acc9e2e5-17ff-4ffe-b88d-f38aae14cd47" /> 
   kompiliacija įvyksta kai klasės Zmogus nenaudojame:
   <img width="834" height="106" alt="image" src="https://github.com/user-attachments/assets/80e3f068-a61d-4442-818c-0894c5151a76" />


   atkomentuojame eilutę, kur yra zmogus z:
   <img width="773" height="202" alt="image" src="https://github.com/user-attachments/assets/2757056a-b2e3-4980-904a-d06cb40871d2" />
matome, kad kompiliacija neįvyko, nes klasė Zmogus yra abstrakti
   <img width="700" height="55" alt="image" src="https://github.com/user-attachments/assets/496c9730-1439-4a94-bc91-e991b83cef05" />

   
# programos paleidimas
</pre>
1. Atsisiųsti v1.0 release failus
2. atsidarius Pirmas_lab_2 pasirinkti, kurią strategiją naudosime.
3. Atidaryti .sln failą per Visual studio
4. rekomenduoju naudoti c++17 versiją
5. paleisti programą Realease x64 metodu.

arba

1. Atsidarykite terminalą (arba „Developer PowerShell“ jei naudojate Visual Studio).
2. įrašykite: cd "3 strategijos folderio išsaugojimo vieta"
3. toliau: mkdir build
cd build
4.toliau: cmake ..
5. įvykdome kompiliaciją:cmake --build . --config Release
6. pereiti 5 release: cd .\Release
7. visą kodą galime paleisti: ./3_strategija.exe
   testavimą su: ./testavimas.exe




Paleidus programą:
Pasirinkite, ar norite įvesti duomenis ranka, ar nuskaityti iš failo.
Įveskite studentų duomenis (vardas, pavardė, pažymiai, egzaminas).
Programa automatiškai:
suskaičiuos vidurkius ir medianas,
išrūšiuos studentus pagal pasirinktą strategiją (pvz. 3 strategija),
atskirs „vargšiukus“,
išves rezultatus ekrane ir į failus.
</pre>
  

## Aprašymas
Programa skirta studentų pažymių tvarkymui, galutinio balo skaičiavimui ir rūšiavimui.
