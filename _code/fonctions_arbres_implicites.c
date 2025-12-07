#include "arbre_implicite.h"
#include "arbre.h"

arbre* abi_vers_arbre_aux(abi *a, int index){
  if (index > abi_index_dernier(a)) {
    return arbre_vide();
  }
  
  return arbre_constructeur(
    abi_acces(a, index),
    abi_vers_arbre_aux(a, abi_fils_gauche(index)),
    abi_vers_arbre_aux(a, abi_fils_droit(index))
  );

}

arbre* abi_vers_arbre(abi *a){
  if (abi_est_vide(a)) return arbre_vide();
  return abi_vers_arbre_aux(a, abi_racine());
}
