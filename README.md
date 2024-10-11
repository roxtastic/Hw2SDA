## Tema 2 - SDA ##
## Tololoi Ilinca-Roxana, 311CB ##

## Task 1 ##

## 1. functia "insertsuf" ##
    Functia insertsuf primeste ca parametri un pointer la radacina arborelui de sufixe (root) si un sir de caractere ce reprezinta un sufix (sufix). Scopul ei este sa insereze sufixul dat in arborele de sufixe.
    Mai intai, initializam un pointer curent cu adresa radacinii arborelui. Iteram prin fiecare caracter din sufix pana cand intalnim caracterul terminator \0.
    Dupa, calculam indexul corespunzator caracterului curent din sufix. Indexul este 0 pentru caracterul $ si 1 pana la 26 pentru literele de la a la z.
    Se verifica apoi daca nodul curent are deja un copil cu indexul dat. Daca nu, cream un nou nod.
    Dupa, mutam pointerul curent la copilul corespunzator indexului si trecem la urmatorul caracter din sufix.
    Astfel se construieste arborele de sufixe, adaugand fiecare sufix in arbore pe rand.

## 2. functia "parclatime" ##
    Functia parclatime primeste ca parametri radacina arborelui de sufixe (root) si un pointer la fisierul de iesire (outfile). Se o parcurgere in latime a arborelui si sa afiseze fiecare nivel al arborelui in fisierul de iesire.
    Pentru inceput, initializam o coada pentru parcurgere. Arborele de sufixe si coada au aceeasi dimensiune maxima, cat alfabetul.
    Adaugam radacina arborelui in coada si marcam ca am adaugat un nod in spatele cozii.
    Dupa, incepem parcurgerea in latime a arborelui. Calculam numarul de noduri de pe nivelul curent al arborelui si parcurgem fiecare nod de pe nivelul curent al arborelui.
    Mai apoi, pentru fiecare copil al nodului curent, afisam caracterul sau. Daca este NULL, trecem la urmatorul.
    Scadem numarul de noduri de pe nivelul curent al arborelui si daca mai exista noduri in coada, trecem pe linia urmatoare(si pe nivelul urmator).

## 3. main ##
    Mai intai, se itereaza prin cele N sufixe. Se citeste fiecare sufix folosind fgets, fiecare sufix fiind stocat in variabila sufix.
    Dupa, am dorit sa elimin caracterul newline de la sfarsitul sufixului folosind strcspn. Mai apoi, se adauga caracterul '$' la sfarsitul sufixului. Se itereaza prin fiecare caracter al sufixului si se insereaza sufixul in arbore folosind functia insertsuf.
    Apoi, se apeleaza functia parclatime pentru a parcurge arborele si a scrie in fisierul de iesire toate sufixele intalnite si elibereaza memoria alocata pentru arbore.

## Task 2 ##

## 1. functia numardolar ##
    Functia primeste ca argument un nod root, care reprezinta radacina arborelui.
    Se initializeaza un contor cnt cu valoarea 0, care va fi utilizat pentru a numara nodurile care au un copil cu eticheta "$".
    Dupa, se declara o coada de arbori si doua variabile pentru a gestiona coada (fata si spate). De asemenea, se adauga radacina arborelui la coada.
    Apoi, se parcurge coada pana cand aceasta devine goala si se extrage primul element din coadam, pentru a se memora in variabila curent.
    Se parcurg toti copiii nodului curent. Daca un copil al nodului curent exista, este adaugat la coada pentru a fi procesat dupa.
    Daca primul copil al nodului curent este diferit de NULL, inseamna ca nodul curent are un copil cu eticheta "$", asa ca incrementam cnt.
    La final, functia returneaza valoarea lui cnt, care reprezinta numarul de noduri care au un copil cu eticheta "$" in arborele dat.

## 2. functia nrmaxdes ##
    Functia nrmaxdes este utilizata pentru a determina cel mai mare numar de descendenti pe care un nod il poate avea, dat fiind un arbore si o limita K pentru adancimea cautarii.
    Functia primeste trei argumente: nodul radacina root, limita K pentru adancimea cautarii si un pointer catre maxDes, care va retine numarul maxim de descendenti gasiti pana acum.
    Se verifica daca root este NULL, caz in care functia se termina.
    Dupa, se declara o coada de arbori si doua variabile pentru coada (fata si spate). Se adauga radacina arborelui la coada.
    Apoi, se parcurge coada pana cand aceasta devine goala, se calculeaza numarul de noduri de pe nivelul curent al arborelui, si se parcurge fiecare nod de pe nivelul curent.
    Dupa ce se extrage nodul curent din coada, se initializeaza un contor pentru numarul de descendenti ai nodului curent, astfel incat sa fie parcursi toti copiii nodului curent
    Daca un copil al nodului curent exista, se incrementeaza contorul de descendenti. si copilul este adaugat la coada pentru a fi procesat ulterior
    Daca numarul de descendenti ai nodului curent este mai mare decat valoarea maxima gasita pana acum, se actualizeaza valoarea maxima, iar dupa se decrementeaza numarul de noduri de pe nivelul curent.

## 3. functia sufixK ## 
    Functia sufixK numara cate sufixe de lungime K exista in arbore si primeste trei argumente: nodul radacina root, lungimea sufixului K si returneaza numarul de sufixe de lungime K din arbore.
    Mai intai, se initializeaza un contor cnt cu valoarea 0, care va fi utilizat pentru a numara sufixele de lungime K.
    Dupa, se declara o coada de arbori si variabilele fata si spate si se adauga radacina arborelui la coada. Parcurg coada pana cand aceasta devine goala.
    Mai apoi, se calculeaza numarul de noduri de pe nivelul curent al arborelui, se parcurge fiecare nod de pe nivelul curent si se extrage nodul curent din coada.
    Daca suntem la nivelul sufixului K si nodul curent are un copil, incrementam contorul cnt.
    Se parcurg toti copiii nodului curent si daca un copil al nodului curent exista, este adaugat la coada pentru a fi luat in calcul mai incolo.
    Se decrementeaza numarul de noduri de pe nivelul curent, se incrementeaza nivelul si se verifica daca acesta a depasit lungimea sufixului K. Daca da, se iese din bucla.
    La final, functia returneaza valoarea lui cnt, care reprezinta numarul de sufixe de lungime K gasite in arbore.

## 4. main ## 
    Se repeta mare parte din cod, ca la taskul 1: formarea arborelui multicai din care sa putem obtine statisticile dorite.
    Dupa, adaug caracterul '$' la sfarsitul sufixului si se insereaza sufixul in arbore.
    Argumentul argv[2] (care reprezinta lungimea sufixelor cautate) este numarul intreg K.
    Prin functiile descrise mai sus, aflam:
    Numarul de noduri care au un copil cu eticheta "$".
    Numarul de sufixe de lungime K.
    Numarul maxim de descendenti al unui nod.

## Task 3 ##

## 1. functia cautsuf ##
    Functia cautsuf cauta un sufix dat intr-un arbore si determina daca exista in arborele multicai obtinut.
    Functia primeste doua argumente: nodul radacina root al arborelui si sufixul cautat sufix, reprezentat ca un sir de caractere.
    Mai intai, se initializeaza un nod curent curent cu radacina arborelui si un index i pentru a parcurge sufixul si dupa, se parcurge sufixul pana la caracterul terminator 
    Se declara o variabila index pentru a reprezenta indexul copilului corespunzator caracterului din sufix. Daca caracterul curent din sufix este '$', indexul este 0; altfel, se calculeaza indexul pe baza pozitiei caracterului in alfabet.
    Daca copilul corespunzator caracterului din sufix nu exista, sufixul nu este prezent in arbore, deci functia returneaza 0.
    Apoi, se actualizeaza nodul curent cu copilul corespunzator caracterului si se trece la urmatorul caracter din sufix.
    Dupa ce s-a parcurs intreg sufixul, se verifica daca nodul curent are doar copii NULL. In acest caz, sufixul este prezent in arbore si functia returneaza 1.
    Daca nu exista niciun copil al nodului curent, functia returneaza 1, indicand ca sufixul este prezent in arbore.

## 2. main ##
    Din nou, ca si la primele 2 taskuri, mai intai avem de scris instructiunile pentru arborelui multicai cu sufixe din cuvintele primite in input. 
    Ca sa clarific mai bine, am ales sa fac cu if-uri pentru ca sa simulez un fel de meniu, plus ca la taskul 2 difereau indicii, din cauza aparitiei variabilei K.
    Se creeaza un arbore si se citesc numerele N si M din fisierul de intrare, se itereaza prin fiecare sufix si se adauga fiecare sufix in arbore.
    Dupa, se itereaza prin fiecare sufix cautat M si se cauta fiecare sufix in arbore.
    La final, se elibereaza memoria alocata pentru arbore si se inchid fisierele de intrare si de iesire.






