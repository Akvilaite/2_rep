# v1.1 specifikacijos:

<pre>
CPU Intel Core i9-12900H, 12-oji karta, 14 branduolių (6 P + 8 E), 20 gijų, 2.5 GHz bazinis dažnis, iki 5.0 GHz
RAM 16 GB DDR5-4800 MHz, 2× 8 GB 
SSD - 1 TB PCIe Gen 4 NVMe M.2 SSD 
<pre>


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
  
#Vidurkiai: 
  
<pre>  
Bendros įžvalgos
didelio pokyčio tarp class ir stuct nepastebėjau darant 3 bandymus
   O2 ir O3 už O1 greitesnės net 10 kartų. greičiaucia O2   


# Pirmas_lab_2
   </pre>
su struct:
Su 100 000:         
Failo nuskaitymas        1.04658      
Rūšiavimas ir skirstymas 0.02732      
Rezultatų išvedimas      0.31476    
Bendras laikas           1.38866     

Su 1 000 000:                            
Failo nuskaitymas        7.39874           
Rūšiavimas ir skirstymas 0.09767         
Rezultatų išvedimas      2.12998       
Bendras laikas           9.62639                  

su class:
   Vektoriai:
Su 100 000:
Failo nuskaitymas           0.92756
R?Üiavimas ir skirstymas    0.02367
Rezultat? iÜvedimas         0.31816
Bendras laikas              1.26939
   

Su 1000000:
Failo nuskaitymas           8.43623
R?Üiavimas ir skirstymas    0.21206
Rezultat? iÜvedimas         2.92994
Bendras laikas             11.57822

</pre>


# su optimizavimu
O1:
</pre>
su 1 000 000:
===== LAIKO MATAVIMAI =====
Failo nuskaitymo laikas: 6.0704 s
Skirstymo i vargsiukus laikas: 0.0661496 s
Rezultatu isvedimo i faila laikas: 1.70911 s
---------------------------------
Bendras programos veikimo laikas: 7.84566 s
===========================

su 100 000:
===== LAIKO MATAVIMAI =====
Failo nuskaitymo laikas: 6.40266 s
Skirstymo i vargsiukus laikas: 0.0714069 s
Rezultatu isvedimo i faila laikas: 1.82292 s
---------------------------------
Bendras programos veikimo laikas: 8.29699 s
===========================
</pre>

02(jau naudojau anksciau):su class:
</pre>
Vektoriai:
Su 100 000:
===== LAIKO MATAVIMAI =====
Failo nuskaitymo laikas: 0.605872 s
Skirstymo i vargsiukus laikas: 0.0088592 s
Rezultatu isvedimo i faila laikas: 0.177838 s
---------------------------------
Bendras programos veikimo laikas: 0.792569 s
===========================

Su 1000000:

===== LAIKO MATAVIMAI =====
Failo nuskaitymo laikas: 5.99331 s
Skirstymo i vargsiukus laikas: 0.0801343 s
Rezultatu isvedimo i faila laikas: 1.62353 s
---------------------------------
Bendras programos veikimo laikas: 7.69698 s
===========================
</pre>
O3:
</pre>
Vektoriai:

Su 100000:
===== LAIKO MATAVIMAI =====
Failo nuskaitymo laikas: 0.602839 s
Skirstymo i vargsiukus laikas: 0.006805 s
Rezultatu isvedimo i faila laikas: 0.190798 s
---------------------------------
Bendras programos veikimo laikas: 0.800441 s
===========================
Su 1 000 000:

===== LAIKO MATAVIMAI =====
Failo nuskaitymo laikas: 5.96122 s
Skirstymo i vargsiukus laikas: 0.0756703 s
Rezultatu isvedimo i faila laikas: 1.69641 s
---------------------------------
Bendras programos veikimo laikas: 7.73329 s
===========================
</pre>
