#include <stdio.h>
#include "arbre.h"
#include "tgc.h"

extern  tgc_t gc;

struct arbre {
  int valeur;
  arbre *gauche;
  arbre *droite;
};
  
arbre* arbre_vide()
{ return NULL; }

int arbre_est_vide(arbre *a)
{ return (a == NULL); }

arbre* a_alloue()
{
  arbre *r = tgc_alloc(&gc, sizeof(arbre));
  if (r == NULL) {
    fprintf(stderr, "a_alloue(): impossible"
      " d'allouer de la memoire!\n");
    exit(1);
  }
  return r;
}

void a_non_vide(arbre *a, char *str)
{
  if (a == NULL) {
    fprintf(stderr, "%s(): l'arbre "
               "est vide!\n", str);
    exit(1);
  }
}

int arbre_valeur(arbre *a)
{
  a_non_vide(a, "valeur");
  return a->valeur;
}

arbre* arbre_gauche(arbre *a)
{
  a_non_vide(a, "arbre_gauche");
  return a->gauche;
}

arbre* arbre_droit(arbre *a)
{
  a_non_vide(a, "arbre_droite");
  return a->droite;
}

arbre* arbre_constructeur(int v, arbre *g, arbre *d)
{
  arbre *r = a_alloue();
  r->valeur = v;
  r->gauche = g;
  r->droite = d;
  return r;
}

