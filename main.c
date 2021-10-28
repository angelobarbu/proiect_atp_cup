//Barbu Angelo 311AB
#include <stdio.h>
#include <stdlib.h>

#include "header.h"

int main(int argc, char *argv[])
{
    struct List *head;
    int nr_countries;
    int i;
    int *cerinte = malloc(5 * sizeof(int));

    FILE *freq = fopen(argv[1], "rt");
    fileOpenCheck(freq);

    FILE *fin = fopen(argv[2], "rt");
    fileOpenCheck(fin);

    FILE *fout = fopen(argv[3], "wt");
    fileOpenCheck(fout);

    fscanf(fin, "%d", &nr_countries);
    Read(&head, nr_countries, fin);
    
    for (i = 0; i < 5; i++)
        fscanf(freq, "%d", &cerinte[i]);

    if (cerinte[4] && cerinte[3] && cerinte[2] && cerinte[1] && cerinte[0])
    {
        struct Country *last_teams;
        struct BST *root = NULL;
        deleteCountry(head, &nr_countries);
        writeCountry(head, fout);
        Task3(head, nr_countries, &last_teams, fout);
        Task4(&root, last_teams, fout);
        Task5(root, freq, fout);
        freeBST(root);
    }
    else if (cerinte[3] && cerinte[2] && cerinte[1] && cerinte[0])
    {
        struct Country *last_teams;
        struct BST *root = NULL;
        deleteCountry(head, &nr_countries);
        writeCountry(head, fout);
        Task3(head, nr_countries, &last_teams, fout);
        Task4(&root, last_teams, fout);
        freeBST(root);
    }
    else if (cerinte[2] && cerinte[1] && cerinte[0])
    {
        struct Country *last_teams;
        deleteCountry(head, &nr_countries);
        writeCountry(head, fout);
        Task3(head, nr_countries, &last_teams, fout);
        free(last_teams);
    }
    else if (cerinte[0] && cerinte[1])
    {
        deleteCountry(head, &nr_countries);
        writeCountry(head, fout);
    }
    else writeCountry(head, fout);

    
    freeList(&head);
    free(cerinte);
    return 0;
}