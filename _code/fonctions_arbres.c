#include <stdio.h>
#include "arbre.h"
#include "liste_chainee.h"
#include "fonctions_listes.h"

int arbre_profondeur(arbre *a){
  int p = 0;

  if (arbre_est_vide(a)) {
    return p;
  }

  int profondeur_gauche = arbre_profondeur(arbre_gauche(a));
  int profondeur_droite = arbre_profondeur(arbre_droit(a));


  return (profondeur_gauche > profondeur_droite ? profondeur_gauche : profondeur_droite) + 1;
}

int arbre_nombre_elements(arbre *a){
  int n = 0;

  if (arbre_est_vide(a)) {
    return n;
  }

  int arbre_nombre_elements_gauche = arbre_nombre_elements(arbre_gauche(a));
  int arbre_nombre_elements_droit = arbre_nombre_elements(arbre_droit(a));
  
  return (arbre_nombre_elements_gauche + arbre_nombre_elements_droit) + 1;
}


liste *arbre_elements(arbre *a){
  
  if (arbre_est_vide(a)) {
    return liste_vide();
  }

  liste *l_gauche = arbre_elements(arbre_gauche(a));
  liste *l_valeur = ajoute(liste_vide(), arbre_valeur(a));
  liste *l_droit = arbre_elements(arbre_droit(a));

  return liste_concatene(liste_concatene(l_gauche, l_valeur),l_droit);  
}

liste *preorder_arbre(arbre *a){
  
  if (arbre_est_vide(a)) {
    return liste_vide();
  }

  liste *l_valeur = ajoute(liste_vide(), arbre_valeur(a));
  liste *l_gauche = preorder_arbre(arbre_gauche(a));
  liste *l_droit = preorder_arbre(arbre_droit(a));

  return liste_concatene(liste_concatene(l_valeur, l_gauche), l_droit);
}

void arbre_source_c(arbre *a){
  if (arbre_est_vide(a)){
    printf("arbre_vide()");
    return;
  }

  printf("arbre_constructeur(%d, ", arbre_valeur(a));

  arbre_source_c(arbre_gauche(a));

  printf(", ");

  arbre_source_c(arbre_droit(a));

  printf(")");
}


void
arbre_affiche_aux(arbre *a, int p)
{
  for (int j=0; j<p; j++)
    printf(" ");
  if (arbre_est_vide(a))
  {
    printf("Arbre vide\n");
    return;
  }

  printf("%d\n", arbre_valeur(a));
  if (!(arbre_est_vide(arbre_gauche(a)) && arbre_est_vide(arbre_droit(a))))
  {
    arbre_affiche_aux(arbre_gauche(a), p+2);
    arbre_affiche_aux(arbre_droit(a), p+2);
  }
}

void
arbre_affiche(arbre* a)
{
  arbre_affiche_aux(a, 0);
}

void
arbre_source_c_aux(arbre *a)
{
  if (arbre_est_vide(a))
    printf("arbre_vide()");
  else
  {
    printf("arbre_constructeur(");
    printf("%d, ", arbre_valeur(a));
    arbre_source_c_aux(arbre_gauche(a));
    printf(", ");
    arbre_source_c_aux(arbre_droit(a));
    printf(")");
  }
}

