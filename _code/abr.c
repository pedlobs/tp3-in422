#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include <time.h>
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

int abr_max(abr *a){
  if (arbre_est_vide(arbre_droit(a))) {
    return arbre_valeur(a);
  }

  return abr_max(arbre_droit(a));
}

int abr_retire_aux(abr *a){
  if (arbre_est_vide(arbre_gauche(a)) && arbre_est_vide(arbre_droit(a))) {
    return 1; // If it's a leaf
  } else if (arbre_est_vide(arbre_gauche(a)) && !arbre_est_vide(arbre_droit(a))) {
    return 2; // If only the left if empty
  } else if (arbre_est_vide(arbre_droit(a)) && !arbre_est_vide(arbre_gauche(a))) {
    return 3; // If only the right is empty
  } else {
    return 4; // If no branch is empty
  }

}

abr*
abr_retire(abr *a, int n){
  if (arbre_est_vide(a)) {
    printf("Erreur: arbre est vide!\n");
    exit(EXIT_FAILURE);
  }

  if (n < arbre_valeur(a)) {
    return arbre_constructeur(arbre_valeur(a), abr_retire(arbre_gauche(a), n), arbre_droit(a));
  } else if (n > arbre_valeur(a)) {
    return arbre_constructeur(arbre_valeur(a), arbre_gauche(a), abr_retire(arbre_droit(a), n));
  } else {
    switch (abr_retire_aux(a)){ 
      case 1: // Leaf
        return arbre_vide();
        break; 
      case 2: // Left empty
        return arbre_droit(a);
        break; 
      case 3: // Right empty
        return arbre_gauche(a);
        break; 
      case 4: // No side empty
        return arbre_constructeur(abr_max(arbre_gauche(a)), abr_retire(arbre_gauche(a), abr_max(arbre_gauche(a))), arbre_droit(a));
        break; 
    }
  }
  return a;
}

int tentative(int N){

  abr *a = arbre_vide();

    for (int j = 0; j<N; j++) {
      int n = rand() % (365) + 1; // Generates a random number between 1 adn 365

      if (abr_cherche(a,n)) {
        return 1;
      } else {
        a = abr_insere(a,n);
      }
    }

  return 0;
}
