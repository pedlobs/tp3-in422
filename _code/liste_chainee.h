typedef struct liste liste;

liste*
liste_vide();

int
liste_est_vide(liste *l);
  
liste*
ajoute(liste *l, int n);
  
int
premier(liste *l);

liste*
reste(liste *l);

