#include "arbre_implicite.h"
#include "table_dynamique.h"
#include "utilitaires.h"

#include <stdlib.h>
#include <stdio.h>

struct arbre_binaire_complet_implicite
{
  int taille;
  table_dynamique *table;
};

abi*
abi_vide()
{ 
  abi *r;

  r = allocation(sizeof(abi));
  
  r->taille = 0;
  r->table = table_dynamique_vide();
  return r;
}

int
abi_est_vide(abi *a)
{ return a->taille == 0; }

int
abi_acces(abi *a, int index)
{ return table_dynamique_acces(a->table, index); }

void
abi_ecrase_racine(abi *a, int valeur)
{
  table_dynamique_insere(a->table, 0, valeur);
}

// ajoute un élément "en fin"
void
abi_ajoute(abi *a, int valeur)
{
  table_dynamique_insere(a->table, a->taille, valeur);
  a->taille++;
}

// retire le "dernier" élément
int
abi_retire(abi *a)
{
  a->taille--;
  return table_dynamique_acces(a->table, a->taille);
}

void
abi_echange_elements(abi *a, int i, int j)
{
  table_dynamique *t;
  int temp;

  t = a->table;
  temp = table_dynamique_acces(t, i);
  table_dynamique_insere(t, i, table_dynamique_acces(t, j));
  table_dynamique_insere(t, j, temp);
}

int
abi_racine()
{ return 0; }

int
abi_est_racine(int index)
{ return index == 0; }

int
abi_index_dernier(abi *a)
{ return a->taille-1; }

int
abi_fils_gauche(int index)
{ return (index * 2) + 1; }

int
abi_fils_droit(int index)
{ return (index * 2) + 2; }

int
abi_parent(int index)
{
  if (index == 0)
    return 0;
  else
    return (index-1) / 2;
}

void
abi_libere(abi *a)
{ 
  table_dynamique_libere(a->table);
  free(a);
  return;
}

