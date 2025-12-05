#include "table_dynamique.h"
#include "utilitaires.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define TAILLE_INITIALE 4

struct table_dynamique 
{
  int taille;
  int *tableau;
};

table_dynamique*
table_dynamique_vide()
{
  table_dynamique *t;

  t = allocation(sizeof(table_dynamique));
  t->taille = TAILLE_INITIALE;
  t->tableau = allocation(t->taille * sizeof(int));

  return t;
}

int
table_dynamique_acces(table_dynamique *t, int index)
{
  if (index < t->taille)
    return t->tableau[index];
  fprintf(stderr, "table_dynamique_acces(): erreur, accès à un élément hors de la table\n");
  exit(1);
}

void
table_dynamique_augmente(table_dynamique *t, int index)
{
  int *z;
  int nouvelle_taille;

  if (index < t->taille)
    fprintf(stderr, "table_dynamique_augmente() appelée sans nécessité.\n");
  nouvelle_taille = t->taille *2;
  if (index >= nouvelle_taille)
    nouvelle_taille = index+1;
  z = allocation(nouvelle_taille * sizeof(int));
  memcpy(z, t->tableau, t->taille * sizeof(int));
  free(t->tableau);
  t->tableau = z;
  t->taille = nouvelle_taille;
}

void
table_dynamique_insere(table_dynamique *t, int index, int valeur)
{
  if (index >= t->taille)
    table_dynamique_augmente(t, index);
  t->tableau[index] = valeur;
  return;
}

void
table_dynamique_libere(table_dynamique *t)
{
  free(t->tableau);
  free(t);
}
