typedef struct arbre_binaire_complet_implicite tas;

tas*
tas_vide();

int
tas_est_vide(tas *t);

int
tas_min(tas *t);

// void
// tas_ajoute(tas *t, int valeur);
// void
// tas_retire_min(tas *t);

void
tas_libere(tas *t);
