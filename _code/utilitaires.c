#include <stdlib.h>
#include <stdio.h>

void*
allocation(int taille)
{
  int *r;

  r = malloc(taille);
  if (r == NULL)
  {
    fprintf(stderr, "Plus de mémoire disponible!\n");
    exit(1);
  }
  return r;
}

