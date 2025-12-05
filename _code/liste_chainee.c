#include <stdio.h>
#include "liste_chainee.h"
#include "tgc.h"


extern  tgc_t gc;

struct liste {
  int valeur;
  liste *suivante;
};
  
liste* liste_vide()
{ return NULL; }

int liste_est_vide(liste *l)
{ return (l == NULL); }

liste* alloue()
{
  liste *r = tgc_alloc(&gc, sizeof(liste));
  if (r == NULL) {
    fprintf(stderr, "alloue(): impossible"
      " d'allouer de la memoire!\n");
    exit(1);
  }
  return r;
}

void non_vide(liste *l, char *str)
{
  if (l == NULL) {
    fprintf(stderr, "%s(): la liste "
               "est vide!\n", str);
    exit(1);
  }
}

int premier(liste *l)
{
  non_vide(l, "premier");
  return l->valeur;
}

liste* reste(liste *l)
{
  non_vide(l, "reste");
  return l->suivante;
}

liste* ajoute(liste *l, int n)
{
  liste *r = alloue();
  r->valeur = n;
  r->suivante = l;

  return r;
}
