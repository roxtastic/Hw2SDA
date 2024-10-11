#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LUNGIME_ALFABET 27
#define LMAX 1000

typedef struct Node
{
  struct Node *children[LUNGIME_ALFABET + 1];
} Node, *Tree;
Node *createNode ();
void insertsuf (Tree *root, char *sufix);
void parclatime (Tree root, FILE *outfile);
int numardolar (Tree root);
void nrmaxdes (Tree root, int K, int *maxDes);
int sufixK (Tree root, int K);
int cautsuf (Tree root, char *sufix);
void eliberare (Tree root);