#include "arbre.h"
#include "liste_chainee.h"
#include "fonctions_listes.h"

void
arbre_affiche(arbre* a);

void
arbre_source_c(arbre *a);

int
arbre_profondeur(arbre *a);

int
arbre_nombre_elements(arbre *a);

liste* 
arbre_elements(arbre *a);

liste *preorder_arbre(arbre *a);
