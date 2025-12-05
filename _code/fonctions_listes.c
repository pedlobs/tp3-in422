#include "fonctions_listes.h"
#include <stdio.h>
#include "liste_chainee.h"


void
liste_affiche(liste *l)
{
  while (!liste_est_vide(l))
  {
    printf(" %d", premier(l));
    l = reste(l);
  }
  printf(".\n");
}

int liste_longueur(liste *l){
  int c = 0;

  while (!liste_est_vide(l)) {
    c++;
    l = reste(l);
  } 
  return c;
}

liste* liste_retourne(liste *l){
  liste *r = liste_vide();

  while (!liste_est_vide(l)) {
    r = ajoute(r, premier(l));
    l = reste(l);
  }

  return r;
}

liste* liste_concatene(liste *l1, liste *l2){
  if (liste_est_vide(l1)) {
    return l2;
  }

  return ajoute(
    liste_concatene(reste(l1),l2),
    premier(l1)
    );
}
