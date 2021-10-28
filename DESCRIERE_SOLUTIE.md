# Barbu Angelo-Gabriel (angelo.barbu123@gmail.com)
# Structuri de Date si Algoritmi(SDA) - 2019-2020

DESCRIERE SOLUTIE ATP CUP:

Programul contine fisierele:
- main.c, care contine functia main;
- functions.c, care contine functiile pentru rezolvarea cerintelor
- header.h, care contine structurile de date necesare si antetele functiilor
- Makefile, avand functia de build, ce creeaza fisierul executabil tenis si functia de clean,
care sterge  fisierele obiect create in urma compilarii si fisierul executabil tenis.

In fisierul functions.c se regasesc functiile ce rezolva efectiv cerintele.
 
Functia fileOpenCheck verifica deschiderea fisierelor de read si write
.
Functiile doubleAllocCheck, listAllocCheck, charAllocCheck, etc. verifica alocarea dinamica a
memoriei pentru toate tipurile de date si structurile de date utilizate.

Functia Read citeste elementele fiecarei echipe si le introduce intr-o lista dublu inlantuita,
circulara cu santinela. Se aloca initial memorie pentru santinela si pentru prima tara ce va fi
introdusa in lista. Se citesc datele pentru prima lista, dupa care se fac legaturile intre primul
nod din lista si santinela ce va marca inceputul si sfarsitul listei circulare. Dupa care se aloca
memorie pentru tarile ramase si se creeaza legaturile intre nodul anterior, nodul curent si
santinela.

Functia WriteCountry afiseaza numele tarilor care se gasesc in lista

Functia Write este o functie de verificare si afiseaza toate informatiile stocate in lista.

Functiile deleteNode(sterge un nod din lista), pushStack(introduce un element in stiva),
popStack(scoate un element din stiva si ilr eturneaza), createQueue(creeaza efectiv coada),
enQueue(adauga o pereche de tari in coada), deQueue(scoate o pereche de tari din coada si o
returneaza) sunt functii ajutatoare regasite sub o forma simplificata in curs si adaptate 
structurilor de date din cerinte.

Functia Power returneaza in mod recursiv cea mai mare putere a lui 2 mai mica decat numarul de tari,
necesara pentru rezolvarea cerintei 2.

Functia deleteCountry sterge tarile cu cel mai mic scor pana cand numarul tarilor este valoarea
returnata de functia Power. Scorurile sunt memorate intr-un vector de tip double, iar tarile scoase
sunt marcate in vector cu valoarea INT_MIN. Intr-un while, se elimina tari pana cand numarul de
tari ramase este egal cu valoarea returnata de Power, astfel: se cauta tara al carei scor este
minim si, in acelasi timp, se contorizeaza numarul de tari eliminate, pentru aflarea pozitiei
actuale in lista a tarii cu scor minim.

Functia Task3 rezolva efectiv cerinta 3, astfel:
- initial introduce in stiva elementele din lista si creeaza efectiv coada
- pentru fiecare runda, se creeaza coada in care se introduc perechile de echipe ce vor
  juca meciurile
- pentru fiecare meci, se scoate din coada perechea de echipe
- se adauga fiecarei echipe si fiecarui jucator scorurile corespunzatoare si se aduna la scorurile
  global al echipelor scorurile locale
- se introduce in stiva WINNER echipa castigatoare dintre cele doua, respectandu-se conditiile 
  cerintei
- dupa terminarea rundei, echipele castigatoare aflate in stiva WINNER sunt reintroduse in stiva
  initiala
- se repeta acest procedeu pana cand ramane o singura echipa in stiva, aceea fiind castigatoare.
- in acelasi timp, se memoreaza ultimele 4 tari ramase intr-un vector de tip structCountry necesar
  rezolvarii cerintei 4

Functiile newBSTnode si insertBST sunt functii ajutatoare pentru rezolvarea cerintei 4 si
construiesc BST, sortand elementele de tip struct Player in functie de scorul jucatorului aflat
in nod

Functia printBST afiseaza elementele din arbore in ordine descrescatoare, printr-o afisare de tip
dreapta - radacina - stanga.

Functia Task4 rezolva efectiv cerinta 4, folosindu-se de functiile insertBST si printBST. Se cauta
jucatorii care au scorul egal, parcurgandu-se vectorul de elemente tip struct Country. Initial, se
verifica sa nu se compare acelasi jucator cu el insusi, intrucat nu se poate evita prin cele 4 for-uri
In continuare, se verifica daca scorul este egal. In caz afirmativ, se marcheaza jucatorul cu numele
mai mare din punct de vedere lexicografic cu INT_MIN. In continuare, se parcurge din nou vectorul
de elemente de tip struct Country si se introduc in BST jucatorii care nu au fost marcati cu INT_MIN.
Dupa care se apeleaza printBST, afisandu-se in ordine descrescatoare, dupa scor, jucatorii din BST.

Functia checkBST este o functie ajutatoare pentru rezolvarea cerintei 4 si verifica in mod recursiv
daca cei doi jucatori din fisierul cerinte.in se afla in arbore.

Functia countBST numara in mod recursiv jucatorii al caror scor se afla intre scorurile a doi
jucatori dati.

Functia Task5 rezolva efectiv ccerinta 5, folosindu-se de functiile checkBST si countBST. Se citesc
cei doi jucatori din fisierul cerinte.in si se verifica daca amandoi se afla in BST. In caz afirmativ,
se afiseaza numarul de jucatori al caror scor se afla intre scorurile celor doi jucatori dati, altfel
se afiseaza un mesaj corespunzator.

Functiile freeList si freeBST elibereaza memoria alocata pentru lista dublu inlantuita, circulara,
cu santinela, respectiv pentru arbore.

In fisierul main.c se gaseste functia main, ce are ca parametri numele fisierelor de intrare si iesire
In functia main se declara variabilele necesare apelarii functiilor si, pentru fiecare cerinta, se
apeleaza functiile corespunzatoare.

Fisierul header.h contine toate structurile utilizate si toate antetele functiilor.

Fisierul Makefile are functie de build si clean. Functia de build compileaza fisierul functions.c
si main.c si creeaza fisierul executabil tenis. Functia de clean sterge toate fisierele obiect
rezultate in urma compilarii si fisierul executabil tenis.