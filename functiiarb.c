#include "tarb.h"
Tree createNode ()
{
  Tree newNode = (Tree)malloc (sizeof (Node));
  for (int i = 0; i < LUNGIME_ALFABET + 1; i++)
    {
      newNode->children[i] = NULL;
    }
  return newNode;
}
void insertsuf (Tree *root, char *sufix)
{
  Tree curent = *root;
  int i = 0;
  while (sufix[i] != '\0')
    {
      int index;
      if (sufix[i] == '$')
        {
          index = 0;
        }
      else
        {
          index = sufix[i] - 'a' + 1;
        }
      if (curent->children[index] == NULL)
        {
          curent->children[index] = createNode ();
        }
      curent = curent->children[index];
      i++;
    }
}
void parclatime (Tree root, FILE *outfile)
{
  if (root == NULL)
    {
      return;
    }
  Tree coada[LMAX];
  int fata = 0, spate = 0;
  coada[spate++] = root;
  while (fata < spate)
    {
      int nivelnod = spate - fata;
      while (nivelnod > 0)
        {
          Tree curent = coada[fata++];
          for (int i = 0; i < LUNGIME_ALFABET; i++)
            {
              if (curent->children[i] != NULL)
                {
                  if (i == 0)
                    {
                      fprintf (outfile, "$ ");
                    }
                  else
                    {
                      fprintf (outfile, "%c ", i - 1 + 'a');
                    }
                  coada[spate++] = curent->children[i];
                }
            }
          nivelnod--;
        }
      if (fata < spate)
        {
          fprintf (outfile, "\n");
        }
    }
}
int numardolar (Tree root)
{
  int cnt = 0;
  Tree coada[LMAX];
  int fata = 0, spate = 0;
  coada[spate++] = root;
  while (fata < spate)
    {
      Tree curent = coada[fata++];
      for (int i = 0; i < LUNGIME_ALFABET; i++)
        {
          if (curent->children[i] != NULL)
            {
              coada[spate++] = curent->children[i];
            }
        }
      if (curent->children[0] != NULL)
        {
          cnt++;
        }
    }
  return cnt;
}
void nrmaxdes (Tree root, int K, int *maxDes)
{
  if (root == NULL)
    {
      return;
    }
  Tree coada[LMAX];
  int fata = 0, spate = 0;
  coada[spate++] = root;
  while (fata < spate)
    {
      int nivelnod = spate - fata;
      while (nivelnod > 0)
        {
          Tree curent = coada[fata++];
          int descend = 0;
          for (int i = 0; i < LUNGIME_ALFABET; i++)
            {
              if (curent->children[i] != NULL)
                {
                  descend++;
                  coada[spate++] = curent->children[i];
                }
            }
          if (descend > *maxDes)
            {
              *maxDes = descend;
            }
          nivelnod--;
        }
    }
}
int sufixK (Tree root, int K)
{
  if (root == NULL || K < 0)
    {
      return 0;
    }
  int cnt = 0;
  Tree coada[LMAX];
  int fata = 0, spate = 0, niv = 0;
  coada[spate++] = root;
  while (fata < spate)
    {
      int nivelnod = spate - fata;
      while (nivelnod > 0)
        {
          Tree curent = coada[fata++];
          if (niv == K && curent->children[0] != NULL)
            {
              cnt++;
            }
          for (int i = 0; i < LUNGIME_ALFABET; i++)
            {
              if (curent->children[i] != NULL)
                {
                  coada[spate++] = curent->children[i];
                }
            }
          nivelnod--;
        }
      niv++;
      if (niv > K)
        {
          break;
        }
    }
  return cnt;
}
int cautsuf (Tree root, char *sufix)
{
  Tree curent = root;
  int i = 0;
  while (sufix[i] != '\0')
    {
      int index;
      if (sufix[i] == '$')
        {
          index = 0;
        }
      else
        {
          index = sufix[i] - 'a' + 1;
        }
      if (curent->children[index] == NULL)
        {
          return 0;
        }
      curent = curent->children[index];
      i++;
    }
  for (int j = 0; j < LUNGIME_ALFABET; j++)
    {
      if (curent->children[j] != NULL)
        {
          return 0;
        }
    }
  return 1;
}

void eliberare (Tree root)
{
  if (root == NULL)
    {
      return;
    }
  for (int i = 0; i < LUNGIME_ALFABET; i++)
    {
      eliberare (root->children[i]);
    }
  free (root);
}
