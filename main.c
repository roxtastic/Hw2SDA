#include "tarb.h"
int main (int argc, char *argv[])
{
  if (argc < 4 || argc > 5)
    {
      return 1;
    }
  if (strcmp (argv[1], "-c1") == 0) //CERINTA 1
    {
      FILE *infile = fopen (argv[2], "r");
      if (infile == NULL)
        return 1;
      FILE *outfile = fopen (argv[3], "w");
      if (outfile == NULL)
        {
          fclose (infile);
          return 1;
        }
      Tree root = createNode();
      int N;
      fscanf (infile, "%d", &N);
      fgetc (infile);
      for (int i = 0; i < N; i++)
        {
          char sufix[LMAX];
          fgets (sufix, LMAX, infile);
          sufix[strcspn (sufix, "\n")] = '\0';
          strcat (sufix, "$");
          for (int j = 0; j < strlen (sufix); j++)
            {
              insertsuf (&root, &sufix[j]);
            }
        }
      parclatime (root, outfile);
      eliberare (root);
      fclose (infile);
      fclose (outfile);
    }
  if (strcmp (argv[1], "-c2") == 0) //CERINTA 2
    {
      FILE *infile = fopen (argv[3], "r");
      if (infile == NULL)
        return 1;
      FILE *outfile = fopen (argv[4], "w");
      if (outfile == NULL)
        {
          fclose (infile);
          return 1;
        }
      Tree root = createNode ();
      int N;
      fscanf (infile, "%d", &N);
      fgetc (infile);
      for (int i = 0; i < N; i++)
        {
          char sufix[LMAX];
          fgets (sufix, LMAX, infile);
          sufix[strcspn (sufix, "\n")] = '\0';
          strcat (sufix, "$");
          for (int j = 0; j < strlen (sufix); j++)
            {
              insertsuf (&root, &sufix[j]);
            }
        }
      int K = atoi (argv[2]);
      fprintf (outfile, "%d\n", numardolar (root));
      int maxDes = 0;
      int Ksuf = sufixK (root, K);
      nrmaxdes (root, K, &maxDes);
      fprintf (outfile, "%d\n", Ksuf);
      fprintf (outfile, "%d\n", maxDes);
      eliberare (root);
      fclose (infile);
      fclose (outfile);
    }
  if (strcmp (argv[1], "-c3") == 0) //CERINTA 3
    {
      FILE *infile = fopen (argv[2], "r");
      if (infile == NULL)
        return 1;
      FILE *outfile = fopen (argv[3], "w");
      if (outfile == NULL)
        {
          fclose (infile);
          return 1;
        }
      Tree root = createNode ();
      int N, M;
      fscanf (infile, "%d %d", &N, &M);
      fgetc (infile);
      for (int i = 0; i < N; i++)
        {
          char sufix[LMAX];
          fgets (sufix, LMAX, infile);
          sufix[strcspn (sufix, "\n")] = '\0';
          strcat (sufix, "$");
          for (int j = 0; j < strlen (sufix); j++)
            insertsuf (&root, &sufix[j]);
        }
      for (int i = 0; i < M; i++)
        {
          char sufix[LMAX];
          if (fgets (sufix, LMAX, infile) == NULL)
            {
              fclose (infile);
              fclose (outfile);
              return 1;
            }
          sufix[strcspn (sufix, "\n")] = '\0';
          strcat (sufix, "$");
          int found = cautsuf (root, sufix);
          fprintf (outfile, "%d\n", found);
        }
      eliberare (root);
      fclose (infile);
      fclose (outfile);
    }
  return 0;
}