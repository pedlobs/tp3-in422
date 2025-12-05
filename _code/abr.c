#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "abr.h"
#include "fonctions_arbres.h"

abr*
abr_vide()
{ return arbre_vide(); }

int
est_abr_vide(abr *a)
{ return arbre_est_vide(a); }
  
int abr_cherche(abr *a, int n) {
  if (a == NULL){
    return 0; // Si n'ai pas trovez
  }

  int v = arbre_valeur(a);

  if (n == v){
    return 1; //Si il y a trouvez
  }

  if (n < v){
    return abr_cherche(arbre_gauche(a), n);
  }

  return abr_cherche(arbre_droit(a), n);
}

abr* abr_insere(abr *a, int n){

  if (arbre_est_vide(a)) {
    return(arbre_constructeur(n, arbre_vide(), arbre_vide()));
  }

  int v = arbre_valeur(a);

  if (n < v) {
    return arbre_constructeur(v, abr_insere(arbre_gauche(a),n), arbre_droit(a));
  } else {
    return arbre_constructeur(v, arbre_gauche(a), abr_insere(arbre_droit(a),n));
  }
}







