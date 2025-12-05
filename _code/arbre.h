typedef struct arbre arbre;

arbre*
arbre_vide();

int
arbre_est_vide(arbre *a);
  
arbre*
arbre_constructeur(int v, arbre *g, arbre *d);
  
int
arbre_valeur(arbre *a);

arbre*
arbre_gauche(arbre *a);

arbre*
arbre_droit(arbre *a);

