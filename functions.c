//Barbu Angelo 311AB
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#include "header.h"



/* Functii pentru verificarea alocarii dinamice
   pt diferite tipuri de date si structuri */
void fileOpenCheck(FILE *file)
{
    if (file == NULL)
    {
        printf("FILE ERROR");
        exit(1);
    }
}

void doubleAllocCheck(double *v)
{
    if (v == NULL)
    {
        printf("DOUBLE ALLOC ERROR");
        exit(1);
    }
}

void listAllocCheck(struct List *node)
{
    if (node == NULL)
    {
        printf("NODE ALLOC ERROR");
        exit(1);
    }
}

void charAllocCheck(char *string)
{
    if (string == NULL)
    {
        printf("CHAR ALLOC ERROR");
        exit(1);
    }
}

void countryAllocCheck(struct Country *country)
{
    if (country == NULL)
    {
        printf("COUNTRY CHECK ERROR");
        exit(1);
    }
}

void playerAllocCheck(struct Player *player)
{
    if (player == NULL)
    {
        printf("PLAYER ALLOC ERROR");
        exit(1);
    }
}

void stackAllocCheck(struct Stack *node)
{
    if (node == NULL)
    {
        printf("STACK ALLOC ERROR");
        exit(1);
    }
}

void queueAllocCheck(struct Queue *q)
{
    if (q == NULL)
    {
        printf("QUEUE ALLOC ERROR");
        exit(1);
    }
}

void qelemAllocCheck(struct QueueElem *node)
{
    if (node == NULL)
    {
        printf("QUEUE ELEM ALLOC ERROR");
        exit(1);
    }
}

void bstAllocCheck(struct BST *node)
{
    if (node == NULL)
    {
        printf("BST ALLOC ERROR");
        exit(1);
    }
}


/* Functia de citire pt stocarea datelor intr-o
   lista dublu inlantuita, circulara, cu santinela */
void Read(struct List **head, int nr_countries, FILE *fin)
{
    /* Se citesc datele separat la inceput pt primul element al listei
       si se aloca memorie pt primul nod si pt santinela */
    *head = (struct List *) malloc(sizeof(struct List));
    listAllocCheck(*head);

    struct List *newNode = (struct List *) malloc(sizeof(struct List));
    listAllocCheck(newNode);

    int i, j;
    char buf[256];

    fscanf(fin, "%d", &newNode->country.nr_players);
    fscanf(fin, "%s", buf);

    newNode->country.name = (char *) malloc((strlen(buf) + 1) * sizeof(char));
    charAllocCheck(newNode->country.name);

    strcpy(newNode->country.name, buf);

    newNode->country.players = (struct Player *) malloc(newNode->country.nr_players * sizeof(struct Player));
    playerAllocCheck(newNode->country.players);


    for (i = 0; i < newNode->country.nr_players; i++)
    {
        fscanf(fin, "%s", buf);

        newNode->country.players[i].last_name = (char *) malloc((strlen(buf) + 1) * sizeof(char));
        charAllocCheck(newNode->country.players[i].last_name);

        strcpy(newNode->country.players[i].last_name, buf);

        fscanf(fin, "%s", buf);

        newNode->country.players[i].first_name = (char *) malloc((strlen(buf) + 1) * sizeof(char));
        charAllocCheck(newNode->country.players[i].first_name);

        strcpy(newNode->country.players[i].first_name, buf);

        fscanf(fin, "%d", &newNode->country.players[i].score);
    }

    // Se creeaza legatura intre primul nod si santinela
    (*head)->next = newNode;
    newNode->prev = *head;

    for (i = 1; i < nr_countries; i++)
    {
        //Se citesc datele pentru restul tarilor
        struct List *aux = malloc(sizeof(struct List));
        listAllocCheck(aux);

        fscanf(fin, "%d", &aux->country.nr_players);
        fscanf(fin, "%s", buf);

        aux->country.name = (char *) malloc((strlen(buf) + 1) * sizeof(char));
        charAllocCheck(aux->country.name);

        strcpy(aux->country.name, buf);

        aux->country.players = (struct Player *) malloc(aux->country.nr_players * sizeof(struct Player));
        playerAllocCheck(aux->country.players);

        for (j = 0; j < aux->country.nr_players; j++)
        {
            fscanf(fin, "%s", buf);

            aux->country.players[j].last_name = (char *) malloc((strlen(buf) + 1) * sizeof(char));
            charAllocCheck(aux->country.players[j].last_name);

            strcpy(aux->country.players[j].last_name, buf);

            fscanf(fin, "%s", buf);

            aux->country.players[j].first_name = (char *) malloc((strlen(buf) + 1) * sizeof(char));
            charAllocCheck(aux->country.players[j].last_name);

            strcpy(aux->country.players[j].first_name, buf);

            fscanf(fin, "%d", &aux->country.players[j].score);
        }

        /* Se creeaza legatura intre nodul anterior,
           nodul curent si santinela */
        newNode->next = aux;
        aux->prev = newNode;
        aux->next = *head;
        (*head)->prev = aux;
        newNode = aux;
    }
}



/* Functia de afisare a numelor tarilor din lista
   rezolvandu-se astfel cerinta 1 */
void writeCountry(struct List *head, FILE *fout)
{
    struct List *node;
    for (node = head->next; node != head; node = node->next)
        fprintf(fout, "%s\n", node->country.name);
}

// Functie de verificare pt afisarea listei complet
void writeList(struct List *head, int nr_countries, FILE *fout)
{
    int i;
    struct List *node;

    fprintf(fout, "%d\n", nr_countries);

    for (node = head->next; node != head; node = node->next)
    {
        fprintf(fout, "%d\n", node->country.nr_players);
        fprintf(fout, "%s\n", node->country.name);
        for (i = 0; i < node->country.nr_players; i++)
            fprintf(fout, "%s %s %d\n", node->country.players[i].last_name,
                    node->country.players[i].first_name, node->country.players[i].score);
    }
}


/* Functii ajutatoare pt lista, stiva, coada
   folosite la rezolvarea cerintelor */


// Sterge un nod din lista de pe o pozitie data
void deleteNode(struct List *head, int pos)
{
    int i = 1;
    struct List *node, *next, *prev;
    for (node = head->next; node != head; node = node->next)
    {
        if (i == pos)
        {
            (node->next)->prev = node->prev;
            (node->prev)->next = node->next;
            free(node);
            return;
        }
        else
            i++;
        
    }
    
}

// Introduce un element in stiva
void pushStack(struct Stack **top, struct Country country)
{
    struct Stack *newNode = (struct Stack *) malloc(sizeof(struct Stack));
    stackAllocCheck(newNode);
    newNode->country = country;
    newNode->next = *top;
    *top = newNode;
}

// Scoate un element de tip struct Country din stiva si il returneaza
struct Country popStack(struct Stack **top)
{
    struct Stack *temp = *top;
    struct Country aux = temp->country;
    
    *top = (*top)->next;
    free(temp);
    return aux;
}

// Creeaza coada
struct Queue *createQueue()
{
    struct Queue *q = (struct Queue *) malloc(sizeof(struct Queue));
    queueAllocCheck(q);
    q->front = q->rear = NULL;
    return q;
}

// Adauga in coada o pereche de tari(tip struct CountryPair)
void enQueue(struct Queue *q, struct CountryPair countries)
{
    struct QueueElem *newNode = (struct QueueElem *) malloc(sizeof(struct QueueElem));
    qelemAllocCheck(newNode);
    newNode->countries = countries;
    newNode->next = NULL;
    if (q->rear == NULL)
        q->rear = newNode;
    else
    {
        (q->rear)->next = newNode;
        (q->rear) = newNode;
    }
    if (q->front == NULL)
        q->front = q->rear;
}

// Scoate din coada o pereche de tari(tip struct CountryPair) si il retureaza
struct CountryPair deQueue(struct Queue *q)
{
    struct QueueElem *aux;
    struct CountryPair countries;
    aux = q->front;
    countries = aux->countries;
    q->front = (q->front)->next;
    free(aux);
    return countries;
}



/* Functii utilizate pentru
   rezolvarea cerintei 2 */


/* Calculeaza cea mai mare putere a lui 2
   mai mica decat numarul de tari */
int Power(int i, int nr_countries)
{
    if (2 * i > nr_countries)
        return i;
    return Power(2 * i, nr_countries);
}

/* Sterge tari cu cel mai mic scor pana cand
   raman cea mai mare putere a lui 2 mai mica
   decat numarul de tari initial */
void deleteCountry(struct List *head, int *nr_countries)
{
    int copy_nr_countries = *nr_countries;
    int deleted_before, min_del_before;
    int pos_min, x, i, j;
    double min, sum;

    double *scores = malloc(*nr_countries * sizeof(double));
    doubleAllocCheck(scores);

    struct List *node;

    // Se foloseste un vector pt memorarea scorurilor tarilor
    for (node = head->next, i = 0; node != head; node = node->next, i++)
    {
        sum = 0;
        for (j = 0; j < node->country.nr_players; j++)
            sum += node->country.players[j].score;
        scores[i] = sum / node->country.nr_players;
    }

    x = Power(1, *nr_countries);
    
    while (copy_nr_countries > x) // cat timp sunt mai multe tari decat puterea lui 2
    {
        min = INT_MAX;
        deleted_before = 0;
        min_del_before = 0;
        /* se foloseste o variabila min_del_before care
           numara tarile scoase din lista inaintea tarii
           ce urmeaza sa fie scoasa pentru a-i gasi
           pozitia actuala in lista */
        for (i = 0; i < *nr_countries; i++)
        {
            if (scores[i] < min)
            {
                min = scores[i];
                pos_min = i + 1;
                min_del_before = deleted_before;
            }
            if (scores[i] == INT_MAX)
                deleted_before++;
        }
        deleteNode(head, (pos_min - min_del_before));
        scores[pos_min - 1] = INT_MAX; // tarile scoase din lista sunt marcate in vector cu valoarea INT_MAX
        copy_nr_countries--;
    }

    *nr_countries = copy_nr_countries;
    free(scores);
}


/* Functie pt rezolvarea efectiva
   a cerintei 3 */

void Task3(struct List *head, int nr_countries, struct Country **last_teams, FILE *fout)
{
    int i, j, k, r = 1, sw = 1;
    int max, country_max;
    int local_score1, local_score2;
    struct Country country_winner;
    struct CountryPair countries;
    struct List *p;
    struct Stack *top, *winner;
    struct Queue *q;

    for (p = head; p != head->prev; p = p->next) // se creeaza stiva la inceput
        pushStack(&top, p->country);
    pushStack(&top, (head->prev)->country);
    q = createQueue(); // se creeaza coada
    * last_teams = (struct Country *) malloc(4 * sizeof(struct Country)); /* se aloca memorie pentru vectorul
                                                                             de tari ce va fi folosit in cerinta 4 */    
    countryAllocCheck(*last_teams);
    
    while (nr_countries != 1)
    {
        // se introduc tarile in coada
        for (i = 0; i < nr_countries; i = i+2)
        {
            countries.country1 = popStack(&top);
            countries.country2 = popStack(&top);
            enQueue(q, countries);
        }

        fprintf(fout, "\n====== ETAPA %d ======\n", r);
        for (i = 0; i < nr_countries; i = i+2)
        {
            local_score1 = 0;
            local_score2 = 0;
            countries = deQueue(q);
            // se verifica daca s-a ajuns la ultimele 4 tari pt vectorul de la cerinta 4
            if (nr_countries == 4 && sw == 1)
            {
                (*last_teams)[0] = countries.country1;
                (*last_teams)[1] = countries.country2;
                sw = 1 - sw;
            }
            else if (nr_countries == 4)
            {
                (*last_teams)[2] = countries.country1;
                (*last_teams)[3] = countries.country2;
            }   

            fprintf(fout, "\n%s %d ----- %s %d\n", countries.country1.name, countries.country1.global_score,
                                               countries.country2.name, countries.country2.global_score);
            for (j = 0; j < countries.country1.nr_players; j++)
                for (k = 0; k < countries.country2.nr_players; k++)
                {
                    fprintf(fout, "%s %s %d vs %s %s %d\n", countries.country1.players[j].last_name,
                                                            countries.country1.players[j].first_name,
                                                            countries.country1.players[j].score,
                                                            countries.country2.players[k].last_name,
                                                            countries.country2.players[k].first_name,
                                                            countries.country2.players[k].score);
                    // se creeaza scorurile locale in urma meciului
                    if (countries.country1.players[j].score > countries.country2.players[k].score)
                    {
                        local_score1 += 3;
                        countries.country1.players[j].score += 5;
                    }
                    else if (countries.country1.players[j].score < countries.country2.players[k].score)
                    {
                        local_score2 += 3;
                        countries.country2.players[k].score += 5;
                    }
                    else
                    {
                        local_score1 += 1;
                        local_score2 += 1;
                        countries.country1.players[j].score += 2;
                        countries.country2.players[k].score += 2;
                    }
                }
            // se actualizeaza scorurile globale
            countries.country1.global_score += local_score1;
            countries.country2.global_score += local_score2;
            // se introduce in stiva WINNER echipa castigatoare in urma meciului
            if (local_score1 > local_score2)
                pushStack(&winner, countries.country1);
            else if(local_score1 < local_score2)
                pushStack(&winner, countries.country2);
            else
            {
                max = INT_MIN;
                country_max = 0;
                for (j = 0; j < countries.country1.nr_players; j++)
                    if (max < countries.country1.players[j].score)
                    {
                        max = countries.country1.players[j].score;
                        country_max = 1;
                    }
                for (j = 0; j < countries.country2.nr_players; j++)
                     if (max < countries.country2.players[j].score)
                    {
                        max = countries.country2.players[j].score;
                        country_max = 2;
                    }
                if (country_max == 1)
                    pushStack(&winner, countries.country1);
                else
                    pushStack(&winner, countries.country2);
            }
        
        }
        fprintf(fout, "\n=== WINNER ===\n");
        nr_countries = nr_countries / 2;
        // se reintroduc in stiva initiala tarile ramase
        for (i = 0; i < nr_countries; i++)
        {
            country_winner = popStack(&winner);
            pushStack(&top, country_winner);
            fprintf(fout, "%s --- %d\n", country_winner.name, country_winner.global_score);
        }
        r++; // variabila ajutatoare pentru a numara runda pentru fprintf
    }
}


/* Functii ajutatoare de creeaza a unui BST
   pentru cerinta 4 */

struct BST *newBSTnode(struct Player player)
{
    struct BST *newNode = (struct BST *) malloc(sizeof(struct BST));
    bstAllocCheck(newNode);
    newNode->player = player;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct BST *insertBST(struct BST **node, struct Player player)
{
    if (*node == NULL)
        return newBSTnode(player);
    if (player.score < (*node)->player.score)
        (*node)->left = insertBST(&(*node)->left, player);
    else if (player.score > (*node)->player.score)
        (*node)->right = insertBST(&(*node)->right, player);
    return *node;
}

void printBST(struct BST *root, FILE *fout)
{
    if (root)
    {
        printBST(root->right, fout);
        fprintf(fout, "%s %s %d\n", root->player.last_name, root->player.first_name, root->player.score);
        printBST(root->left, fout);
    }
}

void Task4(struct BST **root, struct Country *last_teams, FILE *fout)
{
    int i, j, k, l;
    // marcheaza fiecare jucator care nu va fi introdus in BST
    for (i = 0; i < 4; i++)
        for (j = 0; j < last_teams[i].nr_players; j++)
            for (k = i; k < 4; k++)
                for (l = 0; l < last_teams[k].nr_players; l++)
                    // Se verifica daca jucatorul este comparat cu el insusi
                    if (strcmp(last_teams[i].players[j].last_name, last_teams[k].players[l].last_name) ||
                        strcmp(last_teams[i].players[j].first_name, last_teams[k].players[l].first_name))
                        // Se verifica scorul
                        if (last_teams[i].players[j].score == last_teams[k].players[l].score)
                        {
                            // Se compara lexicografic
                            if (strcmp(last_teams[i].players[j].first_name, last_teams[k].players[l].last_name) <= 0)
                                last_teams[k].players[l].score = INT_MIN;
                            else
                                last_teams[i].players[j].score = INT_MIN;
                        }
    // se introduce in root primul jucator
    *root = insertBST(&(*root), last_teams[0].players[0]);
    // se introduc jucatorii in BST
    for (i = 0; i < 4; i++)
        for (j = 0; j < last_teams[i].nr_players; j++)
            if (last_teams[i].players[j].score != INT_MIN && (i != 0 || j !=0))
                // Se verifica daca jucatorul a fost scos si daca este primul jucator deja introdus in root
                insertBST(&(*root), last_teams[i].players[j]);
    free(last_teams);
    fprintf(fout, "\n====== CLASAMENT JUCATORI ======\n");
    printBST(*root, fout);
}


// Functii ajutatoare pt rezolvarea cerintei 4

/* Verifica daca jucatorii dati in cerinte.in se afla in BST
   parcurgand arborele preordine */
int checkBST(struct BST *root, char *player_firstname, char *player_lastname)
{
    if (root)
    {
        if (!strcmp(root->player.first_name, player_firstname) &&
            !strcmp(root->player.first_name, player_firstname))
            return 1;
        return (checkBST(root->left, player_firstname, player_lastname) ||
                checkBST(root->right, player_firstname, player_lastname));
    }
    else
        return 0;
}

/* Numara jucatorii aflati intre scorurile lui player1 si player 2
  parcurgand arborele preordine */
void countBST(struct BST *root, struct Player player1, struct Player player2, int *count)
{
    if (root)
    {
        // ia in considerare cazurile player1.score > player2.score si player1.score < player2.score
        if ((root->player.score < player2.score && root->player.score > player1.score) ||
             (root->player.score > player2.score && root->player.score < player1.score))
            (*count)++;
        countBST(root->left, player1, player2, &(*count));
        countBST(root->right, player1, player2, &(*count));
    }
}

// Rezolva efectiv cerinta 5
void Task5(struct BST *root, FILE *freq, FILE *fout)
{
    int sw1, sw2;
    int count = 0;
    char buf[256];
    struct Player player1, player2;

    // citeste datele celor 2 jucatori din cerinte.in
    fscanf(freq, "%s", buf);
    player1.last_name = malloc(strlen(buf) * sizeof(char));
    charAllocCheck(player1.last_name);
    strcpy(player1.last_name, buf);

    fscanf(freq, "%s", buf);
    player1.first_name = malloc(strlen(buf) * sizeof(char));
    charAllocCheck(player1.first_name);
    strcpy(player1.first_name, buf);

    fscanf(freq, "%d", &player1.score);

    fscanf(freq, "%s", buf);
    player2.last_name = malloc(strlen(buf) * sizeof(char));
    charAllocCheck(player2.last_name);
    strcpy(player2.last_name, buf);

    fscanf(freq, "%s", buf);
    player2.first_name = malloc(strlen(buf) * sizeof(char));
    charAllocCheck(player2.first_name);
    strcpy(player2.first_name, buf);

    fscanf(freq, "%d", &player2.score);

    // verifica daca amandoi jucatorii se afla in BST
    sw1 = checkBST(root, player1.first_name, player1.last_name);
    sw2 = checkBST(root, player2.first_name, player2.last_name);

    if (sw1 && sw2) // in caz ca da, se numara jucatorii cuprinsi intre player1.score si player2.score
    {
        countBST(root, player1, player2, &count);
        fprintf(fout, "\n%d", count);
    } // in caz contrar se afiseaza un mesaj corespunzator
    else
    {
        if (!sw1)
            fprintf(fout, "\n%s %s nu poate fi identificat!", player1.last_name, player1.first_name);
        else
        {
            fprintf(fout, "\n%s %s nu poate fi identificat!", player2.last_name, player2.first_name);
        }
        
    }
}


/* Functii de eliberare a memorie
   pt lista si BST */

void freeBST(struct BST *root)
{
    if (root)
    {
        freeBST(root->left);
        freeBST(root->right);
        free(root);
    }
}

void freeList(struct List **head)
{
    int i;
    struct List *p, *q;
    for (p = (*head)->next; p != *head; p = q)
    {
        q = p->next;
        free(p);
    }
    free(*head);
    *head = NULL;
}