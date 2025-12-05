#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "tgc.h"
#include "arbre.h"
#include "fonctions_arbres.h"
#include "liste_chainee.h"
#include "fonctions_listes.h"
#include "abr.h"


tgc_t gc;

void test(){
  // Arbre vide  
  arbre *vide = arbre_vide();
  arbre_affiche(vide);
  
  // Arbre example
  arbre *filho_esq = arbre_constructeur(5, arbre_vide(), arbre_vide());
  
  arbre *neto_esq_dir = arbre_constructeur(15, arbre_vide(), arbre_vide());
  arbre *neto_dir_dir = arbre_constructeur(30, arbre_vide(), arbre_vide());
  arbre *filho_dir = arbre_constructeur(20, neto_esq_dir, neto_dir_dir);

  arbre *raiz = arbre_constructeur(10, filho_esq, filho_dir);
  arbre_affiche(raiz);
 
  int taille = arbre_profondeur(raiz);
  printf("Taille: %d\n", taille);

  int n_elements = arbre_nombre_elements(raiz);
  printf("Nombre de elements: %d\n", n_elements);

  printf("Inorder: ");
  liste_affiche(arbre_elements(raiz));


  printf("Traversal: ");
  liste_affiche(preorder_arbre(raiz));

  arbre_source_c(raiz);
  
  printf("\n\nÉtape 2:\n\n");

  // Binary search tree
  arbre *n1  = arbre_constructeur(1,  arbre_vide(), arbre_vide());
  arbre *n4  = arbre_constructeur(4,  arbre_vide(), arbre_vide());
  arbre *n7  = arbre_constructeur(7,  arbre_vide(), arbre_vide());
  arbre *n13 = arbre_constructeur(13, arbre_vide(), arbre_vide());
  arbre *n6  = arbre_constructeur(6, n4, n7);
  arbre *n14 = arbre_constructeur(14, n13, arbre_vide());
  arbre *n3  = arbre_constructeur(3, n1, n6);
  arbre *n10 = arbre_constructeur(10, arbre_vide(), n14);
  arbre *root_abr = arbre_constructeur(8, n3, n10);

  arbre_affiche(root_abr);

  printf("Is there a 6 in the tree? %d\n", abr_cherche(root_abr, 6));

  printf("Is there a 2 in the tree? %d\n", abr_cherche(root_abr, 2));

  printf("Teste abr_insere: \n");
  arbre_affiche(abr_insere(root_abr, 2));
}

int main(int argc, char **argv) {
  tgc_start(&gc, &argc);
  
  test();
  
  tgc_stop(&gc);
  
  return 0;
}
